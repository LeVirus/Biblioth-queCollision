#include "segment.hpp"
#include "collisionconstants.hpp"
#include <cassert>
#include <cmath>

Segment::Segment(){

}

Segment::Segment( const Vector2D & vect2dA, const Vector2D & vect2dB ){
    bAttribuerPointsSegment( vect2dA, vect2dB );
}

/**
 * @brief Segment::bAttribuerPointsSegment Attribution des 2 points définissant le segment.
 * Si les 2 points en paramètre ont la même ordonnée la fonction retourne false.
 * @param vect2dA Le premier point du segment.
 * @param vect2dB Le deuxième point du segment.
 * @return true si l'opération a été effectuée avec succés, false sinon.
 */
bool Segment::bAttribuerPointsSegment( const Vector2D & vect2dA, const Vector2D & vect2dB ){
    if( vect2dA == vect2dB )return false;
    mvect2dPointA = vect2dA;
    mvect2dPointB = vect2dB;
    bCalculConstanteSegment();
    calcRectBox();
    return true;
}

/**
 * @brief Segment::attributePointAToSegment Fonction modifiant le premier point du segment.
 * @param vect2dA La valeur du nouveau point.
 * @return true si l'opération a été effectuée avec succés, false sinon.
 */
bool Segment::bAttributePointAToSegment( const Vector2D & vect2dA ){
    return bAttribuerPointsSegment( vect2dA, mvect2dPointB );
}

/**
 * @brief Segment::attributePointBToSegment Fonction modifiant le deuxième point du segment.
 * @param vect2dB La valeur du nouveau point.
 * @return true si l'opération a été effectuée avec succés, false sinon.
 */
bool Segment::bAttributePointBToSegment( const Vector2D & vect2dB ){
    return bAttribuerPointsSegment( mvect2dPointA, vect2dB );
}

/**
 * @brief Segment::getVect2dPointA Retourne une référence constante du point A du segment.
 * @return La référence constante de mvect2dPointA.
 */
const Vector2D & Segment::getVect2dPointA()const{
    return mvect2dPointA;
}

/**
 * @brief Segment::getVect2dPointB Retourne une référence constante du point B du segment.
 * @return La référence constante de mvect2dPointB.
 */
const Vector2D & Segment::getVect2dPointB()const{
    return mvect2dPointB;
}


/**
 * @brief Segment::bCalculConstantesFonction Fonction calculant et mémorisant les constantes a et b de la fonction "y = ax + b" du segment.
 * @return false si les points ont la même ordonnée, true si les constantes ont bien été calculées.
 */
bool Segment::bCalculConstanteSegment(){
    if( mvect2dPointA . mfY == mvect2dPointB . mfY )return false;
    //calcul de a :: cohefficient directeur
    mfCstFonctionA = fRetourCohefDirectSegment();
    //calcul de b :: b = ya - ( a * xa )
    mfCstFonctionB = mvect2dPointA . mfY - mvect2dPointA . mfX * mfCstFonctionA;
    return true;
}

/**
 * @brief Segment::bCheckPointInterval Fonction vérifiant si l'abscisse envoyée en paramètre se trouve dans l'intervalle du segment.
 * @param fCoordX L'abscisse à tester.
 * @return retourne true si l'abscisse est bien dans le segment, false sinon.
 */
bool Segment::bCheckAbscisInterval( float fCoordX )const{
    return ! ( ( fabs( fCoordX - mvect2dPointA . mfX ) >= ZERO_FLOAT && fCoordX < mvect2dPointA . mfX &&
                 fCoordX < mvect2dPointB . mfX ) ||
             ( fabs( fCoordX - mvect2dPointA . mfX ) >= ZERO_FLOAT && fCoordX > mvect2dPointA . mfX &&
               fCoordX > mvect2dPointB . mfX ) );
}

/**
 * @brief calculCohefDirectSegment Calcul du cohéficient directeur du segment.
 * @return La valeur du cohéficients directeur.
 */
float Segment::fRetourCohefDirectSegment()const{
    assert( ! ( mvect2dPointA . mfY - mvect2dPointB . mfY  == 0.0f ) && "Cohéficient directeur infini\n" );
    return ( mvect2dPointB . mfY - mvect2dPointA . mfY ) / ( mvect2dPointB . mfX - mvect2dPointA . mfX );
}

/**
 * @brief Segment::fRetourYSegment Calcul du Y du segment avec un paramètre X.
 * @param fX La valeur de X par rapport au segment.
 * @return La valeur de Y trouvé à l'aide du X.
 */
float Segment::fRetourYSegment( float fX ) const{
    //si le X est hors du segment
    assert( ! ( fX > mvect2dPointB . mfX ||  fX < mvect2dPointA . mfX ) && "Valeur X hors norme Segment." );
    //yRecherché = YdebutSegment + ( distance abscisse premier point et point recherché ) * coheffDirecteurSegment
    return mvect2dPointA . mfY + ( fX - mvect2dPointA . mfX ) * mfCstFonctionA;
}

/**
 * @brief getSegmentIntercect Retourne le point d'intersection des 2 segments envoyés en paramètre.
 * Le programme renvoie un Vector2D avec "nan" pour valeur si les 2 segment ne se coupent pas.
 * @param segmentA Le premier segment.
 * @param segmentB Le deuxième segment.
 * @return Le Point d'intersection des 2 segments.
 */
Vector2D getSegmentIntersection( const Segment & segmentA, const Segment & segmentB ){
    Vector2D  vect2dIntersect =
            getIntersectionRightLine( segmentA . getCstA(), segmentA . getCstB(), segmentB . getCstA(), segmentB . getCstB() );

    //si les segments sont // ou que le point d'intersection est hors d'au moins un des 2 segments
    if( vect2dIntersect . mfX == NAN ||
            ! segmentA . bCheckAbscisInterval( vect2dIntersect . mfX ) || ! segmentB . bCheckAbscisInterval( vect2dIntersect . mfX ) ){
        return Vector2D( NAN, NAN );
    }
    return vect2dIntersect;
}

/**
 * @brief getSegmentIntercect Retourne le point d'intersection des 2 segments composé par les vector2d envoyés en paramètre.
 * Le programme renvoie un Vector2D avec "nan" pour valeur si les 2 segment ne se coupent pas.
 * @param vect2dAA Le premier point du premier segment.
 * @param vect2dAB Le deuxième point du premier segment.
 * @param vect2dBA Le premier point du deuxième segment.
 * @param vect2dBB Le deuxième point du deuxième segment.
 * @return Le Point d'intersection des 2 segments.
 */
Vector2D getSegmentIntersection( const Vector2D & vect2dAA, const Vector2D & vect2dAB,
                                 const Vector2D & vect2dBA, const Vector2D & vect2dBB ){
    return getSegmentIntersection( Segment( vect2dAA, vect2dAB ), Segment( vect2dBA, vect2dBB ) );

}

/**
 * @brief getIntersectionRightLine Retourne le point d'intersection de 2 droites.
 * Dans le cas où les 2 droites sont // la fonction renvoie un Vector2D avec "nan" pour valeur.
 * @param fCstA La constante a de la fonction de la droite( y = ax + b ).
 * @param fCstB La constante b de la fonction de la droite( y = ax + b ).
 * @param fCstC La constante c de la fonction de la droite( y = cx + d ).
 * @param fCstD La constante d de la fonction de la droite( y = cx + d ).
 * @return Le point d'intersection des 2 droites.
 */
Vector2D getIntersectionRightLine( float fCstA, float fCstB, float fCstC, float fCstD ){
    float fIntersectX, fIntersectY;
    //si les 2 segments sont //
    if( fabs( fCstA - fCstC ) < ZERO_FLOAT ){
        return Vector2D( NAN, NAN );
    }
    //calcul de x :: ax + b = cx + d ==> x = ( d - b ) / ( a - c )
    fIntersectX = ( fCstD - fCstB ) / ( fCstA - fCstC );

    //calcul de y :: y = ax + b
    fIntersectY = fCstA * fIntersectX + fCstB;
    return Vector2D( fIntersectX, fIntersectY );
}

/**
 * @brief Segment::getVectorAB Retourne le vecteur AB du segment.
 * @return La valeur du vecteur AB.
 */
Vector2D Segment::getVectorAB()const{
    return mvect2dPointB - mvect2dPointA;
}

/**
 * @brief Segment::getCstA Retourne la constante a de la fonction du segment( y = ax + b ).
 * @return La valeur de a.
 */
float Segment::getCstA()const{
    return mfCstFonctionA;
}

/**
 * @brief Segment::getRectBox Retourne la boite englobante du segment.
 * @return mRectBox.
 */
const RectBox & Segment::getRectBox()const{
    return mRectBox;
}

/**
 * @brief Segment::getCstA Retourne la constante b de la fonction du segment( y = ax + b ).
 * @return La valeur de b.
 */
float Segment::getCstB()const{
    return mfCstFonctionB;
}

/**
 * @brief Segment::calcRectBox Calcul de la boite englobante du segment en fonction des 2 points le constituant.
 */
void Segment::calcRectBox(){
    float fAbscPointOrigins, fOrdPointOrigins, fLenghtBox, fHeightBox;

    //Traitement abscisse
    if( mvect2dPointA . mfX < mvect2dPointB . mfX ){
        fAbscPointOrigins = mvect2dPointA . mfX;
        fLenghtBox = mvect2dPointB . mfX - mvect2dPointA . mfX;
    }
    else if( mvect2dPointA . mfX > mvect2dPointB . mfX ){
        fAbscPointOrigins = mvect2dPointB . mfX;
        fLenghtBox = mvect2dPointA . mfX - mvect2dPointB . mfX;
    }
    //si mvect2dPointA . mfX == mvect2dPointB . mfX
    else{
        fAbscPointOrigins = mvect2dPointA . mfX;
        fLenghtBox = 1;
    }

    //Traitement ordonnée
    if( mvect2dPointA . mfY < mvect2dPointB . mfY ){
        fOrdPointOrigins = mvect2dPointA . mfY;
        fHeightBox = mvect2dPointB . mfY - mvect2dPointA . mfY;
    }
    else if( mvect2dPointA . mfY > mvect2dPointB . mfY ){
        fOrdPointOrigins = mvect2dPointB . mfY;
        fHeightBox = mvect2dPointA . mfY - mvect2dPointB . mfY;
    }
    //si mvect2dPointA . mfY == mvect2dPointB . mfY
    else{
        fOrdPointOrigins = mvect2dPointA . mfY;
        fHeightBox = 1;
    }
    mRectBox . modifyOriginsRectBox( Vector2D( fAbscPointOrigins, fOrdPointOrigins ) );
    mRectBox . modifyLenghtRectBox( fLenghtBox );
    mRectBox . modifyHeightRectBox( fHeightBox );
}

/**
 * @brief bIsInCollision Fonction vérifiant si les 2 segments envoyés en paramètre sont en collision.
 * @param segmentA Le premier segment.
 * @param segmentB Le deuxième segment.
 * @return true si il y a collision, false sinon.
 */
bool bIsInCollision( const Segment & segmentA, const Segment & segmentB ){
    Vector2D vect2dA = getSegmentIntersection( segmentA, segmentB );
    if( vect2dA . mfX == NAN )return false;
    return true;
}

/**
 * @brief bIsInCollision Fonction vérifiant si le segment et la boite englobante envoyés en paramètre sont en collision.
 * @param segmentA Le segment.
 * @param rectBoxB La boite englobante.
 * @return true si il y a collision, false sinon.
 */
bool bIsInCollision( const Segment & segmentA, const RectBox & rectBoxB ){
    /*float fHeightBox = rectBoxB . getHeightRectBox(),
            fLenghtBox = rectBoxB . getLenghtRectBox();
    Vector2D vect2dOrigineBox = rectBoxB . getOriginsRectBox(),
            vect2dAngleTopRightBox = Vector2D( vect2dOrigineBox . mfX + fLenghtBox, vect2dOrigineBox . mfY ),
            vect2dAngleDownRightBox = Vector2D( vect2dOrigineBox . mfX + fLenghtBox, vect2dOrigineBox . mfY + fHeightBox ),
            vect2dAngleDownLeftBox = Vector2D( vect2dOrigineBox . mfX, vect2dOrigineBox . mfY + fHeightBox );

    //Vérif de la boite englobante
    if( bIsInCollision( segmentA . getRectBox(), rectBoxB ) )return false;

    //Check de tous les segment composant la boite englobante avec le segment.
    if ( bIsInCollision( segmentA, Segment( vect2dOrigineBox, vect2dAngleTopRightBox ) ) )return true;
    if ( bIsInCollision( segmentA, Segment( vect2dAngleTopRightBox, vect2dAngleDownRightBox ) ) )return true;
    if ( bIsInCollision( segmentA, Segment( vect2dAngleDownRightBox, vect2dAngleDownLeftBox ) ) )return true;
    if ( bIsInCollision( segmentA, Segment( vect2dAngleDownLeftBox, vect2dOrigineBox ) ) )return true;

    return false;*/
    float fRetourYSegment( float fX );
    Vector2D vect2dPointSegment = segmentA . getVect2dPointA();
    bool bExit = false, bBSupA;
    bBSupA = ( segmentA . getVect2dPointB() . mfX >= vect2dPointSegment . mfX );
    do{

    }while( bExit );
}

/**
 * @brief bIsInCollision Fonction vérifiant si le segment et la boite englobante envoyés en paramètre sont en collision.
 * @param rectBoxA La boite englobante.
 * @param segmentB Le segment.
 * @return true si il y a collision, false sinon.
 */
bool bIsInCollision( const RectBox & rectBoxA, const Segment & segmentB ){
    return bIsInCollision( segmentB, rectBoxA );
}

Segment::~Segment(){

}


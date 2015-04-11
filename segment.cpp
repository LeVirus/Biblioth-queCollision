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
 * @return
 */
bool Segment::bAttribuerPointsSegment( const Vector2D & vect2dA, const Vector2D & vect2dB ){
    if( vect2dA == vect2dB )return false;
    mvect2dPointA = vect2dA;
    mvect2dPointB = vect2dB;
    bCalculConstanteSegment();
    return true;
}

/**
 * @brief Segment::getVect2dPointA Retourne une référence constante du point A du segment.
 * @return La référence constante de mvect2dPointA.
 */
const Vector2D & Segment::getVect2dPointA()const{
    return mvect2dPointA;
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
float Segment::fRetourCohefDirectSegment(){
    assert( ! ( mvect2dPointA . mfY - mvect2dPointB . mfY  == 0.0f ) && "Cohéficient directeur infini\n" );
    return ( mvect2dPointB . mfY - mvect2dPointA . mfY ) / ( mvect2dPointB . mfX - mvect2dPointA . mfX );
}

/**
 * @brief Segment::fRetourYSegment Calcul du Y du segment avec un paramètre X.
 * @param fX La valeur de X par rapport au segment.
 * @return La valeur de Y trouvé à l'aide du X.
 */
float Segment::fRetourYSegment( float fX ){
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
 * @brief Segment::getCstA Retourne la constante b de la fonction du segment( y = ax + b ).
 * @return La valeur de b.
 */
float Segment::getCstB()const{
    return mfCstFonctionB;
}

Segment::~Segment(){

}


#include "segment.hpp"
#include "collisionconstants.hpp"
#include <cassert>

Segment::Segment(){

}

/**
 * @brief Segment::bAttribuerPointsSegment Attribution des 2 points définissant le segment.
 * Si les 2 points en paramètre ont la même ordonnée la fonction retourne false.
 * @param vect2dA Le premier point du segment.
 * @param vect2dB Le deuxième point du segment.
 * @return
 */
bool Segment::bAttribuerPointsSegment( const Vector2D & vect2dA, const Vector2D & vect2dB ){
    if( vect2dA . mfY == vect2dB . mfY )return false;
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
 * @brief Segment::getVect2dPointB Retourne une référence constante du point B du segment.
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
 * @brief calculCohefDirectSegment Calcul du cohéficient directeur du segment.
 * @return La valeur du cohéficients directeur.
 */
float Segment::fRetourCohefDirectSegment(){
    assert( ! ( mvect2dPointA . mfY - mvect2dPointB . mfY  < ZERO_FLOAT ) && "Cohéficient directeur infini\n" );
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
 * Le programme est stopée si les 2 segment ne se coupent pas.
 * @param segmentA Le premier segment.
 * @param segmentB Le deuxième segment.
 * @return Le Point d'intersection des 2 segments.
 */
Vector2D getSegmentIntercection( const Segment & segmentA, const Segment & segmentB ){

}

/**
 * @brief bSegmentIntersect Fonction vérifiant si les 2 segments envoyés en paramètre sont sécant.
 * @param segmentA Le premier segment.
 * @param segmentB Le deuxième segment.
 * @return true si il y a intersection, false sinon.
 *
 *
 *
 *
 */
bool bSegmentIntersect( const Segment & segmentA, const Segment & segmentB ){
    Vector2D  vect2dSegmAPtA = segmentA . getVect2dPointA(), vect2dSegmAPtB = segmentA . getVect2dPointB(),
    vect2dSegmBPtA = segmentB . getVect2dPointA(), vect2dSegmBPtB = segmentB . getVect2dPointB();

    //si les 2 segments sont //
    if( segmentA . fRetourCohefDirectSegment() == segmentB . fRetourCohefDirectSegment() )return false;

    vectorDeterminant( ( vect2dSegmAPtB - vect2dSegmAPtA ), ( vect2dSegmBPtB - vect2dSegmAPtA ) )
}

/**
 * @brief Segment::getVectorAB Retourne le vecteur AB du segment.
 * @return La valeur du vecteur AB.
 */
Vector2D Segment::getVectorAB()const{
    return mvect2dPointB - mvect2dPointA
}


Segment::~Segment(){

}


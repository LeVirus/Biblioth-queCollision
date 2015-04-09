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
 * @brief Segment::bCalculConstantesFonction Fonction calculant et mémorisant les constantes a et b de la fonction "y = ax + b" du segment.
 * @return false si les points ont la même ordonnée, true si les constantes ont bien été calculées.
 */
bool Segment::bCalculConstantesSegment(){
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
 * @brief Segment::bCalculConstanteSegment Calcul des constantes a et b d'une fonction y = ax + b issu d'un segment dont les coordonnées
 * de 2 points sont envoyés en arguments.
 * @return true si les calculs ont été fait avec succés, false sinon.
 */
bool Segment::bCalculConstanteSegment(){
    //calcul de a :: cohefficient directeur
    mfCstFonctionA = fRetourCohefDirectSegment();
    //calcul de b :: b = ya - ( a * xa )
    mfCstFonctionB = mvect2dPointA . mfY - mvect2dPointA . mfX * mfCstFonctionA;
    return true;
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



Segment::~Segment(){

}


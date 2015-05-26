#include "rectbox.hpp"

/**
 * @brief RectBox::RectBox Constructeur de RectBox.
 */
RectBox::RectBox(){

}

/**
 * @brief RectBox::modifyLenghtRectBox Fonction de modification de l'attribut mfLenght.
 * @param uiNewLenght La nouvelle valeur de mfLenght.
 */
void RectBox::modifyLenghtRectBox( float fNewLenght ){
    mfLenght = fNewLenght;
}

/**
 * @brief RectBox::modifyLenghtRectBox Fonction de modification de l'attribut mfHeight.
 * @param uiNewLenght La nouvelle valeur de mfHeight.
 */
void RectBox::modifyHeightRectBox( float fNewHeight ){
    mfHeight = fNewHeight;
}

/**
 * @brief RectBox::modifyLenghtRectBox Fonction de modification de l'attribut mPointOrigins.
 * @param uiNewLenght La nouvelle valeur de mPointOrigins.
 */
void RectBox::modifyOriginsRectBox( const Vector2D &vect2dNewPoint ){
    mPointOrigins = vect2dNewPoint;
}

/**
 * @brief RectBox::getLenghtRectBox Renvoie la valeur de la longueur de la box.
 * @return la valeur l'attribut mfLenght.
 */
float RectBox::getLenghtRectBox()const{
    return mfLenght;
}

/**
 * @brief RectBox::getLenghtRectBox Renvoie la valeur de la largeur de la box.
 * @return la valeur l'attribut mfHeight.
 */
float RectBox::getHeightRectBox()const{
    return mfHeight;
}

/**
 * @brief RectBox::getLenghtRectBox Renvoie la valeur de l'origine de la box.
 * @return la valeur de l'attribut mPointOrigins.
 */
const Vector2D &RectBox::getOriginsRectBox()const{
    return mPointOrigins;
}


/**
 * @brief bIsInCollision Fonction de test vérifiant si les 2 RectBox sont en collision.
 * @param rectBoxA La référence constante du premier RectBox.
 * @param rectBoxB La référence constante du premier RectBox.
 * @return true si les 2 figures sont en collision, false sinon
 */
bool bIsInCollision( const RectBox & rectBoxA, const RectBox & rectBoxB ){
    const Vector2D &pointOriginsBoxA = rectBoxA . getOriginsRectBox(),
            &pointOriginsBoxB = rectBoxB . getOriginsRectBox();
    float fAbscTopRightA = pointOriginsBoxA . mfX + rectBoxA . getLenghtRectBox(),
            fAbscTopRightB = pointOriginsBoxB . mfX + rectBoxB . getLenghtRectBox(),
            fOrdDownLeftA = pointOriginsBoxA . mfY + rectBoxA . getHeightRectBox(),
            fOrdDownLeftB = pointOriginsBoxB . mfY + rectBoxB . getHeightRectBox();


    //test latéral
    if( pointOriginsBoxA . mfX >  fAbscTopRightB ||
            fAbscTopRightA < pointOriginsBoxA . mfX ){
        return false;
    }
    //test vertical
    if( pointOriginsBoxA . mfY >  fOrdDownLeftB ||
            fOrdDownLeftA < pointOriginsBoxA . mfY ){
        return false;
    }
    return true;
}

/**
 * @brief bIsInCollision Verification si un point et une boite englobante sont en collision.
 * @param rectBoxA La boite englobante.
 * @param vect2dB Le point.
 * @return true si il y a collision, false sinon.
 */
bool bIsInCollision( const RectBox & rectBoxA, const Vector2D & vect2dB ){
    const Vector2D & OriginsRect = rectBoxA . mPointOrigins;
    if( ! ( vect2dB . mfX <= OriginsRect . mfX + rectBoxA . getLenghtRectBox() && vect2dB . mfX >= OriginsRect . mfX ) )return false;
    else if( ! ( vect2dB . mfY <= OriginsRect . mfY + rectBoxA . getHeightRectBox() && vect2dB . mfY >= OriginsRect . mfY ) )return false;
    return true;
}

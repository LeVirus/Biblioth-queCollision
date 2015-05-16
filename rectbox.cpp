#include "rectbox.hpp"

/**
 * @brief RectBox::RectBox Constructeur de RectBox.
 */
RectBox::RectBox(){

}
;
/**
 * @brief RectBox::modifyLenghtRectBox Fonction de modification de l'attribut muiLenght.
 * @param uiNewLenght La nouvelle valeur de muiLenght.
 */
void RectBox::modifyLenghtRectBox( unsigned int uiNewLenght ){

}

/**
 * @brief RectBox::modifyLenghtRectBox Fonction de modification de l'attribut muiHeight.
 * @param uiNewLenght La nouvelle valeur de muiHeight.
 */
void RectBox::modifyHeightRectBox( unsigned int uiNewHeight ){

}

/**
 * @brief RectBox::modifyLenghtRectBox Fonction de modification de l'attribut mPointOrigins.
 * @param uiNewLenght La nouvelle valeur de mPointOrigins.
 */
void RectBox::modifyOriginsRectBox( const Vector2D &vect2dNewPoint ){

}

/**
 * @brief RectBox::getLenghtRectBox Renvoie la valeur de la longueur de la box.
 * @return la valeur l'attribut muiLenght.
 */
unsigned int RectBox::getLenghtRectBox()const{

}

/**
 * @brief RectBox::getLenghtRectBox Renvoie la valeur de la largeur de la box.
 * @return la valeur l'attribut muiHeight.
 */
unsigned int RectBox::getHeightRectBox()const{

}

/**
 * @brief RectBox::getLenghtRectBox Renvoie la valeur de l'origine de la box.
 * @return la valeur de l'attribut mPointOrigins.
 */
const Vector2D &RectBox::getOriginsRectBox()const{

}


/**
 * @brief bIsInCollision Fonction de test vérifiant si les 2 RectBox sont en collision.
 * @param rectBoxA La référence constante du premier RectBox.
 * @param rectBoxB La référence constante du premier RectBox.
 * @return true si les 2 figures sont en collision, false sinon
 */
bool bIsInCollision( const RectBox & rectBoxA, const RectBox & rectBoxB ){

}

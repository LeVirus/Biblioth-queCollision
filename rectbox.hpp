#ifndef RECTBOX_H
#define RECTBOX_H

#include "vector2d.hpp"

class RectBox{
private:
    Vector2D mPointOrigins;
    unsigned int muiLenght, muiHeight;
public:
    RectBox();
    void modifyLenghtRectBox( unsigned int uiNewLenght );
    void modifyHeightRectBox( unsigned int uiNewHeight );
    void modifyOriginsRectBox( const Vector2D &vect2dNewPoint );
    unsigned int getLenghtRectBox()const;
    unsigned int getHeightRectBox()const;
    const Vector2D &getOriginsRectBox()const;
};

bool bIsInCollision( const RectBox & rectBoxA, const RectBox & rectBoxB );

#endif // RECTBOX_H

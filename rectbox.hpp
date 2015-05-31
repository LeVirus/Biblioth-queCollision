#ifndef RECTBOX_H
#define RECTBOX_H

#include "vector2d.hpp"

class RectBox{
private:
    Vector2D mPointOrigins;
    float mfLenght, mfHeight;
public:
    RectBox();
    void modifyLenghtRectBox( float fNewLenght );
    void modifyHeightRectBox( float fNewHeight );
    void modifyOriginsRectBox( const Vector2D &vect2dNewPoint );
    float getLenghtRectBox()const;
    float getHeightRectBox()const;
    const Vector2D &getOriginsRectBox()const;
};

bool bIsInCollision( const RectBox & rectBoxA, const RectBox & rectBoxB );
bool bIsInCollision( const RectBox & rectBox, const Vector2D & vect2d );
bool bIsInCollision( const Vector2D & vect2d, const RectBox & rectBox );

#endif // RECTBOX_H

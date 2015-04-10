#ifndef SEGMENT_H
#define SEGMENT_H

#include "vector2d.hpp"

/**
 * @brief La classe Segment est composé de 2 Vector2d.
 */
class Segment{
private:
    Vector2D mvect2dPointA, mvect2dPointB;
    float mfCstFonctionA, mfCstFonctionB;
public:
    Segment();
    const Vector2D & getVect2dPointA()const;
    const Vector2D & getVect2dPointB()const;
    float getCstA()const;
    float getCstB()const;
    Segment( const Vector2D & vect2dA, const Vector2D & vect2dB );
    bool bAttribuerPointsSegment( const Vector2D & vect2dA, const Vector2D & vect2dB );
    float fRetourYSegment( float fX );
    float fRetourCohefDirectSegment();
    bool bCalculConstanteSegment();
    Vector2D getVectorAB()const;
    bool bCheckAbscisInterval( float fCoordX )const;
    ~Segment();
};

Vector2D getSegmentIntercection( const Segment & segmentA, const Segment & segmentB );
bool bSegmentIntersect( const Segment & segmentA, const Segment & segmentB );
Vector2D getIntersectionRightLine( float fCstA, float fCstB, float fCstC, float fCstD );

#endif // SEGMENT_H

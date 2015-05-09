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
    Segment( const Vector2D & vect2dA, const Vector2D & vect2dB );
    const Vector2D & getVect2dPointA()const;
    const Vector2D & getVect2dPointB()const;
    float getCstA()const;
    float getCstB()const;
    bool bAttribuerPointsSegment( const Vector2D & vect2dA, const Vector2D & vect2dB );
    bool bAttributePointAToSegment( const Vector2D & vect2dA );
    bool bAttributePointBToSegment( const Vector2D & vect2dB );
    float fRetourYSegment( float fX );
    float fRetourCohefDirectSegment();
    bool bCalculConstanteSegment();
    Vector2D getVectorAB()const;
    bool bCheckAbscisInterval( float fCoordX )const;
    ~Segment();
};

Vector2D getSegmentIntersection( const Segment & segmentA, const Segment & segmentB );
Vector2D getSegmentIntersection( const Vector2D & vect2dAA, const Vector2D & vect2dAB,
                                 const Vector2D & vect2dBA, const Vector2D & vect2dBB );
bool bSegmentIntersect( const Segment & segmentA, const Segment & segmentB );
Vector2D getIntersectionRightLine( float fCstA, float fCstB, float fCstC, float fCstD );

#endif // SEGMENT_H

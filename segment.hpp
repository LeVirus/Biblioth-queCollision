#ifndef SEGMENT_H
#define SEGMENT_H

#include "vector2d.hpp"

/**
 * @brief La classe Segment est composé de 2 Vector2d.
 */
class Segment{
private:
    Vector2D mVect2dPointA, mVect2dPointB;
    float mfCstFonctionA, mfCstFonctionB;
public:
    Segment();
    ~Segment();
};

#endif // SEGMENT_H

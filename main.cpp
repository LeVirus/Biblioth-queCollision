#include <iostream>
#include "segment.hpp"
#include "vector2d.hpp"

using namespace std;

int main(){
    Segment a( Vector2D( 0, 0 ), Vector2D( 5, 0 ) ), b( Vector2D( 0, -5 ), Vector2D( 0, 5 ) );
    Vector2D aa = getSegmentIntersection( a, b );
    aa . displayVector();
    return 0;
}


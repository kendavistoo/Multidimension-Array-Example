#ifndef MULTIARRAY_H
#define MULTIARRAY_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

//---------- class MultiArray ----------

class MultiArray
{
private:
    uint dimX;
    uint dimY;
    uint dimZ;

public:
    MultiArray();
    ~MultiArray();

    void dimensionTheArray(const uint x, const uint y, const uint z);

    uint  index(uint x, uint y, uint z);

    void     setNode(uint x, uint y, uint z, NodeType* node);
    NodeType getNode(uint x, uint y, uint z);

    NodeType* nodeArray;

    uint maxX;
    uint maxY;
    uint maxZ;

};

#endif // MULTIARRAY_H



/*
 *
 *
OldPeculier on StackOverflow

 * A Different Solution

The better solution is to allocate your whole matrix as a single dynamic array, then use (slightly) clever indexing math of
your own to access cells. The indexing math is only very slightly clever; nah, it's not clever at all: it's obvious.

class Matrix
{
    ...
    size_t index( int x, int y ) const { return x + m_width * y; }
};

Given this index() function (which I'm imagining is a member of a class because it needs to know the m_width of
your matrix), you can access cells within your matrix array. The matrix array is allocated like this:

array = new int[ width * height ];

So the equivalent of this in the slow, fat solution:

array[ x ][ y ]

...is this in the quick, small solution:

array[ index( x, y )]
*/


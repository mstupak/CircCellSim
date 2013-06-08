/* ring.h */
#ifndef RING_H_INCLUDED
#define RING_H_INCLUDED

#include "stdbool.h"
#include "cell.h"

typedef struct Nodes
{
    int nodeNum;
    struct Nodes *left;
    struct Nodes *right;
    Cell cell;
} Node;

typedef struct Rings
{
    Node *head;
} Ring;

typedef struct RingIterators
{
    Node *head;
    Node *cur;
} RingIterator;

Node *nodeNew( int i );
void nodePrint( Node *n );
Ring *ringNew();
void ringPrint( Ring *r );
void ringAddNode( Ring *r, Node *n );

RingIterator *ringIteratorNew( Ring *r );
bool ringIteratorNext( RingIterator *ri );
void ringIteratorReset( RingIterator *ri );
Node *ringIteratorGet( RingIterator *ri );

#endif // RING_H_INCLUDED

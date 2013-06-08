#include <stdlib.h>
#include <stdio.h>
#include "ring.h"
#include "cell.h"

// Node API

Node *nodeNew( int i )
{
    Node *n = ( Node* ) malloc( sizeof( Node ) );
    n->nodeNum = i;
    n->right = NULL;
    n->left = NULL;
    cellInit( &(n->cell) );
    return n;
}

void nodePrint( Node *n )
{
    printf( "===== NODE =====\n" );
    printf( "nodeNum: %d\n", n->nodeNum );
    if( n->cell.start.active )
    {
        printf( "START: %s, %s\n", cellColorToString[ n->cell.start.color ].sName,  cellStartDirectionToString[ n->cell.start.direction ].sName);
    }
    if( n->cell.pass.active )
    {
        printf( "PASS: %s\n", cellPassDirectionToString[ n->cell.pass.direction ].sName );
    }
    if( n->cell.bounce.active )
    {
        printf( "BOUNCE: %s\n", cellBounceDirectionToString[ n->cell.bounce.direction ].sName );
    }
    printf( "=====/NODE/=====\n" );
}

// Ring API

Ring *ringNew()
{
    Ring *r = ( Ring* ) malloc( sizeof( Ring ) );
    r->head = nodeNew( 0 );
    r->head->right = r->head;
    r->head->left = r->head;
    return r;
}

void ringPrint( Ring *r )
{
    Node *n = NULL;

    printf( "===== RING =====\n\n" );
    n = r->head->right;

    while( n != r->head )
    {
        nodePrint( n );
        printf( "\n" );
        n = n->right;
    }


    printf( "=====/RING/=====\n" );
}

void ringAddNode( Ring *r, Node *n )
{
    n->left = r->head->left;
    n->right = r->head;
    r->head->left->right = n;
    r->head->left = n;
}

// Ring iterator API

RingIterator *ringIteratorNew( Ring *r )
{
    RingIterator *ri = malloc((sizeof(RingIterator)));
    ri->head = ri->cur = r->head;
    return ri;
}

bool ringIteratorNext( RingIterator *ri )
{
    if( ri->cur->right == ri->head)
    {
        return false;
    }
    else
    {
        ri->cur = ri->cur->right;
    }

    return true;
}

void ringIteratorReset( RingIterator *ri )
{
    ri->cur = ri->head;
}

Node *ringIteratorGet( RingIterator *ri )
{
    return ri->cur;
}

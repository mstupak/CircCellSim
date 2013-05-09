#include <stdlib.h>
#include <stdio.h>
#include "ring.h"

Node *newNode( int i )
{
    Node *n = ( Node* ) malloc( sizeof( Node ) );
    n->nodeNum = i;
    n->right = NULL;
    n->left = NULL;
    return n;
}

void printNode( Node *n )
{
    printf( "===== NODE =====\n" );
    printf( "nodeNum: %d\n", n->nodeNum );
    printf( "=====/NODE/=====\n" );
}

Ring *newRing()
{
    Ring *r = ( Ring* ) malloc( sizeof( Ring ) );
    r->head = newNode( 0 );
    r->head->right = r->head;
    r->head->left = r->head;
    return r;
}

void printRing( Ring *r )
{
    Node *n = NULL;

    printf( "===== RING =====\n\n" );
    n = r->head->right;

    while( n != r->head )
    {
        printNode( n );
        printf( "\n" );
        n = n->right;
    }

        
    printf( "=====/RING/=====\n" );
}

void addNodeToRing( Node *n, Ring *r )
{

    n->left = r->head->left;
    n->right = r->head;
    r->head->left->right = n;
    r->head->left = n;
}

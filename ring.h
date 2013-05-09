/* ring.h */

typedef struct Nodes
{
    int data;
    struct Nodes *next;
    struct Nodes *prev;
} Node;

typedef struct Rings
{
    Node *head;
} Ring;

Node *newNode( int i );
void printNode( Node *n );
Ring *newRing();
void printRing( Ring *r );
void addNodeToRing( Node *n, Ring *r );

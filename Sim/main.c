#include <stdio.h>
#include <stdlib.h>
#include "ring.h"
#include "cell.h"

int main()
{
    Ring *r = ringNew();
    Node *n;

    // Bead 1
    n = nodeNew(1);
    // START
    n->cell.start.active = true;
    n->cell.start.color = RED;
    n->cell.start.direction = START_RIGHT;
    // PASS
    n->cell.pass.active = true;
    n->cell.pass.direction = PASS_TO_RIGHT;
    // BOUNCE
    n->cell.bounce.active = true;
    n->cell.bounce.direction = BOUNCE_TO_RIGHT;
    ringAddNode( r, n );

    // Bead 2
    n = nodeNew(2);
    //PASS
    n->cell.pass.active = true;
    n->cell.pass.direction = PASS_TO_BOTH;
    ringAddNode( r, n );

    // Bead 3
    n = nodeNew(3);
    // BOUNCE
    n->cell.bounce.active = true;
    n->cell.bounce.direction = BOUNCE_TO_LEFT;
    ringAddNode( r, n );


    ringPrint( r );

    /*
    RingIterator *ri = ringIteratorNew( r );
    while( ringIteratorNext( ri ) )
    {
        nodePrint( ringIteratorGet( ri ) );
    }
    */

    return 0;
}

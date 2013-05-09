#include <stdio.h>
#include <stdlib.h>
#include "ring.h"

typedef enum MessageTypes
{
    STATE_PASS,
    STATE_DO,
    PHOTON
}
MessageType;

void main()
{
    Ring *r = newRing();
    addNodeToRing( newNode(1), r );
    addNodeToRing( newNode(2), r );
    addNodeToRing( newNode(3), r );
    printRing( r );
}

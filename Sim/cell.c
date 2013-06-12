#include <stddef.h>
#include "cell.h"
#include "photon.h"


cellColorToStringMap cellColorToString[5] =
{
    {RED, "red" },
    {GREEN, "green"},
    {BLUE, "blue"},
    {WHITE, "white"},
    {COLOR_NONE, "none"}
};

cellStartDirectionToStringMap cellStartDirectionToString[3] =
{
    {START_LEFT, "left" },
    {START_RIGHT, "right" },
    {START_NONE, "none" }
};

cellPassDirectionToStringMap cellPassDirectionToString[4] =
{
    {PASS_TO_LEFT, "pass to left" },
    {PASS_TO_RIGHT, "pass to right" },
    {PASS_TO_BOTH, "pass to both" },
    {PASS_TO_NONE, "pass to none" }
};

cellBounceDirectionToStringMap cellBounceDirectionToString[4] =
{
    {BOUNCE_TO_LEFT, "bounce to left" },
    {BOUNCE_TO_RIGHT, "bounce to right" },
    {BOUNCE_TO_BOTH, "bounce to both" },
    {BOUNCE_TO_NONE, "bounce to none" }
};

void cellInit( Cell *c )
{
    // init "start" fields
    c->start.active = false;
    c->start.direction = PHOTON_NONE;
    c->start.color = COLOR_NONE;

    // init "pass" fields
    c->pass.active = false;
    c->pass.direction = PASS_TO_NONE;

    // init "bounce" fields
    c->bounce.active = false;
    c->bounce.direction = BOUNCE_TO_NONE;
}

CellColorEnum cellCalc( Cell *c, bool isFirstCycle )
{
    if( c==NULL )
    {
        return COLOR_NONE;
    }

    if( isFirstCycle && c->start.active )
    {
        // create photon
        Photon *p = photonNew( 0 );
        p->direction = c->start.direction;
        p->color = c->start.color;
        // return photon color
        return p->color;
    }

    // if we have at least one photon
        // do appropriate munge
        // return new color

    return COLOR_NONE;
}

void cellDo( Cell *c, Cell *left, Cell *right )
{
    if( c==NULL )
    {
        return;
    }

    /*
    if( c->pass.active && matchPhoton( c ) )
    {

    }
    */
}

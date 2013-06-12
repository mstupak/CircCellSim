#include <stdlib.h>
#include <stdio.h>
#include "photon.h"
#include "cell.h"


PhotonDirectionToStringMap photonDirectionToString[3] =
{
    {PHOTON_LEFT, "left" },
    {PHOTON_RIGHT, "right" },
    {PHOTON_NONE, "none" }
};


// Photon API

Photon *photonNew( int i )
{
    Photon *p = ( Photon* ) malloc( sizeof( Photon ) );
    p->next = NULL;
    p->id = i;
    p->direction = PHOTON_NONE;
    p->color = COLOR_NONE;
    return p;
}

void photonDelete( Photon *p )
{
    if( p != NULL )
    {
        free( p );
    }
}

void photonPrint( Photon *p )
{
    printf( "== PHOTON ==\n" );
    printf( "ID: %d\n", p->id );
    printf( "DIRECTION: %s\n", photonDirectionToString[ p->direction ].sName );
    printf( "COLOR: %s\n", cellColorToString[ p->color ].sName );
    printf( "==/PHOTON/==\n" );
}

// PhotonList API

PhotonList *photonListNew( )
{
    PhotonList *pl = ( PhotonList* ) malloc( sizeof( PhotonList ) );
    pl->head = photonNew( -1 );
    pl->head->next = NULL;
    return pl;
}

void photonListPrint( PhotonList *pl )
{
    Photon *p = pl->head->next;

    printf( "===== PHOTONLIST =====\n\n" );

    while( p != NULL )
    {
        photonPrint( p );
        printf( "\n" );
        p = p->next;
    }

    printf( "=====/PHOTONLIST/=====\n" );
}

void photonListAdd( PhotonList *pl, Photon *p )
{
    p->next = pl->head->next;
    pl->head->next = p;
}

Photon *photonListPop( PhotonList *pl )
{
    Photon *p = NULL;

    p = pl->head->next;

    if( p != NULL )
    {
        pl->head->next = p->next;
        p->next = NULL;
    }

    return p;
}

// PhotonList iterator API

// iterator is only valid after first call to Next
PhotonListIterator *photonListIteratorNew( PhotonList *pl )
{
    PhotonListIterator *pli = malloc((sizeof(PhotonListIterator)));
    pli->head = pli->cur = pl->head;
    return pli;
}

bool photonListIteratorNext( PhotonListIterator *pli )
{
    if( pli->cur == NULL || pli->cur->next == NULL)
    {
        return false;
    }
    else
    {
        pli->cur = pli->cur->next;
    }

    return true;
}

Photon *photonListIteratorGet( PhotonListIterator *pli )
{
    return pli->cur;
}

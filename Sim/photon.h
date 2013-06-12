#ifndef PHOTON_H_INCLUDED
#define PHOTON_H_INCLUDED

// TODO (Mike#1#): Make color enum generic?
// get color enum defs
#include "cell.h"

// Photon - structures
typedef enum PhotonDirectionEnums
{
    PHOTON_LEFT,
    PHOTON_RIGHT,
    PHOTON_NONE
} PhotonDirectionEnum;

typedef struct PhotonDirectionToStringMaps
{
    PhotonDirectionEnum eName;
    // has to fit the longest direction string
    char sName[6];
} PhotonDirectionToStringMap;

extern PhotonDirectionToStringMap photonDirectionToString[];

typedef struct Photons
{
    //embedded linked list pointer
    struct Photons *next;

    //data fields
    int id;
    PhotonDirectionEnum direction;
    CellColorEnum color;
} Photon;

typedef struct PhotonLists
{
    Photon *head;
} PhotonList;

typedef struct PhotonListIterators
{
    Photon *head;
    Photon *cur;
} PhotonListIterator;

Photon *photonNew( int i );
void photonDelete( Photon *p );
void photonPrint( Photon *p );

PhotonList *photonListNew();
void photonListPrint( PhotonList *pl );
void photonListAdd( PhotonList *pl, Photon *p );
Photon *photonListPop( PhotonList *pl );

PhotonListIterator *photonListIteratorNew( PhotonList *pl );
bool photonListIteratorNext( PhotonListIterator *pi );
Photon *photonListIteratorGet( PhotonListIterator *pi );

#endif // PHOTON_H_INCLUDED

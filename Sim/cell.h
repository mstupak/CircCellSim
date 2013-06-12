// cell.h
//
// Structures used to define the behavior of the different types of cells

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include "stdbool.h"
#include "photon.h"

// Generic color structures
typedef enum CellColorEnums
{
    RED,
    GREEN,
    BLUE,
    WHITE,
    COLOR_NONE
} CellColorEnum;

typedef struct cellColorToStringMaps
{
    CellColorEnum eName;
    // has to fit the longest color string
    char sName[6];
} cellColorToStringMap;

extern cellColorToStringMap cellColorToString[];

// START - structures
typedef enum CellStartDirectionEnums
{
    START_LEFT,
    START_RIGHT,
    START_NONE
} CellStartDirectionEnum;

typedef struct cellStartDirectionToStringMaps
{
    CellStartDirectionEnum eName;
    // has to fit the longest direction string
    char sName[6];
} cellStartDirectionToStringMap;

extern cellStartDirectionToStringMap cellStartDirectionToString[];

typedef struct CellStarts
{
    bool active;
    PhotonDirectionEnum direction;
    CellColorEnum color;
} CellStart;


// PASS - structures
typedef enum CellPassDirectionEnums
{
    PASS_TO_LEFT,
    PASS_TO_RIGHT,
    PASS_TO_BOTH,
    PASS_TO_NONE
} CellPassDirectionEnum;

typedef struct cellPassDirectionToStringMaps
{
    CellColorEnum eName;
    // has to fit the longest pass direction string
    char sName[14];
} cellPassDirectionToStringMap;

extern cellPassDirectionToStringMap cellPassDirectionToString[];

typedef struct CellPasses
{
    bool active;
    CellPassDirectionEnum direction;
} CellPass;


// BOUNCE - structures
typedef enum CellBounceDirectionEnums
{
    BOUNCE_TO_LEFT,
    BOUNCE_TO_RIGHT,
    BOUNCE_TO_BOTH,
    BOUNCE_TO_NONE
} CellBounceDirectionEnum;

typedef struct cellBounceDirectionToStringMaps
{
    CellColorEnum eName;
    // has to fit the longest pass direction string
    char sName[16];
} cellBounceDirectionToStringMap;

extern cellBounceDirectionToStringMap cellBounceDirectionToString[];

typedef struct CellBounces
{
    bool active;
    CellBounceDirectionEnum direction;
} CellBounce;


// CELL - structures

typedef struct Cells
{
    CellStart start;
    //struct CTTimer;
    CellPass pass;
    CellBounce bounce;
    //enum CTEnumDisplay CTDisplay;
} Cell;

// function protos
void cellInit( Cell *c );

#endif // CELL_H_INCLUDED

#ifndef SET_UTILS_H
#define SET_UTILS_H

// headers/libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

static const int DEFAULT_CAPACITY = 64;

typedef struct SetStruct
   {
    int *setArray;

    int capacity;

    int size;
   } SetType;

// prototypes

void addItem( SetType *setData, int newValue );

bool checkForSetResize(SetType *set);

void clearSet( SetType *set );

void copySet( SetType *dest, const SetType source );

void copyInArray( SetType *dest, const int *source );

void copyInHardArray( SetType *dest, const int source[DEFAULT_CAPACITY], int size );

bool deleteItem( SetType *setData, int itemToDelete );

void displaySet( const SetType setData );

int *doubleCapacity(SetType *set);

void findIntersection( SetType *intersectSet, 
                                 const SetType oneSet, const SetType otherSet );

void findUnion( SetType *unionSet, 
                                 const SetType oneSet, const SetType otherSet );

int getIndexHof(SetType *setData, int index);

void initializeSet( SetType *set );

bool isInSet( const SetType *testSet, int searchVal );

bool isSubSetOf( const SetType oneSet, const SetType psbleSubset );

void swapValues( int *one, int *other );

#endif



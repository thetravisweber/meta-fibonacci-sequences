#ifndef SET_UTILS_H
#define SET_UTILS_H

// headers/libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

static const int DEFAULT_CAPACITY = 50;

typedef struct SetStruct
   {
    int *setArray;

    int capacity;

    int size;
   } SetType;

// prototypes

bool addItem( SetType *setData, int newValue );

void copySet( SetType *dest, const SetType source );

bool deleteItem( SetType *setData, int itemToDelete );

void displaySet( const SetType setData );

void findIntersection( SetType *intersectSet, 
                                 const SetType oneSet, const SetType otherSet );

void findUnion( SetType *unionSet, 
                                 const SetType oneSet, const SetType otherSet );

int getIndex(SetType *setData, int index);

void initializeSet( SetType *set );

bool isInSet( const SetType *testSet, int searchVal );

bool isSubSetOf( const SetType oneSet, const SetType psbleSubset );

void swapValues( int *one, int *other );

#endif



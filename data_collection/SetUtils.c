#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SetUtils.h"

void addItem( SetType *setData, int newValue )
{
   // resize if needed
   checkForSetResize(setData);

   // add to end of set array
   setData->setArray[setData->size] = newValue;

   // increase size
   setData->size++;
}

bool checkForSetResize(SetType *set)
{
   // if does not need resize
   if (set->size < set->capacity)
   {
      return false;
   }
   // otherwise
   
   // make bigger array
   int *oldArray = doubleCapacity(set);

   // copy in data
   copyInArray(set, oldArray);

   return true;
}

void clearSet( SetType *set )
{
   // not whiping data, no need
   set->size = 0;
}

void copySet( SetType *dest, const SetType source )
{
   dest->capacity = source.capacity;
   dest->size = source.size;
   copyInArray(dest, source.setArray);
}

void copyInArray( SetType *dest, const int *source )
{
   // initialize variables
   int index;

   for (index = 0; index < dest->size; index++)
   {
      dest->setArray[index] = source[index];
   }
}

void copyInHardArray( SetType *dest, const int source[DEFAULT_CAPACITY], int size )
{
   // initialize variables
   int index;

   for (index = 0; index < size; index++)
   {
      dest->setArray[index] = source[index];
   }

   dest->size = size;
}

bool deleteItem( SetType *setData, int itemToDelete )
{
   // initialize variables
   int index;
   bool hasBeenFound = false;

   for (index = 0; index < setData->size - 1; index++)
   {
      // if at item
      if (setData->setArray[index] == itemToDelete)
      {
         // set found to be true
         hasBeenFound = true;
      }

      // if at or past item
      if (hasBeenFound)
      {
         // swap with next value
         swapValues(&setData->setArray[index], &setData->setArray[index+1]);
      }
   }

   // if item was found
   if ((hasBeenFound) || (setData->setArray[setData->size - 1] == itemToDelete))
   {
      // decrement size
      setData->size--;

      // return that item was deleted
      return true;
   }

   // return that item was not deleted
   return false;
}


void displaySet( const SetType setData )
{
   // initialize variables
   int index;

   // display each data entry
   for (index = 0; index < setData.size; index++)
   {
      printf("%4d", setData.setArray[index]);

      // print comma if necessary
      if (index < setData.size - 1)
      {
         printf(",");
      }
   }

   // print endline
   printf("\n");
}

int *doubleCapacity(SetType *set)
{
   int *oldArray = set->setArray;

   set->capacity *= 2;

   set->setArray = (int *)malloc( set->capacity * sizeof( int ));

   return oldArray;
}

void findIntersection( SetType *intersectSet, 
                                 const SetType oneSet, const SetType otherSet )
{
   // initialize variables
   int index;
   int indexIntersect = 0;

   // loop through one array
   for (index = 0; index < oneSet.size; index++)
   {
      // if element is in other array
      if (isInSet(&otherSet, oneSet.setArray[index]))
      {
         // add to intersection
         intersectSet->setArray[indexIntersect] = oneSet.setArray[index];

         // increment intersection index
         indexIntersect++;
      }
   }

   // set final size of intersection
   intersectSet->size = indexIntersect;
}


void findUnion( SetType *unionSet, 
                                 const SetType oneSet, const SetType otherSet )
{
   // initialize variables
   int indexOther;
   int indexUnion = oneSet.size;

   // copy first set into union set
   copySet(unionSet, oneSet);

   // add each element from other to union if not already included
   for (indexOther = 0; indexOther < otherSet.size; indexOther++)
   {
      // if not already in the union
      if (!isInSet(unionSet, otherSet.setArray[indexOther]))
      {
         // add to union array
         unionSet->setArray[indexUnion] = otherSet.setArray[indexOther];

         // increment union index
         indexUnion++;
      }
   }

   // set final size of union
   unionSet->size = indexUnion;
}

int getIndexHof(SetType *setData, int index)
{
   return setData->setArray[index - 1];
}

void initializeSet( SetType *set )
{
    set->capacity = DEFAULT_CAPACITY;
    set->size = 0;

    // initialize array to DEFAULT_CAPACITY initial capacity
    set->setArray = (int *)malloc( DEFAULT_CAPACITY * sizeof( int ));
}


bool isInSet( const SetType *testSet, int searchVal )
{
   // initialize variable
   int index;

   // loop through provided set
   for (index = 0; index < testSet->size; index++)
   {
      // if matches
      if (testSet->setArray[index] == searchVal)
      {
         // return that it is in set
         return true;
      }
   }

   // otherwise,
   // return that it is NOT in the set
   return false;
}


bool isSubSetOf( const SetType oneSet, const SetType psbleSubset )
{
   // initialize variables
   int index;

   // loop through possible subset
   for (index = 0; index < psbleSubset.size; index++)
   {
      // if not in main set
      if (!isInSet(&oneSet, psbleSubset.setArray[index]))
      {
         // return that it is not a subset
         return false;
      }
   }

   // return that it is a subset
   return true;
}

void swapValues( int *one, int *other )
{
   int temp = *one;

   *one = *other;

   *other = temp;
}
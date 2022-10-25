#include <stdbool.h>
#include "SetUtils.h"
#include "HofUtils.h"

bool addToSequence(SetType *sequence)
{
    int n = sequence->size;
    int firstIndex = getIndex(sequence, n-1);
    int secondIndex = getIndex(sequence, n-2);

    if ((firstIndex < 1) || (secondIndex < 1))
    {
        return false;
    }

    // subtracting one to convert to c indexing
    int nextTerm = getIndex(sequence, firstIndex - 1) + 
                getIndex(sequence, secondIndex - 1);

    addItem(sequence, nextTerm);

    return true;
}

void initializeDefault(SetType *sequence)
{
    addItem(sequence, 1);
    addItem(sequence, 1);
}
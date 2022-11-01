#include <stdbool.h>
#include "SetUtils.h"
#include "HofUtils.h"

bool addToSequence(SetType *sequence)
{
    int n = sequence->size + 1;
    
    int firstIndex = n - getIndexHof(sequence, n-1);
    int secondIndex = n - getIndexHof(sequence, n-2);

    if ((firstIndex < 1) || (firstIndex >= n))
    {
        return false;
    }

    // subtracting one to convert to c indexing
    int nextTerm = getIndexHof(sequence, firstIndex) + 
                getIndexHof(sequence, secondIndex);

    addItem(sequence, nextTerm);

    return true;
}

void initializeDefault(SetType *sequence)
{
    addItem(sequence, 1);
    addItem(sequence, 1);
}
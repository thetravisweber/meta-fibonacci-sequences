#include "SetUtils.h"
#include "HofUtils.h"

int main() 
{
    SetType baseSequence;

    initializeSet(&baseSequence);

    initializeDefault(&baseSequence);

    addToSequence(&baseSequence);

    displaySet(baseSequence);

    return 1;
}
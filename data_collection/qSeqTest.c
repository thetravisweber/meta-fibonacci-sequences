#include "SetUtils.h"
#include "HofUtils.h"

int main() 
{
    SetType baseSequence;

    initializeSet(&baseSequence);

    initializeDefault(&baseSequence);

    for (int i = 0; i < 120; i++)
    {
        addToSequence(&baseSequence);
    }

    displaySet(baseSequence);

    return 1;
}
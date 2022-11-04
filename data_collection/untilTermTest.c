#include "SetUtils.h"
#include "HofUtils.h"

int main() 
{
    SetType baseSequence;
    int test1[] = {1,1,1,1,1,1,1,1,1,3};

    initializeSet(&baseSequence);
    
    copyInHardArray(&baseSequence, test1, 10);
    printf("ran until: %d\n", runToTermination(&baseSequence, 1000));
    displaySet(baseSequence);

    return 0;
}
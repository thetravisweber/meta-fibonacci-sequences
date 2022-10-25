#ifndef HOF_UTILS_H
#define HOF_UTILS_H

struct SequenceData {
    int diedAt;

    int start[];
};

// prototypes

bool addToSequence(SetType *sequence);

void initializeDefault(SetType *sequence);

#endif
#ifndef CONTEXT_H
#define CONTEXT_H

#include "logic.hpp"
#include "memory.hpp"

typedef struct {
    Node* dataHead;
    char* region;
    int column;
    int error;
    YearValuePair* yearValuePairs;
    int pairCount;
    int minYear;
    int maxYear;
} Context;

void initializeContext(Context* context);
void loadDataFromFile(Context* context, const char* filename);
void freeContext(Context* context);
void calculateMetrics(Context* context, float* min, float* max, float* median);
void setYearValuePairs(Context* context, YearValuePair* pairs, int count);
void freeYearValuePairs(Context* context);

#endif // CONTEXT_H

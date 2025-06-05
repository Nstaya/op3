#include "context.hpp"
#include <stdlib.h>

void initializeContext(Context* context) {
    context->dataHead = NULL;
    context->region = NULL;
    context->column = -1;
    context->error = 0;
}

void loadDataFromFile(Context* context, const char* filename) {
    if (context->dataHead) {
        freeData(context->dataHead);
        context->dataHead = NULL;
    }
    context->dataHead = loadData(filename, context->region);
    context->error = (context->dataHead == NULL) ? 1 : 0;
}

void freeContext(Context* context) {
    if (context->dataHead) {
        freeNodeList(context->dataHead);
    }
    if (context->region) {
        free(context->region);
    }
    if (context->yearValuePairs) {
        free(context->yearValuePairs);
    }
    context->dataHead = NULL;
    context->region = NULL;
    context->yearValuePairs = NULL;
}

void calculateMetrics(Context* context, float* min, float* max, float* median) {
    if (context->dataHead == NULL || (context->column < MIN_COLUMN) || context->column > MAX_COLUMN) {
        context->error = 2;
        return;
    }
    *min = calculateMin(context->dataHead, context->column);
    *max = calculateMax(context->dataHead, context->column);
    *median = calculateMedian(context->dataHead, context->column);
    context->error = 0;
}

void setYearValuePairs(Context* context, YearValuePair* pairs, int count) {
    if (context->yearValuePairs) {
        freeYearValuePairs(context);
    }
    context->yearValuePairs = pairs;
    context->pairCount = count;
}

void freeYearValuePairs(Context* context) {
    if (context->yearValuePairs) {
        free(context->yearValuePairs);
        context->yearValuePairs = NULL;
        context->pairCount = 0;
    }
}

#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#include "context.h"

typedef enum {
    INIT,
    LOAD_DATA,
    CALCULATE,
    CALCULATE_AND_DRAW,
    FREE
} OperationType;

void doOperation(Context* context, OperationType operation,
                 const char* filename = nullptr,
                 float* min = nullptr,
                 float* max = nullptr,
                 float* median = nullptr);

#endif // ENTRY_POINT_H

#include "entry_point.hpp"
#include "context.hpp"
#include <cstring>
#include <stdlib.h>

void doOperation(Context* context, OperationType operation, const char* filename, float* min, float* max, float* median) {
    switch (operation) {
    case INIT:
        initializeContext(context);
        break;
    case LOAD_DATA:
        if (filename)
            loadDataFromFile(context, filename);
        break;
    case CALCULATE:
        if (min && max && median)
            calculateMetrics(context, min, max, median);
        break;
    case CALCULATE_AND_DRAW:
        if (min && max && median) {
            calculateMetrics(context, min, max, median);
        }
        break;
    case FREE:
        freeContext(context);
        break;
    default:
        context->error = 3;
        break;
    }
}

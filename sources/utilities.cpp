#include "utilities.hpp"

void swap(float* a, float* b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(float* values, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                swap(&values[j], &values[j + 1]);
            }
        }
    }
}

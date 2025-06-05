#ifndef MEMORY_H
#define MEMORY_H

#include "logic.h"
#include <stdlib.h>
#include "utilities.h"

float* allocateArr(int count);
Node* allocateNode();
void freeArr(float* arr);
void freeNode(Node* node);
void freeNodeList(Node* head);

#endif // MEMORY_H

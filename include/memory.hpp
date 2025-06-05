#ifndef MEMORY_H
#define MEMORY_H

#include "logic.hpp"
#include <stdlib.h>
#include "utilities.hpp"

float* allocateArr(int count);
Node* allocateNode();
void freeArr(float* arr);
void freeNode(Node* node);
void freeNodeList(Node* head);

#endif // MEMORY_H

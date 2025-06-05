#include "memory.h"

float* allocateArr(int count) {
    if (count <= 0) return NULL;
    return (float*)malloc(count * sizeof(float));
}

Node* allocateNode() {
    return (Node*)malloc(sizeof(Node));
}

void freeArr(float* arr) {
    if (arr != nullptr) {
        free(arr);
        arr = nullptr;
    }
}

void freeNode(Node* node) {
    if (node != nullptr) {
        free(node->data.region);
        free(node);
        node = nullptr;
    }
}

void freeNodeList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        freeNode(current);
        current = next;
    }
}

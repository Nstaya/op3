#ifndef ITERATOR_H
#define ITERATOR_H

#include "logic.hpp"

typedef struct {
    Node* current;
} Iterator;

void initIterator(Iterator* iterator, Node* head);
int hasNext(Iterator* iterator);
DemographicData next(Iterator* iterator);

#endif // ITERATOR_H

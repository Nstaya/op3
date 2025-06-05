#include "iterator.hpp"
#include <stdlib.h>

void initIterator(Iterator* iterator, Node* head) {
    iterator->current = head;
}

int hasNext(Iterator* iterator) {
    return iterator->current != NULL;
}

DemographicData next(Iterator* iterator) {
    if (iterator->current == NULL) {
        DemographicData emptyData = {};
        return emptyData;
    }

    DemographicData data = iterator->current->data;
    iterator->current = iterator->current->next;
    return data;
}

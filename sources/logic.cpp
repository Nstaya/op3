#include "logic.hpp"
#include "memory.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

Node* loadData(const char* filename, const char* filterRegion) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;
    char line[MAX_LENGTH];

    if (!fgets(line, sizeof(line), file)) {
        fclose(file);
        return NULL;
    }

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '\r') continue;

        DemographicData data = {};
        char* token = strtok(line, ",");
        int col = 0;
        bool parseError = false;

        while (token != NULL && col < NUM_COLUMN) {
            char* cleanedToken = token;
            while (*cleanedToken == ' ' || *cleanedToken == '"') cleanedToken++;

            switch (col) {
            case 0:
                data.year = atoi(cleanedToken);
                break;
            case 1:
                if (cleanedToken) {
                    data.region = strdup(cleanedToken);
                    if (!data.region) {
                        parseError = true;
                        break;
                    }
                } else {
                    parseError = true;
                }
                break;
            case 2:
                data.natural_population_growth = atof(cleanedToken);
                break;
            case 3:
                data.birth_rate = atof(cleanedToken);
                break;
            case 4:
                data.death_rate = atof(cleanedToken);
                break;
            case 5:
                data.general_demographic_weight = atof(cleanedToken);
                break;
            case 6:
                data.urbanization = atof(cleanedToken);
                break;
            }
            token = strtok(NULL, ",");
            col++;
        }

        if (col == NUM_COLUMN && !parseError && (!filterRegion || strcmp(data.region, filterRegion) == 0)) {
            Node* newNode = allocateNode();
            if (newNode) {
                newNode->data = data;
                newNode->next = NULL;

                if (!head) {
                    head = tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            else {
                free(data.region);
            }
        }
        else {
            free(data.region);
        }
    }
    fclose(file);
    return head;
}

void freeData(Node* head) {
    freeNodeList(head);
}

float calculateMin(Node* head, int column) {
    if (head == NULL) return 0;

    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }

    float* values = sortedValues(head, column, count);
    if (!values) return 0;

    float minValue = values[0];
    freeArr(values);
    return minValue;
}

float calculateMax(Node* head, int column) {
    if (head == NULL) return 0;

    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }

    float* values = sortedValues(head, column, count);
    if (!values) return 0;

    float maxValue = values[count - 1];
    freeArr(values);
    return maxValue;
}

float selectValue(Node* current, int column, float value) {
    switch (column) {
    case COL_NATURAL_GROWTH: value = current->data.natural_population_growth; break;
    case COL_BIRTH_RATE: value = current->data.birth_rate; break;
    case COL_DEATH_RATE: value = current->data.death_rate; break;
    case COL_DEMOGRAPHIC_WEIGHT: value = current->data.general_demographic_weight; break;
    case COL_URBANIZATION: value = current->data.urbanization; break;
    default: return 0;
    }
    return value;
}

float* sortedValues(Node* head, int column, int count) {
    if (column < MIN_COLUMN || (column > MAX_COLUMN) || count <= 0) {
        return NULL;
    }

    float* values = allocateArr(count);
    if (!values) {
        return NULL;
    }

    Node* current = head;
    for (int i = 0; i < count && current != NULL; i++) {
        switch (column) {
        case COL_NATURAL_GROWTH: values[i] = current->data.natural_population_growth; break;
        case COL_BIRTH_RATE: values[i] = current->data.birth_rate; break;
        case COL_DEATH_RATE: values[i] = current->data.death_rate; break;
        case COL_DEMOGRAPHIC_WEIGHT: values[i] = current->data.general_demographic_weight; break;
        case COL_URBANIZATION: values[i] = current->data.urbanization; break;
        default:
            freeArr(values);
            return NULL;
        }
        current = current->next;
    }

    sort(values, count);
    return values;
}

float calculateMedian(Node* head, int column) {
    if (head == NULL) return 0;
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    float* values = sortedValues(head, column, count);

    float median;
    if (count % 2 == 0) {
        median = (values[count / 2 - 1] + values[count / 2]) / 2.0f;
    } else {
        median = values[count / 2];
    }

    freeArr(values);
    return median;
}

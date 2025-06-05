#ifndef LOGIC_H
#define LOGIC_H

#define MAX_LENGTH 1024
#define NUM_COLUMN 7
#define MAX_COLUMN 6
#define MIN_COLUMN 2

enum DataColumns {
    COL_YEAR = 1,
    COL_NATURAL_GROWTH,
    COL_BIRTH_RATE,
    COL_DEATH_RATE,
    COL_DEMOGRAPHIC_WEIGHT,
    COL_URBANIZATION
};

typedef struct {
    int year;
    char* region;
    float natural_population_growth;
    float birth_rate;
    float death_rate;
    float general_demographic_weight;
    float urbanization;
} DemographicData;

typedef struct Node {
    DemographicData data;
    struct Node* next;
} Node;

typedef struct {
    int year;
    float value;
} YearValuePair;

Node* loadData(const char* filename, const char* region);
void freeData(Node* head);
float selectValue(Node* current, int column, float value);
float* sortedValues(Node* head, int column, int count);
float calculateMin(Node* head, int column);
float calculateMax(Node* head, int column);
float calculateMedian(Node* head, int column);
void sort(float* values, int count);

YearValuePair* getYearValuePairs(Node* head, int column, int* count);
void freeYearValuePairs(YearValuePair* pairs);

#endif // LOGIC_H

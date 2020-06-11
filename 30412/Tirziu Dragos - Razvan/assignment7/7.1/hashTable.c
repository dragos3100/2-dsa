#include "hashTable.h"
#include <math.h>
#include <stdio.h>

void initHashTable(int N) {
    size = (int) (N * INITIAL_HT_SIZE_FACTOR);
    hashTable = (listT *) malloc(size * sizeof(listT));
    for (int i = 0; i < size; i++) {
        initList(&hashTable[i]);
    }
}

void insertElement(char *element) {
    int location;
    switch (hash){
        case 0: location=hashFunction0(element);
            break;
        case 1: location=hashFunction1(element);
            break;
        case 2: location=hashFunction2(element);
            break;
        case 3: location=hashFunction3(element);
            break;
        default:location=hashFunction3(element);
            break;
    }
    addToList(&hashTable[location], element);
}

int hashFunction0(char *content) {
    return content[30] % 3;
}

int hashFunction1(char *content) {
    int length = strlen(content);
    int k, sum;
    for (sum = 0, k = 0; k < length; k++) {
        sum += content[k];
    }
    return sum % size;
}

int hashFunction2(char *content) {
    int result = 0;
    for (int k = 0; k < strlen(content); k++) {
        result = content[k] * k + result;
    }
    result = abs(result);
    return result % size;
}

int hashFunction3(char *content) {
    int result = 0;
    int i=71;
    for (int k = 0; k < strlen(content); k++) {
        result = content[k] * i + result;
        i=i*71;
    }
    result = abs(result);
    return result % size;
}

void computeDistributionsPerBucket() {
    for (int i = 0; i < size; i++) {
        nodeT *currentNode = hashTable[i].head;
        hashTable[i].size = 0;
        while (currentNode != NULL) {
            hashTable[i].size++;
            currentNode = currentNode->next;
        }
    }
    double expectedValue = 0;
    for (int i = 0; i < size; i++) {
        expectedValue = expectedValue + hashTable[i].size;
    }
    expectedValue = expectedValue / size;

    double standardDeviationSquared = 0;
    for (int i = 0; i < size; i++) {
        standardDeviationSquared = standardDeviationSquared + pow(hashTable[i].size - expectedValue, 2);
    }
    standardDeviationSquared = standardDeviationSquared / size;
    printf("%lf", sqrt(standardDeviationSquared));

}
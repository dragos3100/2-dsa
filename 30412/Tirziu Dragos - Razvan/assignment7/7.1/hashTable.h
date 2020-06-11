#include "list.h"
#include <stdlib.h>
#include <string.h>

double INITIAL_HT_SIZE_FACTOR;

listT *hashTable;
int size;
int hash;


int hashFunction0(char *content);

int hashFunction1(char *content);

int hashFunction2(char *content);

int hashFunction3(char *content);

void initHashTable(int N);

void insertElement(char *element);

void computeDistributionsPerBucket();
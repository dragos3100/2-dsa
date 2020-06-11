#include <stdlib.h>
double INITIAL_HT_SIZE_FACTOR;
double MAX_FILL_FACTOR;

char ** hashTable;
int size;
int noOfResizes;
int hash;


int hashFunction(char * content,int i);
int hashFunction1(char * content, int i);
int hashFunction2(char *content, int i);
int hashFunction3(char *content, int i);
void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);
#include "hashTable.h"
#include "io.h"
int location;
void initHashTable(int N){
    size = (int) (N * INITIAL_HT_SIZE_FACTOR);
    hashTable = (char **) malloc(size * sizeof(char*));
    for(int i=0;i<size;i++)
        hashTable[i]=NULL;
}

float getFillFactor(int noOfInsertedElem){
    return (float) noOfInsertedElem/(float)size;
}

void resizeHashTable(){
    noOfResizes++;
    int oldSize=size;
    size=size*2;
    hashTable=(char**)realloc(hashTable,size*sizeof(char*));
    for(int i=oldSize;i<size;i++)
        hashTable[i]=NULL;
    for(int i=0;i<oldSize;i++){
        if(hashTable[i]!=NULL) {
            insertElement(hashTable[i]);
            if (location != i)
                hashTable[i] = NULL;
        }
    }
}

int insertElement(char * element){
    int i=0;
    location=hashFunction(element,0);
    while(hashTable[location]!=NULL){
        i++;
        location=hashFunction(element,i);
    }
    hashTable[location]=(char*)malloc(MAX_STRING_LENGTH*sizeof(char));
    strcpy(hashTable[location],element);
    return i;
}

int hashFunction(char *element,int i){
    switch (hash){
        case 1:return hashFunction1(element,i);
        case 2:return hashFunction2(element,i);
        default: return hashFunction3(element,i);
    }
}

int hashFunction1(char * content, int i){
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++){
        sum += content[k];
    }
    return (sum+i) % size;
}

int hashFunction2(char *content,int i) {
    int result = 0;
    for (int k = 0; k < strlen(content); k++) {
        result = content[k] * k + result;
    }
    result = abs(result);
    return (result+i) % size;
}

int hashFunction3(char *content,int i) {
    int result = 0;
    int j=71;
    for (int k = 0; k < strlen(content); k++) {
        result = content[k] * j + result;
        j=j*71;
    }
    result = abs(result);
    return (result+i) % size;
}
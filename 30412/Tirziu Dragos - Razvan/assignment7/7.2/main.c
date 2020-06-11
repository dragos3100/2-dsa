#include "io.h"
#include "files.h"
#include "hashTable.h"
int main()
{
    int N = _10000;
    char ** content = readFromFile(N);

    double initialAndMaxSF[][2]={{0.25,0.60},{0.20,0.75},{0.20,0.80},{0.25,0.83},{0.25,0.85},{0.5,0.9}};
    for(int i=1;i<=3;i++) {
        hash = i;
        printf("H%d:\n",i);
        for (int j = 0; j < 6; j++) {
            INITIAL_HT_SIZE_FACTOR=initialAndMaxSF[j][0];
            MAX_FILL_FACTOR=initialAndMaxSF[j][1];
            initHashTable(N);
            int noOfInsertedElem = 0;
            int noOfCollision = 0;
            noOfResizes = 0;
            for (int k = 0; k < N; k++) {
                if (getFillFactor(noOfInsertedElem) > MAX_FILL_FACTOR) {
                    resizeHashTable();
                }
                noOfCollision = noOfCollision + insertElement(content[k]);
                noOfInsertedElem++;
            }
            printf("%.2f %.2f: %d %d\n",INITIAL_HT_SIZE_FACTOR,MAX_FILL_FACTOR, noOfCollision, noOfResizes);
        }
    }
    return 0;
}
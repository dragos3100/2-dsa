#include "io.h"
#include "files.h"
#include "hashTable.h"

int main() {
    int N = _10000;
    char **content = readFromFile(N);
    double initialSizeFactor[6] = {0.1, 0.2, 0.35, 0.5, 0.75, 0.85};
    for (int i = 0; i < 4; i++) {
        hash = i;
        printf("H%d:\n", i);
        for (int j = 0; j < 6; j++) {
            INITIAL_HT_SIZE_FACTOR = initialSizeFactor[j];
            initHashTable(N);
            for (int i = 0; i < N; i++) {
                insertElement(content[i]);
            }
            printf("%.2f: ", INITIAL_HT_SIZE_FACTOR);
            computeDistributionsPerBucket();
            printf("\n");
        }
    }
    return 0;
}

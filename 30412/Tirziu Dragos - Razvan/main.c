#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"


int main()
{
   FILE *f = fopen("input.dat", "r");
    if (f == NULL) {
        perror("File could not be open");
        exit(EXIT_FAILURE);
    }

    initializeSll();
    while (feof(f) == 0) {
        char command[MAX_COMMAND];
        int x;
        fscanf(f, "%s", command);
        if (strcmp(command, "AF") == 0) {
            fscanf(f, "%d", &x);
            AF(x);
        } else if (strcmp(command, "AL") == 0) {
            fscanf(f, "%d", &x);
            AL(x);

        } else if (strcmp(command, "DF") == 0)
            DF();

        else if (strcmp(command, "DL") == 0)
            DL();

        else if (strcmp(command, "DOOM_THE_LIST") == 0)
            DOOM_THE_LIST();

        else if (strcmp(command, "DE") == 0) {
            fscanf(f, "%d", &x);
            DE(x);

        } else if (strcmp(command, "PRINT_ALL") == 0)
            PRINT_ALL();

        else if (strcmp(command, "PRINT_F") == 0) {
            fscanf(f, "%d", &x);
            PRINT_F(x);

        } else if (strcmp(command, "PRINT_L") == 0) {
            fscanf(f, "%d", &x);
            PRINT_L(x);

        }
    }
}

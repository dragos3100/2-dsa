#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"


int main() {
    input = fopen("input.dat", "r");

    char *commandLine = (char *) malloc(MAX_COMMAND* sizeof(char));
    int x;

    void initializeSll();

    if (input == NULL) {
        exit(1);
    } else {
        while (!feof(input)) {
            fscanf(input, "%s", commandLine);
            getc(input);
            if (strcmp(commandLine, "AF") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                AF(x);
            }
            if (strcmp(commandLine, "AL") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                AL(x);
            }
            if (strcmp(commandLine, "DF") == 0) {
                DF();
            }
            if (strcmp(commandLine, "DL") == 0) {
                DL();
            }
            if (strcmp(commandLine, "DOOM_THE_LIST") == 0) {
                DOOM_THE_LIST();
            }
            if (strcmp(commandLine, "DE") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                DE(x);
            }
            if (strcmp(commandLine, "PRINT_F") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                PRINT_F(x);
            }
            if (strcmp(commandLine, "PRINT_L") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                PRINT_L(x);
            }
            if (strcmp(commandLine, "PRINT_ALL") == 0) {
                PRINT_ALL();
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}


#include <stdio.h>
#include <string.h>
#include "normal.h"

const char* INPUT = "normal";

int main(int argc, char **argv) {

    if (argc >= 2) {
        char* firstInput = argv[1];
        if (strcmp(firstInput, INPUT) == 0) {
            normal(argc, argv);
        }
    } else {
        printf("Not enough paramters.\n");
    }

    return 0;
}
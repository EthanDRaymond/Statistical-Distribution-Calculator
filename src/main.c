#include <stdio.h>
#include <string.h>
#include "normal.h"
#include "poisson.h"

int main(int argc, char **argv) {

    const char* NORMAL = "normal";
    const char* POISSON = "poisson";

    if (argc >= 2) {
        char* firstInput = argv[1];
        if (strcmp(firstInput, NORMAL) == 0) {
            normal(argc, argv);
        } else if (strcmp(firstInput, POISSON) == 0) {
            poisson(argc, argv);
        }
    } else {
        printf("Not enough paramters.\n");
    }

    return 0;
}
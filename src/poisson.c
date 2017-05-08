//
// Created by Ethan on 5/8/2017.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int factorial(unsigned int x) {
    if (x == 0) {
        return 1;
    } else {
        return x * factorial(x-1);
    }
}

double pmf(unsigned int k, double lambda) {
    return pow(lambda, k) * pow(M_E, -lambda) / factorial(k);
}

double getLeftTailPoisson(unsigned int k, double lambda) {

    double p = 0.0;
    for (int i = 0; i <= k; i++) {
        p += pmf(i, lambda);
    }

    return p;

}

double getRightTailPoisson(unsigned int k, double lambda) {
    return 1.0 - getLeftTailPoisson(k, lambda);
}

int poisson(int argc, char** argv) {

    const char* LEFT_TAIL = "left";
    const char* RIGHT_TAIL = "right";
    const char* FLAG_K = "-k";
    const char* FLAG_LAMBDA = "--lambda";

    if (argc >= 3) {
        char* secondParameter = argv[2];
        if (strcmp(secondParameter, LEFT_TAIL) == 0) {
            if (argc >= 4) {
                int k = 4;
                double lambda = 4;
                for (int i = 3; i < argc; i++) {
                    char *param = argv[i];
                    if (strcmp(FLAG_K, param) == 0) {
                        i++;
                        k = atoi(argv[i]);
                    } else if (strcmp(FLAG_LAMBDA, param) == 0) {
                        i++;
                        lambda = atof(argv[i]);
                    }
                }
                printf("%f", getLeftTailPoisson(k, lambda));
            } else {
                printf("No value given to to calculate left tail");
            }
        } else if (strcmp(secondParameter, RIGHT_TAIL) == 0) {
            if (argc >= 4) {
                int k = 4;
                double lambda = 4;
                for (int i = 3; i < argc; i++) {
                    char *param = argv[i];
                    if (strcmp(FLAG_K, param) == 0) {
                        i++;
                        k = atoi(argv[i]);
                    } else if (strcmp(FLAG_LAMBDA, param) == 0) {
                        i++;
                        lambda = atof(argv[i]);
                    }
                }
                printf("%f", getRightTailPoisson(k, lambda));
            } else {
                printf("No value given to to calculate left tail");
            }
        }
    }
    return 1;
}

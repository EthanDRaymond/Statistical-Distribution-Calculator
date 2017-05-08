#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int factorial(unsigned int x) {
    if (x == 0) {
        return 1;
    } else {
        return x * factorial(x-1);
    }
}

double pmfBinomial(unsigned int k, unsigned int n, double p) {
    return factorial(n) * pow(p, k) * pow(1-p, n-k) / (factorial(k) * factorial(n-k));
}

double getLeftTailBinomial(unsigned int x, unsigned int n, double p) {

    double prob = 0.0;
    for (int k = 0; k <= x; k++) {
        prob += pmfBinomial(k, n, p);
    }

    return prob;

}

double getRightTailBinomial(unsigned int x, unsigned int n, double p) {
    return 1.0 - getLeftTailBinomial(x, n, p);
}

int binomial(int argc, char** argv) {

    const char* LEFT_TAIL = "left";
    const char* RIGHT_TAIL = "right";
    const char* FLAG_N = "-n";
    const char* FLAG_X = "-x";
    const char* FLAG_P = "-p";

    if (argc >= 3) {
        char* secondParameter = argv[2];
        if (strcmp(secondParameter, LEFT_TAIL) == 0) {
            if (argc >= 4) {
                int n = 0;
                int x = 0;
                double p = 0;
                for (int i = 3; i < argc; i++) {
                    char *param = argv[i];
                    if (strcmp(FLAG_N, param) == 0) {
                        i++;
                        n = atoi(argv[i]);
                    } else if (strcmp(FLAG_X, param) == 0) {
                        i++;
                        x = atoi(argv[i]);
                    } else if (strcmp(FLAG_P, param) == 0) {
                        i++;
                        p = atof(argv[i]);
                    }
                }
                printf("%f\n", getLeftTailBinomial(x, n, p));
            } else {
                printf("No value given to to calculate left tail");
            }
        } else if (strcmp(secondParameter, RIGHT_TAIL) == 0) {
            if (argc >= 4) {
                int n = 0;
                int x = 0;
                double p = 0;
                for (int i = 3; i < argc; i++) {
                    char *param = argv[i];
                    if (strcmp(FLAG_N, param) == 0) {
                        i++;
                        n = atoi(argv[i]);
                    } else if (strcmp(FLAG_X, param) == 0) {
                        i++;
                        x = atoi(argv[i]);
                    } else if (strcmp(FLAG_P, param) == 0) {
                        i++;
                        p = atof(argv[i]);
                    }
                }
                printf("%f\n", getRightTailBinomial(x, n, p));
            } else {
                printf("No value given to to calculate left tail");
            }
        }
    }
    return 1;
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
                printf("%f\n", getLeftTailPoisson(k, lambda));
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
                printf("%f\n", getRightTailPoisson(k, lambda));
            } else {
                printf("No value given to to calculate left tail");
            }
        }
    }
    return 1;
}

double pdfNormal(double x, double mean, double stdev) {
    return 1.0 / ( (sqrt(2 * stdev * stdev * 3.1415926)) * exp((x-mean)*(x-mean) / (2*stdev*stdev)) );
}

double getLeftTailNormal(double x, double mean, double stdev) {

    const double MIN = -10.0;
    const double MAX = 10.0;
    const int N = 25;

    if (x <= MIN) {
        return 0.0;
    } else if (x >= MAX) {
        return 1.0;
    }

    double p = 0.0;
    int i = 0;
    for (i = 0; i < N; i++) {
        double a = i*((x-MIN) / (double) N) + MIN;
        double b = (i+1)*((x-MIN) / (double) N) + MIN;
        p += pdfNormal(a, mean, stdev) + pdfNormal(b, mean, stdev);
    }
    p *= (x - MIN) / (2 * (double) N);
    p += pdfNormal(MIN, mean, stdev);
    return p;

}

double getRightTailNormal(double x, double mean, double stdev) {
    return 1.0 - getLeftTailNormal(x, mean, stdev);
}

int normal(int argc, char** argv) {

    const char* LEFT_TAIL = "left";
    const char* RIGHT_TAIL = "right";
    const char* FLAG_MEAN = "--mean";
    const char* FLAG_STANDARD_DEVIATION = "--standard-dev";

    if (argc >= 3) {
        char* secondParameter = argv[2];
        if (strcmp(secondParameter, LEFT_TAIL) == 0) {
            if (argc >= 4) {
                double mean = 0.0;
                double stdev = 1.0;
                double x = 0.0;
                for (int i = 3; i < argc; i++) {
                    char *param = argv[i];
                    if (strcmp(FLAG_MEAN, param) == 0) {
                        i++;
                        mean = atoi(argv[i]);
                    } else if (strcmp(FLAG_STANDARD_DEVIATION, param) == 0) {
                        i++;
                        stdev = atoi(argv[i]);
                    } else {
                        x = atoi(param);
                    }
                }
                printf("%f\n", getLeftTailNormal(x, mean, stdev));
            } else {
                printf("No value given to to calculate left tail");
            }
        } else if (strcmp(secondParameter, RIGHT_TAIL) == 0) {
            if (argc >= 4) {
                double mean = 0.0;
                double stdev = 1.0;
                double x = 0.0;
                for (int i = 3; i < argc; i++) {
                    char *param = argv[i];
                    if (strcmp(FLAG_MEAN, param) == 0) {
                        i++;
                        mean = atoi(argv[i]);
                    } else if (strcmp(FLAG_STANDARD_DEVIATION, param) == 0) {
                        i++;
                        stdev = atoi(argv[i]);
                    } else {
                        x = atoi(param);
                    }
                }
                printf("%f\n", getRightTailNormal(x, mean, stdev));
            } else {
                printf("No value given to to calculate left tail");
            }
        }
    }
    return 1;
}

int main(int argc, char **argv) {

    const char* NORMAL = "normal";
    const char* POISSON = "poisson";
    const char* BINOMIAL = "binomial";

    if (argc >= 2) {
        char* firstInput = argv[1];
        if (strcmp(firstInput, NORMAL) == 0) {
            normal(argc, argv);
        } else if (strcmp(firstInput, POISSON) == 0) {
            poisson(argc, argv);
        } else if (strcmp(firstInput, BINOMIAL) == 0) {
            binomial(argc, argv);
        }
    } else {
        printf("Not enough paramters.\n");
    }

    return 0;
}
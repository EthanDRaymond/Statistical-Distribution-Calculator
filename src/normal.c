#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const char* LEFT_TAIL = "lefttail";
const char* RIGHT_TAIL = "righttail";
const char* FLAG_MEAN = "--mean";
const char* FLAG_STANDARD_DEVIATION = "--standard-dev";

const double MIN = -10.0;
const double MAX = 10.0;
const int N = 25;

double pdf(double x, double mean, double stdev) {
	return 1.0 / ( (sqrt(2 * stdev * stdev * 3.1415926)) * exp((x-mean)*(x-mean) / (2*stdev*stdev)) );
}

double getLeftTail(double x, double mean, double stdev) {

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
		p += pdf(a, mean, stdev) + pdf(b, mean, stdev);
	}
	p *= (x - MIN) / (2 * (double) N);
	p += pdf(MIN, mean, stdev);
	return p;

}

double getRightTail(double x, double mean, double stdev) {

	if (x <= MIN) {
		return 0.0;
	} else if (x >= MAX) {
		return 1.0;
	}

	double p = 0.0;
	int i = 0;
	for (i = 0; i < N; i++) {
		double a = i*((MAX-x) / (double) N) + x;
		double b = (i+1)*((MAX-x) / (double) N) + x;
		p += pdf(a, mean, stdev) + pdf(b, mean, stdev);
	}
	p *= (MAX - x) / (2 * (double) N);
	p += pdf(MAX, mean, stdev);
	return p;

}

int normal(int argc, char** argv) {
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
				printf("%f", getLeftTail(x, mean, stdev));
			} else {
				printf("No value given to to calculate left tail");
			}
		}
	}
	return 1;
}

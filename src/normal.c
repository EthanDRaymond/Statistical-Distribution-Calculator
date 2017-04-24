#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

/**
 * Inputs:
 * [1] sample type:
 * 		0 = left tail
 * 		1 = right tail
 * [2] mean
 * [3] standard deviation
 * [4] z value
 */
int main(int argc, char **argv) {

	if (argc != 5){
		return 1;
	}

	int type = atoi(argv[1]);
	double mean = atof(argv[2]);
	double stdev = atof(argv[3]);
	double z = atof(argv[4]);

	if (type == 0) {
		printf("%f", getLeftTail(z, mean, stdev));
	} else if (type == 1) {
		printf("%f", getRightTail(z, mean, stdev));
	} else {
		return 1;
	}

	return 0;
}

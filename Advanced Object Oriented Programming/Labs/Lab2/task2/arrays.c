#include "arrays.h"

double mean(int length, int* arr) {
	int runningTotal = 0;

	int i;
	for (i = 0; i < length; i++) {
		runningTotal += arr[i];
	}

	return runningTotal / (double) length;
}
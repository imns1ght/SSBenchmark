#include "../include/fill-array.h"
	
void fillArray(long * array, long size) {
	// Fill range [0, size] in order (0, 1, 2, ..., size - 1)
	for (long i = 0; i < size; i++) {
		array[i] = i;
	}
}
	
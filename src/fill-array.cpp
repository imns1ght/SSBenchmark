/*!
 * \file fill-array.cpp
 * \brief Fill the array for the search
 */

#include "../include/fill-array.h"
	
void fillArray(long * array, long beginRange, int size) {
	// Fill range [0, size) in order (0, 1, 2, ..., size - 1)
	for (auto i = 0; i < size; i++, beginRange++) {
		array[i] = beginRange;
	}
}
	
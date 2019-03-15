/*!
 * \file jump-search.cpp
 * \brief Implements the jump search
 */

#include "../include/jump-search.h"

const long * jsearch(const long *first, const long *last, long value) {
	long step = sqrt(std::distance(first, last));	// Blocks size
	auto blockSize = first + step;			// Block size

	// Run while not in the correct block
	while ((*first <= value) && (blockSize < last)) {
		first = blockSize;		// Jump block
		blockSize += step;	

		if (blockSize > (last - 1)) { 
			blockSize = last; 	// If the block exceeds the range
		}
	}

	// Linear search
   	for (auto i = (first - step); i < blockSize; i++) {
		if (*i == value) {
         		return i; // If the value is found
		}
   	}

	return NULL; // If the value is not found 
}
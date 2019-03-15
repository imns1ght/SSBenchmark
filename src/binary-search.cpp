/*!
 * \file binary-search.cpp
 * \brief Implements the binary search
 */
#include "../include/binary-search.h"

const long * bsearch(const long *first, const long *last, long value) {
	auto distance = std::distance(first, last); // Current length

	while (distance > 0) {
		auto offset = distance / 2;	    // Determine the mid element of the range
		auto m = first + offset; 	    // Mid element pointer

		if (value == *m) {
			return m;
		} else if (value > *m) {            // If the element is on the right
			distance -= offset + 1;     // Determines the range for one element after mid 
			first = ++m; 		    // Determines the first element for one element after mid
		} else if (value < *m) { 	    // If the element is on the left
			distance = offset; 
		}
	}

	return NULL; // If the value is not found 
}

const long * bsearch_recursive(const long *first, const long *last, long value) {
	auto distance = std::distance(first, last); // Current length

	while (distance > 0) {
		auto offset = distance / 2;	    // Determine the mid element of the range
		auto m = first + offset; 	    // Mid element pointer

		if (value == *m) {
			return m;

		} else if (value > *m) {            // If the element is on the right
			first = ++m; 		    // Determines the first element for one element after mid
			return bsearch_recursive(first, last, value);

		} else if (value < *m) { 	    // If the element is on the left
			last = last - offset;
			return bsearch_recursive(first, last, value);
		}
	}

	return NULL; // If the value is not found 
}
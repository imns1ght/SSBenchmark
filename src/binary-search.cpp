#include "../include/binary-search.h"

const int * bsearch(const int *first, const int *last, int value)
{
	auto distance = std::distance(first, last); /* Current length */

	while (distance > 0) {
		auto offset = distance / 2; // Determine the mid element of the range
		auto m = first + offset; // Mid element pointer

		if (value == *m) {
			return m;
		} else if (value > *m) { // If the element is on the right
			distance -= offset + 1; // Determines the range for one element after mid 
			first = ++m; // Determines the first element for one element after mid
		} else if (value < *m) { // If the element is on the left
			distance = offset; 
		}
	}

	return last; // If the value is not found 
}
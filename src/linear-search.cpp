#include "../include/linear-search.h"

const long * lsearch(const long *first, const long *last, long value) {
	while (first != last) {
		if (*first == value) {
			return first;
		}
		first++;
	}

	return NULL;
}
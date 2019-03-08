#include "../include/linear-search.h"

const int * lsearch(const int *first, const int *last, int value)
{
	while (first != last) {
		if (*first == value) {
			return first;
		}
		first++;
	}

	return last;
}
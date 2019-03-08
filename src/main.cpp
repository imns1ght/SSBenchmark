/*!
 * \file main.cpp
 * \brief TODO
 * \author Jefferson Bruno, Ranieri Santos
 * \date march, 16th
 */

#include "../include/linear-search.h"
#include "../include/binary-search.h"

#define LIMIT 50000000

int main(void) {
	long * array = new long [LIMIT];
	
	for (long i = 0; i < LIMIT; i++) {
		array[i] = i;
	}

	auto result = const_cast <long *>(bsearch(array, (array + LIMIT - 1), LIMIT));

	cout << *result;

	delete[] array;

	return 0;
}
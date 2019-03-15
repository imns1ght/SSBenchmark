#ifndef FILL_ARRAY_H
#define FILL_ARRAY_H

#include <iostream>  	// cout, endl
#include <iterator>  	// ostream_iterator, begin(), end(), distance()

/// Fill the array for the search
/*!
 * \param array Pointer to the array.
 * \param size Size of the array.
 */
void fillArray(long * array, long beginRange, int size);

#endif
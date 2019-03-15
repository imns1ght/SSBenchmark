#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#include <iostream>  	// cout, endl
#include <iterator>  	// ostream_iterator, begin(), end(), distance()
#include <cmath>	// sqrt()

/// Implements jump search on an array of long integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer to the last element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or NULL, in case the value is not in the range.
 */
const long *jsearch(const long *first, const long *last, long value);

#endif
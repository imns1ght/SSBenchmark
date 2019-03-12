#ifndef FIBONACCI_SEARCH_H
#define FIBONACCI_SEARCH_H

#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator, begin(), end(), distance()
#include <algorithm> // min()

/// Implements an Fibonacci search on an range [first; last) of long integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or NULL, in case the value is not in the range.
 */
const long *fibsearch(const long *first, const long *last, long value);

#endif
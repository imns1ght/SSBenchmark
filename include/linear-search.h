#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator, begin(), end(), distance()

using namespace std;

/// Implements an iterative linear search on an range [first; last) of long integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or NULL, in case the value is not in the range.
 */
const long * lsearch(const long *first, const long *last, long value);

#endif
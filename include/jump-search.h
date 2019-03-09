#ifdef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator, begin(), end(), distance()

/// Implements jump search on an array of long integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer to the last element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */

const long int *jumpsearch(const int *first, const int *last, int value);

#endif
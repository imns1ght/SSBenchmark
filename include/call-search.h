#ifndef CALL_SEARCH_H
#define CALL_SEARCH_H

#include "../include/linear-search.h"
#include "../include/binary-search.h"
#include "../include/ternary-search.h"
#include "../include/jump-search.h"
#include "../include/fibonacci-search.h"

/// Call the search function from choice of the user
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer to the last element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
long * callSearch(long *first, long *last, long searchValue, int choice);

#endif
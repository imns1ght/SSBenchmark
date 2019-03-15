/*!
 * \file call-search.cpp
 * \brief Call the search function from choice of the user
 */

#include "../include/call-search.h"

long * callSearch(long *first, long *last, long searchValue, int choice) {
	long *result;

	switch (choice)
	{
		case 1:
			result = const_cast <long *>(lsearch(first, last, searchValue));
			break;

		case 2:
			result = const_cast <long *>(bsearch(first, last, searchValue));
			break;

		case 3:
			result = const_cast <long *>(bsearch_recursive(first, last, searchValue));
			break;

		case 4:
			result = const_cast <long *>(tsearch(first, last, searchValue));
			break;

		case 5:
			result = const_cast <long *>(tsearch_recursive(first, last, searchValue));
			break;

		case 6:
			result = const_cast <long *>(jsearch(first, last, searchValue));
			break;

		case 7:
			result = const_cast <long *>(fibsearch(first, last, searchValue));
			break;
	}

	return result;
}
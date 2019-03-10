#ifndef PRINT_DURATION_H
#define PRINT_DURATION_H

#include <iostream>  	// cout, endl
#include <chrono>     

/// Print the search duration time
/*!
 * \param diff Difference between the start and end point.
 */
void printDuration(std::chrono::nanoseconds diff);

#endif
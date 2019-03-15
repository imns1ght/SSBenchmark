#ifndef EXECUTE_SEARCH_H
#define EXECUTE_SEARCH_H

#include <iostream>
#include "../include/call-search.h"
#include "../include/print-duration.h"
#include "../include/result-write.h"

/// Performs searches with n samples 
/*!
 * \param header Stream associated with the header of the output file.
 * \param numbers Stream associated with the data of the output file.
 * \param first Pointer to the first element in the range.
 * \param beginRange Begin of the range.
 * \param searchValue The target value we are looking for within the range.
 * \param choice Search we want to perform.
 * \param samplesN Number of samples
 * \param arraySize Size of the array
 */
void executeSearch(std::ostringstream &header, std::ostringstream &numbers, long *first, 
		   long beginRange, long searchValue, int choice, int samplesN, long arraySize);

/// Performs 100 searches with the sample and calculates the average
/*!
 * \param first Pointer to the first element in the range.
 * \param beginRange Begin of the range.
 * \param searchValue The target value we are looking for within the range.
 * \param sampleSize Size of the sample.
 * \param choice Search we want to perform.
 * \return The average of 100 searches with sample of n size.
 */
std::chrono::nanoseconds calculateAverage(long * first, long beginRange, long searchValue, long sampleSize, int choice);

#endif
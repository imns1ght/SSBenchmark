#ifndef READ_INPUT_h
#define READ_INPUT_H

#include <iostream>

/// Reads the range, search value, number of samples and the search we want to perform.
/*!
 * \param beginRange Begin of the array.
 * \param endRange End of the array.
 * \param searchValue The value we are looking for within the range.
 * \param samplesN Number of samples.
 * \param choice The search we want to perform.
 * \return The array size (endRange - beginRange).
 */
long readInput(long &beginRange, long &endRange, long &searchValue, int &samplesN, int &choice);

#endif
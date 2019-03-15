/*!
 * \file main.cpp
 * \author Jefferson Bruno, Ranieri Santos
 * \date 16/03/2019
 */

#include "../include/read-input.h"
#include "../include/fill-array.h"
#include "../include/execute-search.h"
#include "../include/result-write.h"

int main(void) {
	std::ostringstream header, numbers; 		// Streams associated with table structure
	std::ofstream output ("data/result.txt"); 	// Stream associated with the result (table)

	long beginRange, endRange;  	// Range of array
	long searchValue;		// Value we want to search
	int samplesN;			// Number of samples to test
	int choice;			// Function we want to use

	// Read the input from the user and return the array size (endRange - beginRange)
	auto arraySize = readInput(beginRange, endRange, searchValue, samplesN, choice);

	std::cout << "\n\n\033[1;35m>>>>>\033[0m STARTING tests with " << samplesN 
		  << " SAMPLES \033[1;35m<<<<<\033[0m\n" << std::endl;

	std::cout << "\033[1;35m>>>\033[0m CREATING array \033[1;35m<<<\033[0m\n\n";
	long *array = new long [arraySize];  		// Declaration of the array
	auto first = array;				// Pointer to the first element of array
	fillArray(array, beginRange, arraySize);	// Fill the array for the search

	// Executes the search
	executeSearch(header, numbers, first, beginRange, searchValue, choice, samplesN, arraySize);

	std::cout << "\033[1;35m>>>>>\033[0m ENDING tests with " << samplesN 
		  << " samples \033[1;35m<<<<<\033[0m\n" << std::endl;
	
	std::cout << "\033[1;35m>>>\033[0m Results saved in '/data/result.txt'\n\n";

	// Ending things...
	output << header.str() << std::endl;	// Write the header to 'result.txt'
	output << numbers.str(); 		// Write the data to 'result.txt'
	output.close();		 		// Close ofstream
	delete[] array;		 		// Deallocates the array

	return 0;
}
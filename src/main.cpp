/*!
 * \file main.cpp
 * \brief TODO
 * \author Jefferson Bruno, Ranieri Santos
 * \date march, 16th
 */

#include "../include/result-write.h"
#include "../include/fill-array.h"
#include "../include/call-search.h"
#include "../include/print-duration.h"

int main(void) {
	ostringstream header, numbers; 		// Streams associated with table structure
	ofstream output ("data/result.txt"); 	// Stream associated with the result (table)

	long beginRange, endRange;  	// Range of array
	long searchValue;		// Value we want to search
	int samplesN;			// Number of samples to test
	int choice;			// Function we want to use

	std::cout << "\033[1;35m>>>\033[0m Enter the range of the array [n; m) \033[1;35m<<<\033[0m" << endl;
	std::cout << "\t\033[1;35m>>>\033[0m Begin:\t";
	std::cin >> beginRange;
	std::cout << "\t\033[1;35m>>>\033[0m End:\t";
	std::cin >> endRange;
	std::cout << "\033[1;35m>>>\033[0m Value to search: ";
	std::cin >> searchValue;

	do {
		std::cout << "\033[1;35m>>>\033[0m Number of samples to test: ";
		std::cin >> samplesN;
	} while (samplesN > endRange);
	
	do {
		std::cout << endl << "\033[1;35m>>>\033[0m Available functions \033[1;35m<<<\033[0m" << endl 
			  << "\033[1;35m[1]\033[0m Linear search" << endl
			  << "\033[1;35m[2]\033[0m Binary search" << endl
			  << "\033[1;35m[3]\033[0m Binary search (recursive)" << endl
			  << "\033[1;35m[4]\033[0m Ternary search" << endl
			  << "\033[1;35m[5]\033[0m Ternary search (recursive)" << endl
			  << "\033[1;35m[6]\033[0m Jump search" << endl
			  << "\033[1;35m[7]\033[0m Fibonacci search" << endl;
		std::cout << endl << "\033[1;35m>>>\033[0m Function you want to use: ";
		std::cin >> choice;
	} while ((choice < 1) || (choice > 7));	// Run while out of range [1, 7]

	std::cout << "\n\n\033[1;35m>>>>>\033[0m STARTING tests with " << samplesN 
		  << " SAMPLES \033[1;35m<<<<<\033[0m\n";
	std::cout << endl << "\033[1;35m>>>\033[0m CREATING array \033[1;35m<<<\033[0m\n\n";
	auto arraySize = endRange - beginRange;		// Size of array
	long *array = new long [arraySize];  		// Declaration of the array
	auto first = array;				// Pointer to the first element of array
	fillArray(array, beginRange, arraySize);	// Fill the array for the search
	
	auto sampleIncrement = arraySize / samplesN;	// Calculates the increment of each sample
	auto sampleRemainder = arraySize % samplesN;	// If remainder exists, save to increment each sample.
	auto sampleSize = sampleIncrement;		// Size of the samples

	header << "During time (ms)" << "\t" << "Sample Size";
	// Performs searches while n samples are not reached
	for (auto i = 0; i < samplesN; i++) {
		long *result;				// Result of the search
		std::chrono::nanoseconds sum {0};	// Sum of search times
		std::chrono::nanoseconds average {0};	// Average of 100 searches for each sample

		std::cout << "\033[1;35m>>>\033[0m SAMPLE [" << i+1 << "] [" 
			  << beginRange << ":" << sampleSize << ") \033[1;35m<<<\033[0m" << endl;

		for (auto j = 1; j <= 100; j++) {
    			auto start = std::chrono::steady_clock::now();	// Start the clock
			result = callSearch(first, (array + sampleSize), searchValue, choice);
    			auto end = std::chrono::steady_clock::now();	// Stop the clock
			sum += end - start;	// Sums the diff between start and end
			average += sum / j;	// Calculates the progressive average
		}

		if (result == NULL) { // If the value is not found 	
			cout << "\033[1;35m>>>\033[0m Value " << searchValue	     
			     << " NOT FOUND at array in" << endl;

		} else { // If the value is not found 		
			cout << "\033[1;35m>>>\033[0m Value " << searchValue	     
			     << " FOUND at array[" << (*result - beginRange) << "] in" << endl;
		}	

		// Print the search duration time to terminal
		printDuration(average); 
		// Print the search duration time to file
		numbers << fixed << std::chrono::duration <double, std::milli> (average).count() << "\t\t"
		<< right << sampleSize << endl; 
		
		// If remainder exists, increment the sample size.
		if (sampleRemainder > 0) {
			sampleSize += sampleIncrement + 1;
			sampleRemainder--;
		} else {
			sampleSize += sampleIncrement;
		}
		cout << endl;
	}
	std::cout << "\033[1;35m>>>>>\033[0m ENDING tests with " << samplesN 
		  << " samples \033[1;35m<<<<<\033[0m\n" << endl;
	
	std::cout << "\033[1;35m>>>\033[0m Results saved in '/data/result.txt'\n\n";

	// Ending things...
	output << header.str() << endl; // Write the header to 'result.txt'
	output << numbers.str(); 	// Write the data to 'result.txt'
	output.close();		 	// Close ofstream
	delete[] array;		 	// Deallocation of array

	return 0;
}
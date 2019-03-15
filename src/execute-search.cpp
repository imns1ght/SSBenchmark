#include "../include/execute-search.h"

void executeSearch(std::ostringstream &header, std::ostringstream &numbers, long *first, 
		   long beginRange, long searchValue, int choice, int samplesN, long arraySize) {

	auto sampleIncrement = arraySize / samplesN;	// Calculates the increment of each sample
	auto sampleRemainder = arraySize % samplesN;	// If remainder exists, save to increment each sample.
	auto sampleSize = sampleIncrement;		// Size of the samples

	header << "During time (ms)" << "\t" << "Sample Size";
	// Performs searches while n samples are not reached
	for (int i = 0; i < samplesN; i++) {
		std::cout << "\033[1;35m>>>\033[0m SAMPLE [" << i+1 << "] [" 
			  << beginRange << ":" << sampleSize << ") \033[1;35m<<<\033[0m" << std::endl;

		auto average = calculateAverage(first, beginRange, searchValue, sampleSize, choice);

		// Print the search duration time to terminal
		printDuration(average); 
		// Write the search duration time to output stream
		numbers << std::fixed << std::chrono::duration <double, std::milli> (average).count() << "\t\t"
		<< std::right << sampleSize << std::endl; 
		
		// If remainder exists, increment the sample size.
		if (sampleRemainder > 0) {
			sampleSize += sampleIncrement + 1;
			sampleRemainder--;
		} else {
			sampleSize += sampleIncrement;
		}
		std::cout << std::endl;
	}
}

std::chrono::nanoseconds calculateAverage(long * first, long beginRange, long searchValue, long sampleSize, int choice) {
	long *result; 				// Result of the search
	std::chrono::nanoseconds sum {0};	// Sum of searches for each sample
	std::chrono::nanoseconds average {0};	// Average of 100 searches for each sample

	// Performs 100 searchs to find the average value
	for (int j = 1; j <= 100; j++) {
    		auto start = std::chrono::steady_clock::now();	// Start the clock
		result = callSearch(first, (first + sampleSize), searchValue, choice);
    		auto end = std::chrono::steady_clock::now();	// Stop the clock
		sum += (end - start); 	// Sums the diff between start and end
		average += (sum / j);	// Calculates the progressive average
	}

	if (result == NULL) { // If the value is not found 	
		std::cout << "\033[1;35m>>>\033[0m Value " << searchValue	     
			     << " NOT FOUND in" << std::endl;

	} else { // If the value is found 		
			std::cout << "\033[1;35m>>>\033[0m Value " << searchValue	     
			     << " FOUND at array[" << (*result - beginRange) << "] in" << std::endl;
	}	

	return average;
}
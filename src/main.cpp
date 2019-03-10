/*!
 * \file main.cpp
 * \brief TODO
 * \author Jefferson Bruno, Ranieri Santos
 * \date march, 16th
 */

#include <chrono>     
#include "../include/fill-array.h"
#include "../include/linear-search.h"
#include "../include/binary-search.h"
#include "../include/ternary-search.h"
#include "../include/jump-search.h" 

int main(void) {	
	long size = 500000000;		// Size of array
	long searchValue = 250000000;	// Value we want to search
	long * array = new long [size]; // Declaration of the array
	
	fillArray(array, size);

	std::cout << ">>> STARTING computation <<<\n";
    	auto start = std::chrono::steady_clock::now();	// Start the clock

	//auto result = const_cast <long *>(lsearch(array, (array + size), searchValue));
	//auto result = const_cast <long *>(bsearch(array, (array + size), searchValue));
	//auto result = const_cast <long *>(bsearch_recursive(array, (array + size), searchValue));
	//auto result = const_cast <long *>(tsearch(array, (array + size), searchValue));
	//auto result = const_cast <long *>(tsearch_recursive(array, (array + size), searchValue));
	auto result = const_cast <long *>(jsearch(array, (array + size), searchValue));

    	auto end = std::chrono::steady_clock::now();	// Stop the clock
    	std::cout << ">>> ENDING computation <<<\n";

    	auto diff = end - start; //Store the time difference between start and end

	// Seconds
    	auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    	std::cout << "\t>>> " << diff_sec.count() << " sec" << std::endl;
    	// Milliseconds (10^-3)
    	std::cout << "\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        << " ms" << std::endl;
    	// Nanoseconds (10^-9)
    	std::cout << "\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
        << " ns" << std::endl;

	if (result == NULL) { 	
		cout << endl << ">>> ERROR 404 (NOT FOUND)" << endl; // If the value is found
	} else { 		
		cout << endl << ">>> Value " << searchValue	     // If the value is not found 
		<< " at [" << *result << "]" << endl;
	}

	delete[] array;

	return 0;
}
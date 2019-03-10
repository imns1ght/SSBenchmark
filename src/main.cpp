/*!
 * \file main.cpp
 * \brief TODO
 * \author Jefferson Bruno, Ranieri Santos
 * \date march, 16th
 */
 
#include "../include/fill-array.h"
#include "../include/print-duration.h"
#include "../include/linear-search.h"
#include "../include/binary-search.h"
#include "../include/ternary-search.h"
#include "../include/jump-search.h" 

int main(void) {	
	long size = 500000000;		// Size of array
	long searchValue = 25000;	// Value we want to search
	long *array = new long [size];  // Declaration of the array
	
	std::cout << ">>> CREATING array <<<\n";
	fillArray(array, size);

	std::cout << ">>> STARTING search <<<\n";
    	auto start = std::chrono::steady_clock::now();	// Start the clock

	//auto result = const_cast <long *>(lsearch(array, (array + size), searchValue));
	//auto result = const_cast <long *>(bsearch(array, (array + size), searchValue));
	//auto result = const_cast <long *>(bsearch_recursive(array, (array + size), searchValue));
	//auto result = const_cast <long *>(tsearch(array, (array + size), searchValue));
	//auto result = const_cast <long *>(tsearch_recursive(array, (array + size), searchValue));
	auto result = const_cast <long *>(jsearch(array, (array + size), searchValue));

    	auto end = std::chrono::steady_clock::now();	// Stop the clock
    	std::cout << ">>> ENDING search <<<\n";

    	auto diff = end - start; 	// Store the time difference between start and end
	printDuration(diff);		// Print the search duration time

	if (result == NULL) { 	
		cout << endl << ">>> ERROR 404 (NOT FOUND)" << endl; // If the value is found
	} else { 		
		cout << endl << ">>> Value " << searchValue	     // If the value is not found 
		<< " FOUND at array[" << *result << "]" << endl;
	}

	delete[] array;

	return 0;
}
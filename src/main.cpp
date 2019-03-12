/*!
 * \file main.cpp
 * \brief TODO
 * \author Jefferson Bruno, Ranieri Santos
 * \date march, 16th
 */
 
#include "../include/fill-array.h"
#include "../include/call-search.h"
#include "../include/print-duration.h"

int main(void) {	
	long size;			// Size of array
	long searchValue;		// Value we want to search
	int choice;			// Function we want to use

	std::cout << "\033[1;35m>>>\033[0m Enter the size of the array: ";
	std::cin >> size;
	std::cout << "\033[1;35m>>>\033[0m Enter the value to search: ";
	std::cin >> searchValue;

	std::cout << endl << "\033[1;35m>>>\033[0m Available functions \033[1;35m<<<\033[0m" << endl 
			  << "\033[1;35m[1]\033[0m Linear search" << endl
			  << "\033[1;35m[2]\033[0m Binary search" << endl
			  << "\033[1;35m[3]\033[0m Binary search (recursive)" << endl
			  << "\033[1;35m[4]\033[0m Ternary search" << endl
			  << "\033[1;35m[5]\033[0m Ternary search (recursive)" << endl
			  << "\033[1;35m[6]\033[0m Jump search" << endl
			  << "\033[1;35m[7]\033[0m Fibonacci search" << endl;
	
	do {
		std::cout << endl << "\033[1;35m>>>\033[0m Enter the function you want to use: ";
		std::cin >> choice;
	} while ((choice < 1) || (choice > 7));	// Run while out of range [1, 7]
	
	std::cout << endl << "\033[1;35m>>>\033[0m CREATING array \033[1;35m<<<\033[0m\n";
	long *array = new long [size];  // Declaration of the array
	auto first = array;		// Pointer to the first element of array
	auto last = array + size;	// Pointer to the last element + 1 of array
	fillArray(first, size);		
	
	std::cout << "\033[1;35m>>>\033[0m STARTING search \033[1;35m<<<\033[0m\n";
    	auto start = std::chrono::steady_clock::now();	// Start the clock
	auto result = callSearch(first, last, searchValue, choice);
    	auto end = std::chrono::steady_clock::now();	// Stop the clock
    	std::cout << "\033[1;35m>>>\033[0m ENDING search \033[1;35m<<<\033[0m\n";

    	auto diff = end - start; 	// Store the time difference between start and end

	if (result == NULL) { 	
		cout << endl << "\033[1;35m>>>\033[0m ERROR 404 (NOT FOUND)" << endl; // If the value is found
	} else { 		
		cout << endl << "\033[1;35m>>>\033[0m Value " << searchValue	     // If the value is not found 
		<< " FOUND at array[" << *result << "] in" << endl;
	}
	printDuration(diff);		// Print the search duration time
	cout << endl;

	delete[] array;

	return 0;
}
/*!
 * \file read-input.cpp
 * \brief Read the input from the user
 */

#include "../include/read-input.h"

long readInput(long &beginRange, long &endRange, long &searchValue, int &samplesN, int &choice) {
	std::cout << "\033[1;35m>>>\033[0m Enter the range of the array [n; m) \033[1;35m<<<\033[0m" << std::endl;
	std::cout << "\t\033[1;35m>>>\033[0m Begin:\t";
	std::cin >> beginRange;
	std::cout << "\t\033[1;35m>>>\033[0m End:\t";
	std::cin >> endRange;
	std::cout << "\033[1;35m>>>\033[0m Value to search: ";
	std::cin >> searchValue;

	do {
		std::cout << "\033[1;35m>>>\033[0m Number of samples: ";
		std::cin >> samplesN;
	} while (samplesN > endRange);
	
	
	std::cout << std::endl << "\033[1;35m>>>\033[0m Available functions \033[1;35m<<<\033[0m" << std::endl 
		  	  << "\033[1;35m[1]\033[0m Linear search" << std::endl
		  	  << "\033[1;35m[2]\033[0m Binary search" << std::endl
		  	  << "\033[1;35m[3]\033[0m Binary search (recursive)" << std::endl
		  	  << "\033[1;35m[4]\033[0m Ternary search" << std::endl
			  << "\033[1;35m[5]\033[0m Ternary search (recursive)" << std::endl
			  << "\033[1;35m[6]\033[0m Jump search" << std::endl
			  << "\033[1;35m[7]\033[0m Fibonacci search" << std::endl;
	do {
		std::cout << std::endl << "\033[1;35m>>>\033[0m Function you want to use: ";
		std::cin >> choice;
	} while ((choice < 1) || (choice > 7));	// Run while out of range [1, 7]

	return (endRange - beginRange); // Return the size of array
}
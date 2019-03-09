/*!
 * \file main.cpp
 * \brief TODO
 * \author Jefferson Bruno, Ranieri Santos
 * \date march, 16th
 */

#include "../include/linear-search.h"
#include "../include/binary-search.h"
#include "../include/ternary-search.h"
#include <chrono>     

#define LIMIT 500000000
#define SEARCH 374456000

using namespace std::chrono; 

int main(void) {	
	long * array = new long [LIMIT];

	for (long i = 0; i < LIMIT; i++) {
		array[i] = i;
	}

	std::cout << ">>> STARTING computation <<<\n";
    	auto start = std::chrono::steady_clock::now();

	//auto result = const_cast <long *>(bsearch(array, (array + LIMIT - 1), SEARCH));
	auto result = const_cast <long *>(bsearch_recursive(array, (array + LIMIT - 1), SEARCH));
	// auto result = const_cast <long *>(tsearch(array, (array + LIMIT - 1), SEARCH));

    	auto end = std::chrono::steady_clock::now();
    	std::cout << ">>> ENDING computation <<<\n";

    	auto diff = end - start; //Store the time difference between start and end

	// Seconds
    	auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    	std::cout << "\t>>> " << diff_sec.count() << " s" << std::endl;

    	// Milliseconds (10^-3)
    	std::cout << "\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        << " ms" << std::endl;

    	// Nanoseconds (10^-9)
    	std::cout << "\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
        << " ns" << std::endl;
	
	cout << endl << "Result: " << *result << endl;

	delete[] array;

	return 0;
}
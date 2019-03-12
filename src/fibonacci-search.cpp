#include "../include/fibonacci-search.h"

const long *fibsearch(const long *first, const long *last, long value){
        // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
        
        // Initialize the fib sequence
        auto fib1 = 0;                  // Number of elements of the first block
        auto fib2 = 1;                  // Number of elements of the second block
        auto fibN = fib1 + fib2;        // Total of elements (first + second)

        // Store the smallest fib number greater than or equal to value
        while (fibN < std::distance(first, last)) {
                fib1 = fib2;
                fib2 = fibN;
                fibN = fib1 + fib2;
        }
        
        int offset = -1; // Eliminated range 

        // Find the value while exists elements
        while (fibN > 1) {
                // Defines the position of the index
                int i = std::min(fib1 + offset, (int) std::distance(first, last) - 1);
                auto *m = first + i;    // Aux pointer

                if (*m > value) {       // Back 2 subarrays if is greater than value
                        fibN = fib1; 
			fib2 = fib2 - fib1; 
			fib1 = fibN - fib2;

                } else if (*m < value) { // Back 1 subarray if is less than value
                        fibN = fib2; 
			fib2 = fib1; 
			fib1 = fibN - fib2; 
                        offset = i;

                } else {                
                        return m;       // If is found
                }
        }

        // Compare the last element with value 
        if((fib2 && (*first + offset + 1)) == value) {
                return ((first + offset) + 1);
        }

        return NULL; // If the value is not found 
}


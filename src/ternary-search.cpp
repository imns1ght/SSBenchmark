#include "../include/ternary-search.h"

const long *tsearch(const long *first, const long *last, long value){
        auto distance = std::distance(first, last); /* Current length */

	while (distance > 0) {
		auto offset = distance / 3; // Determine the third part of the array
                auto first3rd = first + offset; // 1st third element pointer
                auto second3rd = last - offset; // 2nd third element pointer

		if (value == *first3rd) { // If the element is the 1st3rd part
			return first3rd;
                
                } else if (value == *second3rd) { // If the element is the 2st3rd part
                        return second3rd;

		} else if ((value > * first3rd++) && (value < *second3rd--)) { // If the element is between 1st3rd part and 2nd3rd part
                        first = first3rd;
                        last = second3rd;
			distance = std::distance(first, last);

                } else if (value > *second3rd) { // If the element is after 2nd3rd part
			first = second3rd;
			distance = std::distance(first, last);

		} else if (value < *first3rd) { // If the element is before 1st3rd part
			last = first3rd;
			distance = std::distance(first, last);

		}
	}

	return last; // If the value is not found 
}


const long *tsearch_recursive(const long *first, const long *last, long value){
        auto distance = std::distance(first, last); /* Current length */

	while (distance > 0) {
		auto offset = distance / 3; // Determine the third part of the array
                auto first3rd = first + offset; // 1st third element pointer
                auto second3rd = last - offset; // 2nd third element pointer

		if (value == *first3rd) { // If the element is the 1st3rd part
			return first3rd;
                
                } else if (value == *second3rd) { // If the element is the 2st3rd part
                        return second3rd;

		} else if ((value > * first3rd++) && (value < *second3rd--)) { // If the element is between 1st3rd part and 2nd3rd part
                        first = first3rd; 
                        last = second3rd;
			return tsearch_recursive(first, last, value);

                } else if (value > *second3rd) { // If the element is after 2nd3rd part
			first = second3rd;
			return tsearch_recursive(first, last, value);

		} else if (value < *first3rd) { // If the element is before 1st3rd part
			last = first3rd;
			return tsearch_recursive(first, last, value);

		}
	}

	return last; // If the value is not found 
}
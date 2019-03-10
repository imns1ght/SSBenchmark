#include "../include/print-duration.h"

void printDuration(std::chrono::nanoseconds diff) {
	// Seconds
    	auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    	std::cout << "\t>>> " << diff_sec.count() << " sec" << std::endl;

    	// Milliseconds (10^-3)
    	std::cout << "\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        << " ms" << std::endl;

    	// Nanoseconds (10^-9)
    	std::cout << "\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
        << " ns" << std::endl;
}
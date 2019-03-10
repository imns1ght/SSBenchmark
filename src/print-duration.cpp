#include "../include/print-duration.h"

void printDuration(std::chrono::nanoseconds diff) {
	// Seconds
    	auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    	std::cout << "\t\033[1;35m>>>\033[0m " << diff_sec.count() << " sec" << std::endl;

    	// Milliseconds (10^-3)
    	std::cout << "\t\033[1;35m>>>\033[0m " << std::chrono::duration <double, std::milli> (diff).count()
        << " ms" << std::endl;

    	// Nanoseconds (10^-9)
    	std::cout << "\t\033[1;35m>>>\033[0m " << std::chrono::duration <double, std::nano> (diff).count()
        << " ns" << std::endl;
}
# Type 'make' to compile
all:
	g++ -Wall -g -std=c++11 src/main.cpp src/call-search.cpp src/fill-array.cpp src/print-duration.cpp src/linear-search.cpp src/binary-search.cpp src/ternary-search.cpp src/jump-search.cpp -o searching

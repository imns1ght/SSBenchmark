# Type 'make' to compile
all:
	g++ -Wall -g -std=c++11 src/main.cpp src/fill-array.cpp src/linear-search.cpp src/binary-search.cpp src/ternary-search.cpp src/jump-search.cpp -o searching

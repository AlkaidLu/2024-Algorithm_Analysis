# Makefile for Sorting Algorithm
CXX = g++
CXXFLAGS = -O3 -o
all: main

main: main.cpp algorithm.h algorithm.cpp Test.cpp
	$(CXX) $(CXXFLAGS) main.o main.cpp Test.cpp algorithm.cpp

clean:
	rm -f main.o
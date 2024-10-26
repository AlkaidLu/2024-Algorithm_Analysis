CC=g++
CFLAGS=-I. -Wall -std=c++11

all: InsertSortTest

InsertSortTest: InsertSort.o InsertSortTest.o main.o out.o
	$(CC) -o $@ $^

InsertSort.o: InsertSort.cpp C algorithm.h
	$(CC) $(CFLAGS) -c $<

InsertSortTest.o: InsertSortTest.cpp
	$(CC) $(CFLAGS) -c $<

main.o: C+main.cpp C algorithm.h
	$(CC) $(CFLAGS) -c $<

out.o: out.cpp C out.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o InsertSortTest
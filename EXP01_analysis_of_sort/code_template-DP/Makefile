CC=g++

all: data_gen main analyser

data_gen:
	$(CC) data_gen.cpp -o data_gen

main:
	$(CC)  main.cpp algorithm.cpp test.cpp -o main

analyser:
	$(CC) analyser.cpp algorithm.cpp test.cpp -o analyser

.PHONY(clean):
clean:
	rm -rf *.o *.data data_gen main analyser

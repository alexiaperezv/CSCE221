all: test

test: MinQueue.o 
	c++ -std=c++11 MinQueue.o -o test

MinQueue.o: MinQueue.cpp MinQueue.h
	c++ -std=c++11 -c MinQueue.cpp

clean:
	rm -f *.o test
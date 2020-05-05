all: test

test: collection.o collection_test.o Stress_ball.o
	c++ -std=c++11 collection.o collection_test.o Stress_ball.o -o test

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp

collection.o: collection.cpp collection.h
	c++ -std=c++11 -c collection.cpp Stress_ball.cpp

collection_test.o: collection_test.cpp
	c++ -std=c++11 -c collection_test.cpp

clean:
	rm -f *.o test

run:
	./test
all: test

test: Collection.o Collection_test.o Stress_ball.o  Jeans.o 
	c++ -std=c++11 Collection.o Collection_test.o Stress_ball.o  Jeans.o -o test

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp

Collection.o: Collection.cpp Collection.h
	c++ -std=c++11 -c Collection.cpp Stress_ball.cpp Jeans.cpp

Collection_test.o: Collection_test.cpp
	c++ -std=c++11 -c Collection_test.cpp

Jeans.o: Jeans.cpp Jeans.h
	c++ -std=c++11 -c Jeans.cpp

clean:
	rm -f *.o test

run:
	./test
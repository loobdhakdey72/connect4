main: main.o board.o solver.o
	g++ main.o board.o solver.o -o main

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp board.hpp
	g++ -c board.cpp

solver.o: solver.cpp solver.hpp
	g++ -c solver.cpp

clean:
	rm *.o main
main: main.o board.o solver.o hashmap.o
	g++ main.o board.o solver.o hashmap.o -o main

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp board.hpp
	g++ -c board.cpp

solver.o: solver.cpp solver.hpp
	g++ -c solver.cpp

hashmap.o: hashmap.cpp hashmap.hpp
	g++ -c hashmap.cpp

clean:
	rm *.o main
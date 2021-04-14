output: main.o hash.o
	g++ main.o hash.o -o hash

main.o: main.cpp
	g++ -c main.cpp

hash.o: hash.cpp hash.h
	g++ -c hash.cpp

clean: 
	rm *.o hash


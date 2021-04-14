CC=g++
CFLAGS=-c
LIBS=""

default: helloworld.o
	$(CC) helloworld.o -o helloworld

helloworld.o: helloworld.cpp
	$(CC) $(CFLAGS) helloworld.cpp

clean:
	rm *.o helloworld
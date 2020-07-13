CC=gcc
CFLAGS=-c
LIBS=""

default: hello.o
	$(CC) hello.o -o hello

hello.o: hello.c
	$(CC) $(CFLAGS) hello.c

clean:
	rm *.o hello
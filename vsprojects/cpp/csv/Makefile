CC=g++
CFLAGS=-c
LIBS=""

default: csv.o
	$(CC) csv.o -o makecsv

csv.o: csv.cpp
	$(CC) $(CFLAGS) csv.cpp

clean:
	rm *.o makecsv drinks.csv
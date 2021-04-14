GTKMM = `pkg-config gtkmm-3.0 --cflags --libs`
CC = g++ -c
GG = g++

all:	radioButtons.h radioButtons.cpp main.cpp
	$(CC) radioButtons.cpp $(GTKMM)
	$(CC) main.cpp $(GTKMM)
	$(GG) radioButtons.o main.o $(GTKMM)
	mv a.out radioButtons
	./radioButtons

clean:	
	rm *.o
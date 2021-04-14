GTKMM = `pkg-config gtkmm-3.0 --cflags --libs`
CC = g++ -c
GG = g++

all:	checkButton.h checkButton.cpp main.cpp
	$(CC) checkButton.cpp $(GTKMM)
	$(CC) main.cpp $(GTKMM)
	$(GG) checkButton.o main.o $(GTKMM)
	mv a.out checkButton
	./checkButton

clean:	
	rm *.o
GTKMM = `pkg-config gtkmm-3.0 --cflags --libs`
CC = g++ -c
GG = g++

all:	scale.h scale.cpp main.cpp
	$(CC) scale.cpp $(GTKMM)
	$(CC) main.cpp $(GTKMM)
	$(GG) scale.o main.o $(GTKMM)
	mv a.out RangeWidgets
	./RangeWidgets

clean:	
	rm *.o
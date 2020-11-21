GTKMM = `pkg-config gtkmm-3.0 --cflags --libs`
CC = g++ -c
GG = g++

buttons:	buttons.h buttons.cpp example_buttons.cpp
	$(CC) buttons.cpp $(GTKMM)
	$(CC) example_buttons.cpp $(GTKMM)
	$(GG) buttons.o example_buttons.o $(GTKMM)
	mv a.out example_buttons
	./example_buttons

clean:	
	rm *.o

GTKMM = `pkg-config gtkmm-3.0 --cflags --libs`
CC = g++ -c
GG = g++

hello:	helloworld.h helloworld.cpp main.cpp
	$(CC) helloworld.cpp $(GTKMM)
	$(CC) main.cpp $(GTKMM)
	$(GG) helloworld.o main.o $(GTKMM)
	mv a.out helloworld
	./helloworld

clean:	
	rm *.o
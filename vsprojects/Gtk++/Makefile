all: helloworld

helloworld: main.o helloworld.o
	 g++ helloworld.o main.o `pkg-config gtkmm-3.0 --cflags --libs`

hellworld.o: helloworld.cpp main.cpp
	 g++ -c helloworld.cpp `pkg-config gtkmm-3.0 --cflags --libs`
	 g++ -c main.cpp `pkg-config gtkmm-3.0 --cflags --libs`
     
clean:
	 rm helloworld.o main.o helloworld
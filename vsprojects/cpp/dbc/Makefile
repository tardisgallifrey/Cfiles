output: dbc.o Calculator.o
	g++ dbc.o Calculator.o -o dbc

dbc.o: dbc.cpp
	g++ -c dbc.cpp

Calcualtor.o: Calculator.cpp
	g++ -c Calculator.cpp

clean: 
	rm *.o dbc

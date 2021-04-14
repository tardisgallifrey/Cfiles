GTK3LIBS = `pkg-config --libs gtk+-3.0`
GTK3FLAGS = `pkg-config --cflags gtk+-3.0`
CC = gcc -c
GG = gcc

all:	exampleapp.h exampleappwin.h exampleappmain.c exampleappclass1.c exampleappclass2.c resources.c
	$(CC) $(GTK3FLAGS) exampleappmain.c $(GTK3LIBS)
	$(CC) $(GTK3FLAGS) exampleappclass1.c $(GTK3LIBS)
	$(CC) $(GTK3FLAGS) exampleappclass2.c $(GTK3LIBS)
	$(CC) $(GTK3FLAGS) resources.c $(GTK3FLAGS)
	$(GG) $(GTK3FLAGS) exampleappmain.o exampleappclass1.o exampleappclass2.o resources.o $(GTK3LIBS)
	mv a.out exampleapp
	./exampleapp

clean:	
	rm *.o
CC=g++
CFLAGS=-c -Wall

studente: studente.o
	$(CC) $(CFLAGS) studente.o -o studente

studente.o: Studente.cpp Studente.h
	$(CC) $(CFLAGS) Studente.cpp
	
clean: 
	rm -f progetto *.o *~ *#
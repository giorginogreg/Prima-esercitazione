CC=g++
C_FLAGS=-c -Wall -std=c++11
.PHONY: clean

#progetto: progetto.o lib.o
#	$(CC) progetto.o lib.o -o progetto
#progetto.o: progetto.cpp lib.h
#	$(CC) $(C_FLAGS) progetto.cpp
#lib.o: lib.cpp lib.h
#	$(CC) $(C_FLAGS) lib.cpp

main: main.o Queue.o
	$(CC) main.o Queue.o -o main

main.o: Queue.o
	$(CC) $(C_FLAGS) main.cpp

Queue.o:
	$(CC) $(C_FLAGS) ../src/Queue.cpp

clean:
	@rm -rf *.o *~ *#
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"

CC=g++
C_FLAGS=-c -Wall -std=c++11
.PHONY: clean

#progetto: progetto.o lib.o
#	$(CC) progetto.o lib.o -o progetto
#progetto.o: progetto.cpp lib.h
#	$(CC) $(C_FLAGS) progetto.cpp
#lib.o: lib.cpp lib.h
#	$(CC) $(C_FLAGS) lib.cpp

Tests: OutOfBoundException.o Tests.o
	$(CC) Tests.o OutOfBoundException.o -o Tests && ./Tests

Tests.o :
	$(CC) $(C_FLAGS) Tests.cpp -o Tests.o

OutOfBoundException.o:
	$(CC) $(C_FLAGS) ../Exception/OutOfBoundException.cpp -o OutOfBoundException.o

clean:
	@rm -rf *.o *~ *#
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"

CC=g++
C_FLAGS=-c -Werror -std=c++17
.PHONY: clean

#progetto: progetto.o lib.o
#	$(CC) progetto.o lib.o -o progetto
#progetto.o: progetto.cpp lib.h
#	$(CC) $(C_FLAGS) progetto.cpp
#lib.o: lib.cpp lib.h
#	$(CC) $(C_FLAGS) lib.cpp

Tests: IllegalStateException.o OutOfBoundException.o Tests.o
	$(CC) Tests.o IllegalStateException.o OutOfBoundException.o -o Tests && ./Tests && make clean

Tests.o:
	$(CC) $(C_FLAGS) Tests.cpp -o Tests.o

OutOfBoundException.o:
	$(CC) $(C_FLAGS) ../Exception/OutOfBoundException.cpp -o OutOfBoundException.o

IllegalStateException.o:
	$(CC) $(C_FLAGS) ../Exception/IllegalStateException.cpp -o IllegalStateException.o

clean:
	@rm -rf *.o *~ *#
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"

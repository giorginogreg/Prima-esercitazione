CC=g++
C_FLAGS=-c -Wall -std=c++11
.PHONY: clean

#progetto: progetto.o lib.o
#	$(CC) progetto.o lib.o -o progetto
#progetto.o: progetto.cpp lib.h
#	$(CC) $(C_FLAGS) progetto.cpp
#lib.o: lib.cpp lib.h
#	$(CC) $(C_FLAGS) lib.cpp

Test_Cases: VectorList.o OutOfBoundException.o Test_Cases.o
	$(CC) vector_implementation/VectorList.o vector_implementation/Test_Cases.o vector_implementation/OutOfBoundException.o -o Test_Cases && ./Test_Cases

Test_Cases.o: VectorList.o
	$(CC) $(C_FLAGS) vector_implementation/Test_Cases.cpp -o vector_implementation/Test_Cases.o

linkedListTester: LinkedList.o OutOfBoundException.o LinkedListTester.o
	$(CC) pointer_implementation/LinkedList.o pointer_implementation/LinkedListTester.o vector_implementation/OutOfBoundException.o -o LinkedListTester

LinkedListTester.o:
	$(CC) pointer_implementation/tester.cpp -o LinkedListTester.o

tester: tester.o VectorList.o OutOfBoundException.o
	$(CC) Node.o vector_implementation/VectorList.o vector_implementation/tester.o vector_implementation/OutOfBoundException.o -o Tester

OutOfBoundException.o:
	$(CC) $(C_FLAGS) vector_implementation/src/OutOfBoundException.cpp -o vector_implementation/OutOfBoundException.o

tester.o: VectorList.o
	$(CC) $(C_FLAGS) vector_implementation/tester.cpp -o vector_implementation/tester.o

LinkedList.o: #Node.o
	$(CC) $(C_FLAGS) pointer_implementation/src/LinkedList.cpp -o pointer_implementation/LinkedList.o

VectorList.o: #Node.o
	$(CC) $(C_FLAGS) vector_implementation/src/VectorList.cpp -o vector_implementation/VectorList.o

clean:
	@rm -rf *.o *~ *#
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"

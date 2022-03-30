CC=g++
C_FLAGS=-c -Wall -std=c++11
.PHONY: clean

TestCases: Postfix.o PostFixTester.o StackList.o
	$(CC) StackList.o Postfix.o PostFixTester.o -o TestCases

PostFixTester.o:
	$(CC) $(C_FLAGS) PostFixTester.cpp -o PostFixTester.o

Postfix.o:
	$(CC) $(C_FLAGS) Postfix.cpp -o Postfix.o

StackList.o:
	$(CC) $(C_FLAGS) ../TDA_by_greg/Lists/pointer_implementation/src/StackList.cpp -o StackList.o

clean:
	@rm -rf *.o *~ *#
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"


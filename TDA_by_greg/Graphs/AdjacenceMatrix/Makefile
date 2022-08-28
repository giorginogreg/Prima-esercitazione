CC=g++
C_FLAGS=-w -c -std=c++11
.PHONY: clean

Test_Cases: Test_Cases.o
	$(CC) Test_Cases.o -o adjacencyMatrixGraphTestCases && make clean && ./adjacencyMatrixGraphTestCases

Test_Cases.o:
	$(CC) $(C_FLAGS) -std=c++11 adjacencyMatrixGraphTestCases.cpp -o Test_Cases.o

# --------------------------------------------------------------------------------

tester: tester.o 
	$(CC) tester.o -o adjacencyMatrixGraphTester && ./adjacencyMatrixGraphTester && make clean

tester.o:
	$(CC) $(C_FLAGS) main.cpp -o tester.o

# --------------------------------------------------------------------------------

clean:
	@rm -rf *.o *~ *#
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"

CC=g++
C_FLAGS=-c -Wall -std=c++11
.PHONY: clean

Test_Matrix: Matrix.o Test_Matrix.o
	$(CC) Matrix.o Test_Matrix.o -o Test_Matrix

Test_Matrix.o: Matrix.o
	$(CC) $(C_FLAGS) test_matrix.cpp -o test_matrix.o

Test_Cases: Test_Cases.o Matrix.o
	$(CC) Matrix.o Test_Cases.o -o Test_Cases
	clear
	@echo "Program built successfully!"
	@make clean

Test_Cases.o: Matrix.o
	$(CC) $(C_FLAGS) Test_Cases.cpp -o Test_Cases.o

Matrix.o: Matrix.cpp
	$(CC) $(C_FLAGS) Matrix.cpp -o Matrix.o

clean:
	@rm -rf *.o *~ *# Matrix\.dSYM
	@echo "Not necessaries files deleted"

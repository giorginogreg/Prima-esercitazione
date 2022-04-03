CC=g++
C_FLAGS=-c -Wall -std=c++11
OUTPUT_FLAGS=-fprofile-arcs -ftest-coverage
.PHONY: clean gcov lcov genhtml generate_report

main: main.o
	$(CC) -o main pointerQueue.cpp

main.o:
	$(CC) $(C_FLAGS) pointerQueue.cpp

clean:
	@rm -rf *.o *~ *# *.gcno *.gcda *.gcov main_coverage.info main
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"

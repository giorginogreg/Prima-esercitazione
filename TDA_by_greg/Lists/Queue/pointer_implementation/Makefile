CC=g++
C_FLAGS=-c -Wall -std=c++11
OUTPUT_FLAGS=-fprofile-arcs -ftest-coverage
.PHONY: clean gcov lcov genhtml generate_report

#progetto: progetto.o lib.o
#	$(CC) progetto.o lib.o -o progetto
#progetto.o: progetto.cpp lib.h
#	$(CC) $(C_FLAGS) progetto.cpp
#lib.o: lib.cpp lib.h
#	$(CC) $(C_FLAGS) lib.cpp

generate_report:
	make main && make gcov && make lcov && make genhtml

genhtml:
	genhtml main_coverage.info --output-directory outHTML && make clean

lcov:
	 lcov -c --directory . --output-file main_coverage.info

gcov:
	gcov main.cpp && ./main

main: main.o
	$(CC) -o main $(OUTPUT_FLAGS) main.cpp

main.o:
	$(CC) $(C_FLAGS) main.cpp

#Queue.o:
#	$(CC) $(C_FLAGS) ../src/Queue.cpp

clean:
	@rm -rf *.o *~ *# *.gcno *.gcda *.gcov main_coverage.info main
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"

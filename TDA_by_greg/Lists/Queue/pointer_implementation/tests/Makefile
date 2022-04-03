CC=g++
C_FLAGS=-c -Wall -std=c++14
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
	gcov tester_pointerQueue.cpp

main:
	$(CC) -std=c++14 -o tests_pointerQueue $(OUTPUT_FLAGS) tester_pointerQueue.cpp && ./tests_pointerQueue

tester_pointerQueue:
	$(CC) $(C_FLAGS) tester_pointerQueue.cpp

#Queue.o:
#	$(CC) $(C_FLAGS) ../src/Queue.cpp

clean:
	@rm -rf *.o *~ *# *.gcno *.gcda *.gcov main_coverage.info tests_pointerQueue
	@rm -rf vector_implementation/*.o vector_implementation/*~ vector_implementation/*#
	@echo "Not necessaries files deleted"

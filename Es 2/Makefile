CC=g++
C_FLAGS=-c -Wall
.PHONY: clean

test_studente: Studente_Class.o provastudente.o
	$(CC) Studente_Class.o provastudente.o -o test_studente
	clear
	@echo "Program built successfully!"
	@make clean

provastudente.o: Studente_Class.o
	$(CC) $(C_FLAGS) provastudente.cpp

Studente_Class.o: 
	$(CC) $(C_FLAGS) Studente_Class.cpp
	
clean:
	@rm -f *.o *.out *~ *#
	@echo "Not necessaries files deleted"

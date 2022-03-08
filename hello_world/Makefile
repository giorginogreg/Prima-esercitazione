CC=g++
C_FLAGS=-c -Wall
.PHONY: clean

hello_world: hello_world.o
	$(CC) hello_world.o -o hello_world
	clear
	@echo "Program built successfully!"
	@make clean

hello_world.o: main.cpp
	$(CC) $(C_FLAGS) main.cpp -o hello_world.o

clean:
	@rm -f *.o *~ *#
	@echo "Not necessaries files deleted"

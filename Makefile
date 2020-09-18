CC = g++
CFLAGS = -Wall -Wextra -Wfloat-equal -std=c++14 

.PHONY: all clean test solver

all: solver

solver: quadratic_equations.o user_part.o
	$(CC) -o solver quadratic_equations.o user_part.o $(CFLAGS)

test: quadratic_equations.o test_prog.o
	$(CC) -o run_tests test_prog.o quadratic_equations.o $(CFLAGS)

user_part.o: user_part.cpp
	$(CC) -c user_part.cpp $(CFLAGS)

test_prog.o: test_prog.cpp test_lib.h
	$(CC) -c test_prog.cpp $(CFLAGS)

quadratic_equations.o: quadratic_equations.cpp quadratic_equations.h
	$(CC) -c quadratic_equations.cpp $(CFLAGS)

clean:
	rm -rf *.o run_tests solver 

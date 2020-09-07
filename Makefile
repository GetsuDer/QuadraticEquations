all: quadratic_equations.o

test: quadratic_equations.o test_prog.o
	g++ -o run_tests test_prog.o quadratic_equations.o
test_prog.o: test_prog.cpp test_lib.h
	g++ -c test_prog.cpp 
quadratic_equations.o: quadratic_equations.cpp quadratic_equations.h
	g++ -c quadratic_equations.cpp
clean:
	rm -rf *.o quadratic_equations run_tests


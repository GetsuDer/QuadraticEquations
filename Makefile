TESTDIR = Testing/
INCLUDEDIR = Include/
SOURCEDIR = Source/
OBJECTDIR = ObjectFiles/

CC = g++
CFLAGS = -Wall -Wextra -Wfloat-equal -std=c++14 

.PHONY: all clean test solver run_tests

all: solver

run_tests: test
	./run_tests < $(TESTDIR)tests;

solver: $(OBJECTDIR)quadratic_equations.o $(OBJECTDIR)user_part.o
	$(CC) -o solver $(OBJECTDIR)quadratic_equations.o $(OBJECTDIR)user_part.o $(CFLAGS)

test: $(OBJECTDIR)quadratic_equations.o $(OBJECTDIR)test_prog.o
	$(CC) -o run_tests $(OBJECTDIR)test_prog.o $(OBJECTDIR)quadratic_equations.o $(CFLAGS)

$(OBJECTDIR)user_part.o: $(SOURCEDIR)user_part.cpp $(INCLUDEDIR)quadratic_equations.h ObjectDir
	$(CC) -c $(SOURCEDIR)user_part.cpp $(CFLAGS) -o $(OBJECTDIR)user_part.o

$(OBJECTDIR)test_prog.o: $(TESTDIR)test_prog.cpp $(TESTDIR)test_lib.h $(INCLUDEDIR)quadratic_equations.h ObjectDir
	$(CC) -c $(TESTDIR)test_prog.cpp $(CFLAGS) -o $(OBJECTDIR)test_prog.o

$(OBJECTDIR)quadratic_equations.o: $(SOURCEDIR)quadratic_equations.cpp $(INCLUDEDIR)quadratic_equations.h ObjectDir
	$(CC) -c $(SOURCEDIR)quadratic_equations.cpp $(CFLAGS) -o $(OBJECTDIR)quadratic_equations.o

ObjectDir:
	mkdir -p ObjectFiles

clean:
	rm -rf *.o run_tests solver ObjectFiles

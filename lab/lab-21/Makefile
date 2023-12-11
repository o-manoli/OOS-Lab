CC=g++
CFlags=-c -Wall
EXE=appEXE
OBJs=main
test_cases:=$(wildcard *.txt)
SHELL:=/usr/bin/bash
test_runner=python3 tester.py

all: test clean

link: $(OBJs)
	$(CC) -o $(EXE) *.o

%:%.cpp
	$(CC) $(CFlags) $< -o $@.o

run: link
	@ echo - - - - - - - - - - - - - -
	@ ./$(EXE)
	@ echo - - - - - - - - - - - - - -

test: link
	$(test_runner) ./$(EXE) $(test_cases)

clean:
	rm -f *.o $(EXE)


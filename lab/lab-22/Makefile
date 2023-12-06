CC=g++
CFlags=-c -Wall
EXE=appEXE
OBJs=main

all: run clean

link: $(OBJs)
	$(CC) -o $(EXE) *.o

%:%.cpp
	$(CC) $(CFlags) -o $@.o $<

run: link
	@ echo - - - - - - - - - - - - - -
	@ ./$(EXE)
	@ echo - - - - - - - - - - - - - -

clean:
	rm -f *.o $(EXE)


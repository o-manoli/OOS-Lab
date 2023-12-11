CC=g++
CFlags=-c -Wall -O2
EXE=emainEXE
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)

all: run clean

main: $(OBJS)
	@ $(CC) -o $(EXE) *.o

%.o: %.cpp
	@ $(CC) $(CFlags) $< -o $@

run: main
	@ echo - - - - - - - - - - -
	@ ./$(EXE)
	@ echo - - - - - - - - - - -

clean:
	@ rm -f *.o $(EXE)


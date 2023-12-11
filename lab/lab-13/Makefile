CC=g++
CFlags=-c -Wall
EXE=AppEXE
SRCs=main.cpp
OBJs=$(SRCs:.cpp=.o)
DEPSRCs=Employee.cpp Manager.cpp Worker.cpp
DEPs=$(DEPSRCs:.cpp=.o)
Headers=$(DEPSRCs:.cpp=.h)

all: run clean

link: $(Headers) $(DEPs) $(OBJs)
   $(CC) -o $(EXE) $(Headers) $(DEPs) $(OBJs)

%.o: %.cpp
   $(CC) $(CFlags) -o $@ $<

run: link
   @ echo - - - - - - - - - - - - - -
   @ ./$(EXE)
   @ echo - - - - - - - - - - - - - -

clean:
   rm -f *.o $(EXE)


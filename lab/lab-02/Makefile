all: main run clean

main: main.o
	@ g++ -o mainEXE *.o

main.o: main.cpp
	@ g++ -c main.cpp

run: main
	@ echo - - - - - - - - - - - - - -
	./mainEXE
	@ echo - - - - - - - - - - - - - -

clean:
	rm -f *.o mainEXE


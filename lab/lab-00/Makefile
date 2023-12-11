all: main run-test clean

run-test: main
   @echo -------------------------
   ./main_exe < input.txt
   @echo -------------------------

run:
   ./main_exe

main: main.o
   @ g++ -o main_exe *.o

main.o: main.cpp
   @ g++ -c main.cpp

clean:
   rm -f *.o ./main_exe


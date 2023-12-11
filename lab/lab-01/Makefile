all: main run-test clean

main: main.o
   @ g++ -o main_exe *.o

main.o: main.cpp
   @ g++ -c *.cpp

run: main
   ./main_exe

run-test: main
   @ echo ---------------------------
   ./main_exe < input.txt
   @ echo ---------------------------

clean:
   rm -f *.o main_exe


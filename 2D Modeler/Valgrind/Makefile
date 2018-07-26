CC = g++
FLAGS = -std=c++14 -Wall -g

all: vectorTest

vectorTest: vectorValgrind.cpp
	$(CC) $(FLAGS) vectorValgrind.cpp -o vectorTest

clean:
	rm *.o vectorTest vectorValgrind.tar

tar:
	tar cf vectorValgrind.tar vectorValgrind.scr Makefile vectorValgrind.cpp

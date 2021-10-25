CXX = g++

all: main

main: main.o
	$(CXX) -o main main.o

main.o: main.cpp
	$(CXX) -c main.cpp

.PHONY: clean
clean:
	rm -f main *.o

CXX = g++

all: example example-tls max-connect

example: example.o
	$(CXX) -o example example.o -lpthread

example-tls: example-tls.o
	$(CXX) -o example-tls example-tls.o -lpthread -lssl -lcrypto

max-connect: max-connect.o
	$(CXX) -o max-connect max-connect.o -lpthread -lssl -lcrypto

%.o: %.cc
	$(CXX) -c $< -o $@

.PHONY: clean
clean:
	rm -f example example-tls max-connect *.o

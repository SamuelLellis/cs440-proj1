CC = g++
CFLAGS = -Wall -g


test: test.o Deque.hpp
	$(CC) $(CFLAGS) -o testing test.o

test.o: test.cpp Deque.hpp
	$(CC) $(CFLAGS) -c test.cpp

clean:
	rm testing test.o

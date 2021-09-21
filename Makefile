CC = g++
CFLAGS = -Wall -ldl -g


testing: otest.o Deque.hpp
	$(CC) $(CFLAGS) -o testing otest.o

otest.o: otest.cpp Deque.hpp
	$(CC) $(CFLAGS) -c otest.cpp

clean:
	rm testing otest.o

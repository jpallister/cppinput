
HEADERS=cppinput.hpp
CC=g++-4.9
CFLAGS=-std=c++11 -g

all: test

test: $(SOURCES) $(HEADERS) test.cpp Makefile
	$(CC) $(CFLAGS) -o test $(SOURCES) test.cpp
	

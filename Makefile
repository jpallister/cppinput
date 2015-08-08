
HEADERS=cppinput.hpp
CC=g++-4.9
CFLAGS=-std=c++11 -g -Wall

all: test example

test: $(SOURCES) $(HEADERS) test.cpp Makefile
	$(CC) $(CFLAGS) -o test $(SOURCES) test.cpp

example: $(SOURCES) $(HEADERS) example.cpp Makefile
	$(CC) $(CFLAGS) -o example $(SOURCES) example.cpp
	

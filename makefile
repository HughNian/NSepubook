all: epub

CC = g++

CFLAGS = -g -Wall -ansi

INCLUDE = ./lib

epub: main.o html.o
	$(CC) -o epub main.o html.o

main.o: main.cc
	$(CC) $(CFLAGS) -c  main.cc

html.o: html.cc html.h
	$(CC) $(CFLAGS) -c html.cc html.h
clean:
	@rm epub -rf *.o *.h.gch *.txt

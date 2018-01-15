CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -Includes -g -c -o
BINDIR = bin/
SRCDIR = src/
OBJDIR = include/

all:
	$(CC) $(CFLAGS) $(BINDIR)main.o $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(BINDIR)testmain.o $(SRCDIR)testmain.c
	$(CC) $(CFLAGS) $(BINDIR)hashAPI.o $(SRCDIR)hashAPI.c
	$(CC) $(BINDIR)main.o $(BINDIR)hashAPI.o -o main
	$(CC) $(BINDIR)testmain.o $(BINDIR)hashAPI.o -o testmain
run:
	$(BINDIR)main
test:
	$(BINDIR)testmain
clean:
	rm $(BINDIR)*.o
 

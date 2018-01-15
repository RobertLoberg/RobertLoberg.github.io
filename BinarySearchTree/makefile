CC=gcc
CFLAGS = -Wall -std=c99 -g -pedantic -Includes -c -o
BINDIR = bin/
SRCDIR = src/
OBJDIR = include/

all:
	$(CC) $(CFLAGS) $(BINDIR)main.o $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(BINDIR)testmain.o $(SRCDIR)testmain.c
	$(CC) $(CFLAGS) $(BINDIR)BinarySearchTreeAPI.o $(SRCDIR)BinarySearchTreeAPI.c
	$(CC) $(CFLAGS) $(BINDIR)conversation.o $(SRCDIR)conversation.c
	$(CC) $(BINDIR)main.o $(BINDIR)BinarySearchTreeAPI.o $(BINDIR)conversation.o -o main
	$(CC) $(BINDIR)testmain.o $(BINDIR)BinarySearchTreeAPI.o $(BINDIR)conversation.o -o testmain
run:
	$(BINDIR)main
test:
	$(BINDIR)testmain
clean:
	rm $(BINDIR)*.o
 

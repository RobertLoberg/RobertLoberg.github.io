CC=gcc
CFLAGS = -Wall -std=c99 -pedantic -Includes -c -o
BINDIR = bin/
SRCDIR = src/
OBJDIR = include/

all:
	$(CC) $(CFLAGS) $(BINDIR)main.o $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(BINDIR)testmain.o $(SRCDIR)testmain.c
	$(CC) $(CFLAGS) $(BINDIR)LinkedListAPI.o $(SRCDIR)LinkedListAPI.c
	$(CC) $(CFLAGS) $(BINDIR)car.o $(SRCDIR)car.c
	$(CC) $(BINDIR)main.o $(BINDIR)LinkedListAPI.o $(BINDIR)car.o -o main
	$(CC) $(BINDIR)testmain.o $(BINDIR)LinkedListAPI.o $(BINDIR)car.o -o testmain
run:
	$(BINDIR)main
test:
	$(BINDIR)testmain
clean:
	rm $(BINDIR)*.o
 

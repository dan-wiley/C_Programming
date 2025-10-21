CC = gcc
CFLAGS = -Wall -g

# Targets
all: main

main: main.o person.o
	$(CC) $(CFLAGS) -o main main.o person.o

main.o: main.c person.h
	$(CC) $(CFLAGS) -c main.c

person.o: person.c person.h
	$(CC) $(CFLAGS) -c person.c

clean:
	rm -f *.o main


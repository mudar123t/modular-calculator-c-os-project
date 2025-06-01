CC = gcc
CFLAGS = -Wall -g

all: calculator add sub mul div saver

calculator: calculator.c
	$(CC) $(CFLAGS) -o calculator calculator.c

add: add.c
	$(CC) $(CFLAGS) -o add add.c

sub: sub.c
	$(CC) $(CFLAGS) -o sub sub.c

mul: mul.c
	$(CC) $(CFLAGS) -o mul mul.c

div: div.c
	$(CC) $(CFLAGS) -o div div.c

saver: saver.c
	$(CC) $(CFLAGS) -o saver saver.c

clean:
	rm -f calculator add sub mul div saver results.txt


CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 

.PHONY: all clean


all: clean grade

arvore.o: arvore.c
fila.o: fila.c

test: fila.o arvore.o test.c
	$(CC) $(CFLAGS) fila.o arvore.o test.c -o test -lm

grade: test
	./test


CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 
LDFLAGS=-lm

all: teste
	./teste

ls.o: ls.c

teste: ls.o teste.c

clean:
	rm -f ls.o teste



CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 
LDFLAGS=-lm

all: teste
	./teste

le.o: le.c

teste: le.o teste.c

clean:
	rm -f le.o teste
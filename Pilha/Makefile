CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 
LDLIBS=-lm

all: teste
	./teste

pilha.o: pilha.c
	$(CC) $(CFLAGS) pilha.c -c
	

# Supondo que está usando a implementação de lista implementada anteriormente
teste: pilha.o teste.c
	$(CC) $(CFLAGS) pilha.o teste.o -o teste -lm

clean:
	rm -f pilha.o teste
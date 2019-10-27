#include "arvore.h"

typedef struct fila{
	struct nodo * array;
	int inicio;
	int tam;
	int capacidade;
}FILA;

struct fila *create_fila(int cap);

int tamanho_fila(FILA *f);

void exibirFila(FILA *f);

int insereFila(FILA *f, struct nodo * tmp);

struct nodo * excluirElemFila(FILA *f);

void destroyFila(FILA *f);

#define MAX 5
#include <stdio.h>
#include <stdlib.h>

/** Descritor da pilha
  */
struct pilha{
	int topo;
	int vetorItem[MAX];
	   /* seu código aqui, deve usar uma lista */
};

 //typedef elem int;

/** Cria uma pilha
 * @return  um descritor ou NULL
 */
struct pilha * create();

/** Apaga todos elementos da pilha
 * @param p descritor da pilha
 * @return 1 se OK, 0 se erro
 */
int makenull(struct pilha * p);

/* Retorna o elemento no topo da pilha, ou zero se não existir
 * @param p descritor da pilha
 * @return o elemento ou 0
 */
int top(struct pilha * p);

/* eDscarta o topo da pilha
 * @param p descritor de pilha
 * @return 1 se OK, 0 se erro
 */
int pop(struct pilha * p);

/* Insere um elemento no topo da pilha
 * @param p descritor de pilha
 * @param val elemento a ser inserido
 * @return 1 se OK, 0 se erro
 */
int push(struct pilha * p, int val);

/* Retorna se a pilha está vazia ou não
 * @param p descritor de pilha
 * @return 1 se vazia, 0 se não
 */
 int vazia(struct pilha *p);
/** Desaloca toda a pilha
  * @param p descritor da pilha
  */
void destroy(struct pilha * p);

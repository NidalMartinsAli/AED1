#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "fila.h"

//Nome: Nidal Martins Ali

struct nodo * inicializa_arvore(int entradas, int * valores){
	
	int i = 0;
	struct nodo * raiz = NULL;

	if(entradas <= 0 || valores == NULL){
		return NULL;
	}
	
	for(i = 0; i < entradas; i++){
		raiz = insere_nodo(raiz,valores[i]);
	}
	
	raiz->capacidade_fila = entradas;
	
	return raiz;
}

////////////////////////////////////////////////////////////////////////
struct nodo *insere_nodo(struct nodo * raiz, int valor){
	
	if(raiz == NULL){
       	if((raiz = malloc(sizeof(struct nodo))) == NULL){
           	return 0;
        }
        raiz->valor = valor;
        raiz->dir = NULL;
        raiz->esq = NULL;
        return raiz;
	}
    
    else{
		if (raiz->valor > valor) {
			raiz->esq = insere_nodo(raiz->esq, valor);
		}
		else if(raiz->valor < valor) {
			raiz->dir = insere_nodo(raiz->dir, valor);
			}
			return raiz;
		}	
	}
//////////////////////////////////////////////////////////////////////
struct nodo * minimo(struct nodo* raiz) 
{ 
    struct nodo* c = raiz; 
 
    while (c && c->esq != NULL) 
        c = c->esq; 
  
    return c; 
} 
//////////////////////////////////////////////////////////////////////
struct nodo * remove_nodo(struct nodo * raiz, int valor){
 
    if (raiz == NULL){
    return NULL; 
	}
  
    if (valor < raiz->valor) 
        raiz->esq = remove_nodo(raiz->esq, valor); 
  
    else if (valor > raiz->valor) 
        raiz->dir = remove_nodo(raiz->dir, valor); 
  
    else
    { 
        if (raiz->esq == NULL) 
        { 
            struct nodo *temp = raiz->dir; 
            free(raiz); 
            return temp; 
        } 
        else if (raiz->dir == NULL) 
        { 
            struct nodo *temp = raiz->esq; 
            free(raiz); 
            return temp; 
        } 
   
        struct nodo* temp = minimo(raiz->dir); 
   
        raiz->valor= temp->valor; 
  
        raiz->dir = remove_nodo(raiz->dir, temp->valor); 
    } 
    return raiz; 
	
}
		
//////////////////////////////////////////////////////////////////////
int altura(struct nodo * raiz){
	if(raiz == NULL){
		return 0;
	}
	else{
		int altura_esc,altura_dir;
		altura_esc = altura(raiz->esq);
		altura_dir = altura(raiz->dir);
		if(altura_esc > altura_dir){
			return altura_esc + 1;
		}
		else{
			return altura_dir + 1;
		}
	}
}
//////////////////////////////////////////////////////////////////////
struct nodo * busca(struct nodo * raiz, int valor){
	if(raiz == NULL){
		return NULL;
	}
	if(raiz->valor == valor){
		return raiz;
	}
	else if(raiz->valor > valor){
		return busca(raiz->esq,valor);
	}else{
		return busca(raiz->dir,valor);
	}
}
//////////////////////////////////////////////////////////////////////
int balanceada(struct nodo * raiz){
	if(raiz == NULL){
		return 1;
	}
	
	int altura_esc = 0;
	int altura_dir = 0;
	
	altura_esc = altura(raiz->esq);
	altura_dir = altura(raiz->dir);
	
	return (altura_esc-altura_dir);
}
//////////////////////////////////////////////////////////////////////
int numero_elementos(struct nodo * raiz){
	if(raiz == NULL){
		return 0;
	}
	return (numero_elementos(raiz->esq) + 1 + numero_elementos(raiz->dir));
}
//////////////////////////////////////////////////////////////////////
int abrangencia(struct nodo * raiz, int * resultado){
	if(raiz == NULL || resultado == NULL){
		return 0;
	}
	int i = 0;
	printf("CAPACIDADE: %d\n", raiz->capacidade_fila);
	
	struct fila* queue = create_fila(raiz->capacidade_fila);
	struct nodo* tmp = raiz;
	
	while(tmp){
		resultado[i++] = tmp->valor;
		if(tmp->esq != NULL){
			insereFila(queue,tmp->esq);
		}
		if(tmp->dir != NULL){
			insereFila(queue,tmp->dir);
		}
		tmp = excluirElemFila(queue);
	}
	
	destroyFila(queue);
	return i;
}
//////////////////////////////////////////////////////////////////////
int prefix(struct nodo * raiz, int * resultado){
	if(raiz == NULL || resultado == NULL){
		return 0;
	}
	
	int aux = 0;

	resultado[0] = raiz->valor;
	aux += prefix(raiz->esq,&resultado[aux]);
	aux += prefix(raiz->dir,&resultado[aux]);
	
	return aux;
}
//////////////////////////////////////////////////////////////////////
int postfix(struct nodo * raiz, int * resultado){
	if(raiz == NULL || resultado == NULL){
		return 0;
	}
		
	int aux = 0;
	
	aux += postfix(raiz->esq,&resultado[aux]);
	aux += postfix(raiz->dir,&resultado[aux]);
	resultado[aux] = raiz->valor;
	aux++;
	
	return aux;
}
//////////////////////////////////////////////////////////////////////
int infix(struct nodo * raiz, int * resultado){
	if(raiz == NULL || resultado == NULL){
		return 0;
	}
	
	int aux = 0;

	aux += infix(raiz->esq,&resultado[aux]);
	resultado[0] = raiz->valor;
	aux += infix(raiz->dir,&resultado[aux]);
	
	return aux;
}
//////////////////////////////////////////////////////////////////////
void imprime(int * valores, int tamanho){
	if(valores == NULL || tamanho <= 0){
		return;
	}
	int i = 0;
	int k = 0;
	
	for(i = 0; i < tamanho; i++){
		k++;
		printf("|%d| ", valores[i]);
		if(k > 5){
			k = 0;
		}
	}
}
//////////////////////////////////////////////////////////////////////
void destruir_filhos(struct nodo * raiz){
	if(raiz != NULL){
		destruir_filhos(raiz->esq);
		destruir_filhos(raiz->dir);
		free(raiz);
	}
}
//////////////////////////////////////////////////////////////////////
void remove_todos(struct nodo * raiz){
	if(raiz == NULL){
		return;
	}
	destruir_filhos(raiz);
	raiz = NULL;
}
//////////////////////////////////////////////////////////////////////
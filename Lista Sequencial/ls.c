#include "ls.h"
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
struct list * create (int max){

	if(max <= 0){
		return NULL;
	}

	struct list *LISTA = NULL;		//ponteiro lista que aponta pra struct list

	LISTA = (struct list*) malloc(sizeof(struct list)); //alocando dinamicamente a struct

	if (LISTA == NULL){
		return NULL;
	}
 	
 	LISTA->ultimo = 0;
	LISTA->capacidade = max; //var capacidade recebe o tamanho max do vetor


	LISTA->arm = (elem*) malloc(max*sizeof(elem));
	if(LISTA->arm == NULL){
		return NULL;
	}
	
	return LISTA;

}
///////////////////////////////////////////////////////////////////////	
int insert (struct list *desc, int pos, elem item){	 	//função que insere elementos na lista
	
	int i=0;
	pos-=1;

	if(desc == NULL){
		return 0;
	}
	if (desc->ultimo >= desc->capacidade){
		return 0;
	}
	else {
		if ((pos > desc->capacidade) || (pos < 0)){
			return 0;
		}
		else {
			for (i=desc->ultimo-1;i>pos;i--){
				desc->arm[i] = desc->arm[i-1];
			}
			desc->arm[pos] = item;
			desc->ultimo+=1;
			return 1;
		}
	}
}
////////////////////////////////////////////////////////////////////////
int removel(struct list *desc, int pos){	//função que deleta um determinado elemento da lista
	int i=0;
	pos -=1;
	if(desc == NULL){			//
		return 0;				// testa se a lista esta vazia, nula ou fora dos limites
	}							//
	if(pos > desc->ultimo){		//
		return 0;				//
	}							//
	if(desc->ultimo == 0){		//
		return 0;
	}

	else{
		
		for(i=pos;i<desc->ultimo-1;i++){		//for que percorre o vetor e deleta o elemento puxando o da direita para para a esqueda
			desc->arm[i] = desc->arm[i+1];
		}	
		desc->ultimo-=1;
		return 1;
	}
}
/////////////////////////////////////////////////////////////////////////
elem get(struct list *desc, int pos){
	
	pos-=1;

	if(desc == NULL){
		return 0;
	}

	if ((pos < 0) ||(pos > desc->ultimo)){
		return 0;
	}
	return desc->arm[pos];
}
////////////////////////////////////////////////////////////////////////
int set(struct list *desc, int pos, elem item){
		
	pos-=1;
	if (desc == NULL){
		return 0;
	}

	if ((pos < 0) ||(pos >= desc->ultimo)){
		return 0;
	}
	
	desc->arm[pos] = item;
	return 1;

}
////////////////////////////////////////////////////////////////////////
int locate(struct list *desc, int pos, elem item){   //função que encontra e retona um determinado valor da lista
	int i;
	pos-=1;

	for(i=pos;i<length(desc);i++){
		if(desc->arm[i] == item){
			return i+1;
		}
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////
int length(struct list *desc){       //função que chega o comprimento atual da lista
	return desc->ultimo;
}
////////////////////////////////////////////////////////////////////////
int max(struct list *desc){			 //função que checa a capacidade maxima da lista, retornando seu tamanho max
	return desc->capacidade;
}
////////////////////////////////////////////////////////////////////////
int full(struct list *desc){		 //função que checa se a lista esta cheia
	if(length(desc) == max(desc)){	 // se esta, vai retornar 1, se nao retorna 0
		return 1;
	}
	else{
		return 0;
	}
}
////////////////////////////////////////////////////////////////////////
void destroy(struct list *desc){	//função que destroi a lista, liberando ela.
	free (desc);
}
///////////////////////////////////////////////////////////////////////
/* Aqui devem ser implementadas as funções definidas em ls.h */
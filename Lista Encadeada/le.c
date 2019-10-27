#include "le.h"
#include <stdio.h>
#include <stdlib.h>



/* Aqui devem ser implementadas as funções definidas em le.h */

//////////////////////////////////////////////////////////////////////////////////////
struct llist * create_l(){

	struct llist *Lista = NULL;

	Lista = (struct llist*) malloc (sizeof(struct llist));

	if(Lista == NULL){
		return NULL;
	}
	Lista->tam = 0;
	Lista->cabeca = NULL;

	return Lista;
}
//////////////////////////////////////////////////////////////////////////////////////
 elem * create_node(int val){
 	
 	struct elem *nodo = NULL;

 	nodo = (struct elem*) malloc(sizeof(struct elem));

 	if (nodo == NULL){
 		return NULL;
 	}
 	nodo->val = val;
 	nodo->next = NULL;

 	return nodo;
 }
//////////////////////////////////////////////////////////////////////////////////////
 int insert_l(struct llist *desc, elem * prev, elem * item){


 	if ((desc == NULL) || (item == NULL)){
 		return 0;
 	}

 	if (prev == NULL){
 		item->next = desc->cabeca;
 		desc->cabeca = item;

 		desc->tam++;
 		return 1;
 	}
 	item->next = prev->next;
 	prev->next = item;

 	desc->tam++;
 	return 1;
 }
 ////////////////////////////////////////////////////////////////////////////////////
 int delete_l(struct llist *desc, elem * prev){

 	elem *aux;

 	if(desc == NULL){
 		return 0;
 	}

 	//ARRUMAR
 	if(prev == NULL){
 		aux = desc->cabeca;
 		desc->cabeca = aux->next;
 		free(aux);
 	}

 	aux = desc->cabeca;
 	desc->cabeca = desc->cabeca->next;
 	desc->tam--;
 	free(aux);
 	return 1;
 }
 /////////////////////////////////////////////////////////////////////////////////////
 elem * get_l(struct llist *desc, int pos){
 	if((desc == NULL)|| (pos-1<0) || (pos > length_l(desc))){
 		return NULL;
 	}
	int i = pos;

 	struct elem *aux = desc->cabeca;

	while (i > 1 && aux != NULL){
		i--;
		aux = aux->next;
		}	
		if(aux == NULL){
			return NULL;
		}	
		else{
			return aux;
		}
	}	

////////////////////////////////////////////////////////////////////////////////////
int set_l(struct llist *desc, int pos, int val){
	
	if((desc == NULL)|| (pos-1) < 0 || (pos-1) > length_l(desc)-1){
 		return 0;
 	}
	int i = 0;
 	struct elem *aux = desc->cabeca;

 	for(i=0;i<(pos-1);i++){ 		
		aux = aux->next;
 	}
 	aux->val = val;
 	return 1;
}
////////////////////////////////////////////////////////////////////////////////////
elem * locate_l(struct llist *desc, elem * prev, int val){
	if(desc == NULL){
 		return NULL;
 	}
 	struct elem *aux = NULL;

 	if(prev == NULL){
 		aux = desc->cabeca;
 	}
 	while (aux != NULL){
 		if(aux->val == val){
 			return aux;
 		}
 		else{
 			aux = aux->next;
 		}
 	}

 	return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////
int length_l(struct llist *desc){
	if (desc == NULL){
		return 0;
	}
	return (desc->tam);
}
//////////////////////////////////////////////////////////////////////////////////////

void destroy_l(struct llist *desc){
	struct elem * aux = NULL;
	while(desc->cabeca != NULL){
		aux = desc->cabeca;
		desc->cabeca = desc->cabeca->next;
		free(aux);
	}
	free (desc);
}

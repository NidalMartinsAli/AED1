#include "simplegrade.h"
#include "le.h"

#define MAX 5


void test_create(){
	DESCRIBE("CRIA LISTA");
	WHEN("Eu crio uma lista");


	IF("Sem parâmetros");
	THEN("Resultado deve ser ponteiro");
	struct llist * l = create_l();
	isNotNull(l,1);

	THEN("Comprimento deve ser 0");
	isEqual(length_l(l),0,1);

	destroy_l(l);
}

void test_inserts(){
	int i;
	elem * node, * previous;

	struct llist * l = create_l();

	DESCRIBE("INSERE ELEMENTOS");
	WHEN("Eu insiro elementos no começo");
	IF("Insiro um número razoável MAX");
	THEN("Deve inserir todos");
	for(i=1; i<=MAX; i++){
		node = create_node(i);
		isEqual(insert_l(l, NULL, node), 1, 1);
	}
	THEN("Comprimento deve ser MAX");
	isEqual(length_l(l),MAX,1);

	THEN("Primeiro elemento deve ser MAX");
	node = get_l(l,1);
	isNotNull(node, 1);
	if(node)
		isEqual(node->val, MAX, 1);
	destroy_l(l);

  l = create_l();

	WHEN("Eu insiro elementos no fim");
	IF("Insiro tantos quanto o máximo");
	THEN("Deve inserir todos");
	previous = NULL;
	for(i=1; i<=MAX; i++){
		node = create_node(i);
		isEqual(insert_l(l, previous, node), 1, 1);
		previous = node;
	}
	THEN("Primeiro elemento deve ser 1");
	node = get_l(l,1);
	isNotNull(node, 1);
	if(node)
		isEqual(node->val, 1, 1);

	destroy_l(l);
}

void test_delete(){

	int i;
	elem * node = NULL;
	struct llist * l = create_l();

	for(i=MAX; i>0; i=i-1){
		insert_l(l, NULL, create_node(i));
	}

	DESCRIBE("REMOVE ELEMENTOS");
	WHEN("Eu removo os elementos de uma lista");
	THEN("Deve remover");

	for(i=1; i<=MAX; i++){
		node = get_l(l,1);
		isEqual(delete_l(l, node),1,1);
	}
	THEN("Comprimento deve ser 0");
	isEqual(length_l(l),0,1);
	destroy_l(l);
}

void test_get_set(){
	int i;
	elem * result;

	struct llist * l = create_l();
	for(i=MAX; i>0; i=i-1){
		insert_l(l, NULL, create_node(i));
	}
	DESCRIBE("CONSULTANDO E MUDANDO ELEMENTOS");

	WHEN("Eu consulto um elemento inserido");
	THEN("Ele deve estar presente");
	result = get_l(l,1);
	isNotNull(result,1);
	if (result)
		isEqual(result->val, 1, 1);

	WHEN("Eu consulto uma posição inexistente");
	THEN("Ele deve retornar NULL");
	isNull(get_l(l,MAX+1),1);

	WHEN("Eu mudo o valor de um elemento existente");
	THEN("Ele deve mudar");
	isEqual(set_l(l,1,99), 1, 1);
	result = get_l(l,1);
	isNotNull(result,1);
	if (result)
		isEqual(result->val, 99, 1);

	WHEN("Eu mudo o valor de um elemento inexistente");
	THEN("Ele deve retornar erro");
	isEqual(set_l(l,MAX+1,1),0,1);

	destroy_l(l);
}

void test_locate_l(){
	int i;
	elem * result;

	struct llist * l = create_l();
	for(i=MAX; i>0; i=i-1){
		insert_l(l, NULL, create_node(i));
	}

	DESCRIBE("LOCALIZANDO ELEMENTOS");
	WHEN("Procuro elemento inexistente");
	THEN("Não deve achar");
	isNull(locate_l(l,NULL,-1), 1);

	WHEN("Procuro elemento existente");
	THEN("Deve retornar a posição correta na lista");
	result = locate_l(l,NULL,1);
	isNotNull(result, 1);
	if (result)
		isEqual(result->val, 1, 1);
	result = locate_l(l, NULL, MAX);
	isNotNull(result, 1);
	if (result)
		isEqual(result->val, MAX, 1);

	WHEN("Procuro elemento existente depois da posição dele");
	THEN("Não deve achar");
	isNull(locate_l(l,get_l(l,2),1),1);

	destroy_l(l);

}



int main () {
	test_create();
	test_inserts();
	test_get_set();
	test_locate_l();
	
	GRADEME();
	
	if (grade==maxgrade)
		return 0;
	else return grade;
}

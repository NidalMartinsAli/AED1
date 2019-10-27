#include "simplegrade.h"
#include "ls.h"

#define MAX 5


void test_create(){
	DESCRIBE("CRIA LISTA");
	WHEN("Eu crio uma lista");
	IF("Tamanho negativo");
	THEN("Resultado deve ser NULL");
	isNull(create(-1),1);

	IF("Tamanho zero");
	THEN("Resultado deve ser NULL");
	isNull(create(0),1);

	IF("Tamanho positivo e não muito grande");
	THEN("Resultado deve ser ponteiro");
	struct list * l = create(MAX);
	isNotNull(l,1);

	THEN("Comprimento deve ser 0");
	isEqual(length(l),0,1);

	destroy(l);
}

void test_inserts(){
	int i;

	struct list * l = create(MAX);

	DESCRIBE("INSERE ELEMENTOS");
	WHEN("Eu insiro elementos no começo");
	IF("Insiro tantos quanto o máximo");
	THEN("Deve inserir todos");
	for(i=1; i<=MAX; i++){
		isEqual(insert(l, i, i), 1, 1);
	}
	THEN("Comprimento deve ser MAX");
	isEqual(length(l),MAX,1);

	THEN("Deve estar cheia");
	isEqual(full(l),1, 1);

	IF("Insiro mais que a capacidade");
	THEN("Resultado deve ser erro");
	isEqual(insert(l,MAX+1, MAX+1), 0, 1);

	destroy(l);
  	l = create(MAX);

	WHEN("Eu insiro elementos no fim");
	IF("Insiro tantos quanto o máximo");
	THEN("Deve inserir todos");
	for(i=1; i<=MAX; i++){
		insert(l, i, i);
	}
	isEqual(full(l), 1, 1);
	destroy(l);
}

void test_remove(){

	int i;

	struct list * l = create(MAX);
	for(i=1; i<=MAX; i++){
		insert(l, i, i);
	}

	DESCRIBE("REMOVE ELEMENTOS");
	WHEN("Eu removo os elementos de uma lista");
	THEN("Deve remover");
	for(i=1; i<=MAX; i++){
		isEqual(removel(l, 1),1,1);
	}
	THEN("Comprimento deve ser 0");
	isEqual(length(l),0,1);
	destroy(l);
}

void test_get_set(){
	int i;

	struct list * l = create(MAX);
	for(i=1; i<MAX; i++){
		insert(l, i, i);
	}

	DESCRIBE("CONSULTANDO E MUDANDO ELEMENTOS");

	WHEN("Eu consulto um elemento inserido");
	THEN("Ele deve estar presente");
	isEqual(get(l,1), 1,1);

	WHEN("Eu consulto uma posição inexistente");
	THEN("Ele deve retornar erro (no nosso caso, indefinido)");
	get(l,MAX);

	WHEN("Eu mudo o valor de um elemento existente");
	THEN("Ele deve mudar");
	isEqual(set(l,1,99), 1, 1);
	isEqual(get(l,1), 99, 1);

	WHEN("Eu mudo o valor de um elemento inexistente");
	THEN("Ele deve retornar erro");
	isEqual(set(l,MAX,1),0, 1);

	destroy(l);
}

void test_locate(){
	int i;

	struct list * l = create(MAX);
	for(i=1; i<=MAX; i++){
		insert(l, i, i);
	}
	DESCRIBE("LOCALIZANDO ELEMENTOS");
	WHEN("Procuro elemento inexistente");
	THEN("Não deve achar");
	isEqual(locate(l,1,-1),0,1);

	WHEN("Procuro elemento existente");
	THEN("Deve retornar a posição correta na lista");
	isEqual(locate(l,1,1),1,1);
	isEqual(locate(l,1,MAX),MAX,1);

	WHEN("Procuro elemento existente depois da posição dele");
	THEN("Não deve achar");
	isEqual(locate(l,2,1),0,1);

	destroy(l);

}



int main () {

	test_create();
	test_inserts();
	test_remove();
	test_get_set();
	test_locate();


	GRADEME();
	
	if (grade==maxgrade)
		return 0;
	else return grade;
}

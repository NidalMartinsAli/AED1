#include "simplegrade.h"
#include "pilha.h"

#define MAX 5


void test_create(){
	DESCRIBE("CRIA PILHA");
	WHEN("Eu crio uma pilha");


	IF("Sem parâmetros");
	THEN("Resultado deve ser ponteiro");
	struct pilha * p = create();
	isNotNull(p,1);

	THEN("Deve ser vazia");
	isEqual(vazia(p),1,1);

	destroy(p);
}

void test_push(){
	int i;
	struct pilha * p = create();

	DESCRIBE("INSERE ELEMENTOS");
	WHEN("Eu insiro elementos");
	IF("Insiro um número razoável MAX");
	THEN("Deve inserir todos");
	for(i=1; i<=MAX; i++){
		isEqual(push(p,i), 1,1);
	}
	THEN("Deve não estar vazia");
	isEqual(vazia(p),0,1);

	THEN("Topo deve ser MAX");
	isEqual(top(p),MAX,1);

	destroy(p);
}

void test_pop(){

	int i, val;
	struct pilha * p = create();


	DESCRIBE("REMOVE ELEMENTOS");
	WHEN("Eu removo os elementos de uma pilha");
	for(i=1; i<=MAX; i++){
		push(p,i);
	}
	for(i=MAX; i>0; i--){
		THEN("Deve ter topo igual a i");
		isEqual(top(p),i,1);
		THEN("Deve remover");
		isEqual(pop(p),1,1);
	}

	THEN("Deve ser vazia");
	isEqual(vazia(p),1,1);
	destroy(p);
}



int main () {
	test_create();
	test_push();
	test_pop();

		
	GRADEME();
	
	if (grade==maxgrade)
		return 0;
	else return grade;
}

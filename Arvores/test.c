#include "simplegrade.h"
#include "arvore.h"
#include <stdlib.h>



void test_criacao(){
	struct nodo * raiz;
	int val;

	DESCRIBE("Testes simples de criar árvore");

	WHEN("Crio uma árvore com número de entradas em zero ou negativo ou sem dados");
	THEN("Deve retornar NULL");

	isNull(inicializa_arvore(-1, NULL),1);
	isNull(inicializa_arvore(0, NULL),1);
	isNull(inicializa_arvore(10, NULL),1);

	WHEN("Crio uma árvore com um elemento");
	THEN("Devo ter só a raiz");
	val = 5;
	raiz = inicializa_arvore(1,&val);
	isNotNull(raiz, 1);
	if (raiz){
		isEqual(raiz->valor, 5, 2);
		free(raiz);
	} else isNotNull(raiz, 2);
}


void test_3_elementos(){
	struct nodo * raiz;
	int balanceada[] = {2, 1 , 3};
	int caminhamento[3];

	DESCRIBE("Testes com criação de três elementos");
	
	WHEN("Crio uma árvore balanceada");
	THEN("Altura deve ser dois");

	raiz = inicializa_arvore(3, balanceada);
	infix(raiz, caminhamento);
	COMMENT("infix");
	imprime(caminhamento, 3);
	isNotNull(raiz, 1);
	if (raiz){
		isEqual(altura(raiz), 2, 2);
		remove_todos(raiz);
	} else isNotNull(raiz, 2);


}	

void test_15_elementos(){
	struct nodo * raiz;
	int balanceada[] = {50, 20, 100, 10, 25, 70, 150, 5, 15, 22, 30, 60, 90, 120, 170};
	//            50
	//      20         100
	//  10    25     70     150
	// 5  15 22 30  60 90 120  170      
	int caminhamento[15];
	int i;

	DESCRIBE("Testes com criação de quinze elementos");
	
	WHEN("Crio uma árvore balanceada");
	THEN("Altura deve ser 4");

	raiz = inicializa_arvore(15, balanceada);
	COMMENT("abrangência");
	abrangencia(raiz, caminhamento);
	imprime(caminhamento, 15);
	isNotNull(raiz, 1);
	if (raiz){
		isEqual(altura(raiz), 4, 2);
	} else isNotNull(raiz, 2);

	THEN("Caminhamento em abrangência deve ser igual à entrada");
	if (raiz){
		for(i=0; (i<15) && (balanceada[i]==caminhamento[i]); i++);
		isEqual(i,15,5);
	} else isNotNull(raiz,5);

	int post_cam[15] = {5, 15, 10, 22, 30, 25, 20, 60, 90, 70, 120, 170, 150, 100, 50};
	THEN("Percorrer pos-fixado deve funcionar");
	if (raiz){
		for(i=0; i<15;i++)
			caminhamento[i] = 0;
		postfix(raiz, caminhamento);
		for(i=0; (i<15) && (post_cam[i]==caminhamento[i]); i++);
		isEqual(i,15,5);
	}	
	else isNotNull(NULL,5);


	IF("Tirar uma folha");
	THEN("Não deve mudar a raiz");
	if (raiz){
		struct nodo * nova_raiz = remove_nodo(raiz, 170);
		if (nova_raiz == raiz){
			THEN("Percorrer em abrangencia deve funcionar");
			for(i=0; i<15;i++)
				caminhamento[i] = 0;
			abrangencia(nova_raiz, caminhamento);
			COMMENT("abrangência");
			imprime(caminhamento, 15);
			for(i=0; (i<14) && (balanceada[i]==caminhamento[i]); i++);
			if (caminhamento[14]==0)
				isEqual(i,14,2);
			else isNotNull(NULL,2);


		


		} else isNotNull(NULL, 2);
		remove_todos(raiz);

	} else isNotNull(raiz,3);


	IF("Tirar a raiz");
	THEN("Próxima raiz deve ser menor da subarvore direita (como nos slides)");
	raiz = inicializa_arvore(15, balanceada);
	if (raiz){
		raiz = remove_nodo(raiz, 50);
		infix(raiz, caminhamento);
		COMMENT("infix");
		imprime(caminhamento, 15);
		abrangencia(raiz, caminhamento);
		COMMENT("abrangência");
		imprime(caminhamento, 15);

		if(raiz){
			isEqual(raiz->valor, 60, 3);
			remove_todos(raiz);
		}
		else isNotNull(raiz,3);

	} else isNotNull(raiz, 3);


}



void test_7_elementos_linear(){
	struct nodo * raiz;
	int naobalanceada[] = {1,2,3,4,5,6,7};
	int caminhamento[20];
	int i;

	DESCRIBE("Testes com criação de sete elementos à direita");
	
	WHEN("Crio uma árvore com inserção não balanceada");
	THEN("Altura deve ser máxima");



	raiz = inicializa_arvore(7, naobalanceada);
	abrangencia(raiz, caminhamento);
	COMMENT("abrangência");
	imprime(caminhamento, 7);
	isNotNull(raiz, 1);
	if (raiz){
		isEqual(altura(raiz), 7, 2);
	} else isNotNull(raiz, 2);

	THEN("Caminhamento em abrangência deve ser 1 2 3 4 5 6 7");
	if (raiz){
		int esperado[7]={1,2,3,4,5,6,7};

		for(i=0; (i<7) && (esperado[i]==caminhamento[i]); i++);
		isEqual(i,7,5);
	} else isNotNull(raiz,5);



	IF("Tirar uma folha");
	THEN("Não deve mudar a raiz");
	if (raiz){
		int esperado[6]={1,2,3,4,5,6};

		struct nodo * nova_raiz = remove_nodo(raiz, 7);
		if (nova_raiz == raiz){
			THEN("Percorrer em abrangencia deve funcionar");
			for(i=0; i<7;i++)
				caminhamento[i] = 0;
			abrangencia(nova_raiz, caminhamento);
			COMMENT("abrangência");
			imprime(caminhamento, 7);
			for(i=0; (i<6) && (esperado[i]==caminhamento[i]); i++);
			if (caminhamento[6]==0)
				isEqual(i,6,2);
			else isNotNull(NULL,2);
		} else isNotNull(NULL, 2);
		remove_todos(raiz);

	} else isNotNull(raiz,3);


	IF("Tirar a raiz");
	THEN("Próxima raiz deve ser menor da subarvore direita (como nos slides)");


	raiz = inicializa_arvore(7, naobalanceada);
	if (raiz){
		raiz = remove_nodo(raiz, 1);
		infix(raiz, caminhamento);
		COMMENT("infix");
		imprime(caminhamento, 6);
		abrangencia(raiz, caminhamento);
		COMMENT("abrangência");
		imprime(caminhamento, 6);

		if(raiz){
			isEqual(raiz->valor, 2, 3);
			remove_todos(raiz);
		}
		else isNotNull(raiz,3);

	} else isNotNull(raiz, 3);

}


void test_remocao(){
	struct nodo * raiz;
	int balanceada[] = {50, 20, 100, 10, 25, 70, 150, 5, 15, 22, 30, 60, 90, 120, 170};
	//            50
	//      20         100
	//  10    25     70     150
	// 5  15 22 30  60 90 120  170      

	DESCRIBE("Testes com remoção de elementos");
	
	WHEN("Crio uma árvore balanceada e removo os elementos menos a raiz");
	THEN("Altura deve ser 1");

	if ((raiz = inicializa_arvore(15, balanceada))){
		for(int i=1; i<15; i++)
			raiz = remove_nodo(raiz, balanceada[i]);
		isEqual(altura(raiz), 1, 4);
		raiz = remove_nodo(raiz, balanceada[0]);
		isNull(raiz, 1);
	} else isNotNull(raiz, 5);

}

int main(){

	test_criacao();
	test_3_elementos();
	test_15_elementos();
	test_7_elementos_linear();
	test_remocao();


	GRADEME();

	if (grade==maxgrade)
		return 0;
	else return grade;

}

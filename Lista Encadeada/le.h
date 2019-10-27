/* Lista simplesmente encadeada. */


typedef struct elem{
  int val;
  /* aqui vai o ponteiro para o próximo elemento */
  struct elem * next;
} elem;

/** Descritor de lista encadeada.
  * O acesso à lista começa na posição 1.
  * Manter a capacidade atual e o ponteiro para o último elemento da lista
  * são opcionais.
  */

struct llist{
  /* your code here! */
  elem * cabeca;
  int tam;
};


/** Cria uma lista.
 * @return descritor de lista ou NULL
 */
struct llist * create_l();

/** Cria um nodo de lista inicializado.
 * @param val valor a ser armazenado
 * @return ponteiro para nodo criado ou NULL
 */
 elem * create_node(int val);


 /** Insere um elemento na lista após um elemento
  * @param desc descritor da lista
  * @param prev nodo anterior, NULL se início da lista
  * @param ponteiro para o item o que será inserido
  * @return 1 se OK, 0 se erro
  */
 int insert_l(struct llist *desc, elem * prev, elem * item);

/** Remove um elemento de uma posição
* @param desc descritor da lista
* @param prev nodo anterior, NULL se início da lista
* @return 1 se OK, 0 se erro
*/
int delete_l(struct llist *desc, elem * prev);

/** Retorna ponteiro para elemento.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @return ponteiro para elemento
 */
elem * get_l(struct llist *desc, int pos);

/** Muda o valor do elemento.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @param item novo valor para item
 * @return 1 se OK, 0 se erro
 */
int set_l(struct llist *desc, int pos, int val);

/** Encontra um elemento com um determinado valor
* @param desc descritor da lista
* @param prev ponteiro para posição em que começa a busca pelo elemento
* @param val  valor buscado
* @return ponteiro caso encontre, NULL se não encontrar
*/
elem * locate_l(struct llist *desc, elem * prev, int val);

/** Retorna o comprimento da lista
* @param desc descritor da lista
* @return comprimento da lista atual
*/
int length_l(struct llist *desc);

/** Destrói a lista, liberando a memória e eliminando todos os elementos.
 * @param desc descritor da lista
 */
void destroy_l(struct llist *desc);

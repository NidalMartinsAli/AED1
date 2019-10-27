
/** Para trocar fácil o que é um elemento da lista.
 * Templates em C++ faz isso melhor. */

typedef int elem;


/** Descritor de lista sequencial.
  * Pré-aloca um vetor de n posições dinamicamente na função create().
  * O acesso à lista começa na posição 1, mas a implementação deve usar a
  *   posição 0 do vetor.
  */
struct list{
  int ultimo;
  int capacidade;
  elem * arm;
};



/** Cria uma lista com capacidade definida
 * @param max capacidade máxima
 * @return descritor de lista ou NULL
 */
struct list * create(int max);

/** Insere um elemento na lista em uma posição
 * @param desc descritor da lista
 * @param pos posição para inserção
 * @param item o que será inserido
 * @return 1 se OK, 0 se erro
 */
int insert(struct list *desc, int pos, elem item);

/** Remove um elemento de uma posição
 * @param desc descritor da lista
 * @param pos posição para remoção
 * @return 1 se OK, 0 se erro
 */
int removel(struct list *desc, int pos);

/** Retorna o valor do elemento. Em alguns casos pode ser melhor retornar
 *   um ponteiro.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @return elemento
 */
elem get(struct list *desc, int pos);

/** Muda o valor do elemento.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @param item novo valor para item
 * @return 1 se OK, 0 se erro
 */
int set(struct list *desc, int pos, elem item);

/** Encontra um elemento com um determinado valor
* @param desc descritor da lista
* @param pos posição onde começa a busca pelo elemento
* @param item  valor buscado
* @return posição caso encontre, 0 se não encontrar
*/
int locate(struct list *desc, int pos, elem item);

/** Retorna o comprimento da lista
* @param desc descritor da lista
* @return comprimento da lista atual
*/
int length(struct list *desc);

/** Retorna o comprimento máximo lista
* @param desc descritor da lista
* @return comprimento da lista atual
*/
int max(struct list *desc);

/** Retorna se a lista está cheia. Usar length() e max() para implementar.
 * @param desc descritor da lista
 * @return 1 se cheia, 0 se ainda possui espaço livre
 */
int full(struct list *desc);

/** Destrói a lista, liberando a memória.
 * @param desc descritor da lista
 */
void destroy(struct list *desc);

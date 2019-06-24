// Mihael Scofield de Azevedo GRR - 20182621.
// Eduardo Paim Filho GRR - ...
// Cabeçalho com as funções responsáveis pelas manipulações das estruturas.

/* Pilha */

/* Devolve uma pilha inicializada */
struct pilha *ini_pilha(int cap);

/* Verifica se a pilha está vazia */
int p_vazia(struct pilha *p);

/* Verifica se a pilha está cheia */
int p_cheia(struct pilha *p);

/* Insere elemento passado na pilha */
int push(struct pilha *p, char dado);

/* Remove elemento do topo da pilha */
void pop(struct pilha *p);

/* ------------------------------------------------------ */

/* Fila */

/* Devolve uma fila inicializada */
struct fila *ini_fila(void);

/* Verifica se a fila está vazia */
int f_vazia(struct fila *f);

/* Insere elemento passado na fila */
void enfileira(struct fila *f, char dado);

/* Devolve elemento passado da fila */
struct noh_s *desenfileira(struct fila *f);

/* ------------------------------------------------------ */

/* Função que compara Pedido com bandeja, entrega pedido */
int verifica_pedido(char Pedido[], struct pilha *bandeja);

/* Lista Duplamente Encadeada */

// Por enquanto, não preciso implementar as funções desse carinha não...
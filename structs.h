// Mihael Scofield de Azevedo GRR - 20182621.
// Eduardo Paim Filho GRR - 20182627
// Cabeçalho com todas as estruturas de dados utilizadas no programa.

/* Estrutura de dados suporte */

/* Nó simples */
struct noh_s {
	char dado; // d1. 
	struct noh_s *prox; 
};

/* Nó duplo */
struct noh_d {
	struct noh *ant;
	char dado;
	struct noh *prox;
};

/* ------------------------------------------------------ */

/* Estrutura de dados elementares */

/* Pilha, utilizada para empilhar pedidos e ingredientes */
// Nota: Implementação com Vetor mostrou-se melhor para o projeto.
struct pilha {
	int topo;
	int capacidade; // Define tamanho do vetor.
	char *vetor;
};

/* Fila, utilizada para controlar fluxo de clientes */
// Nota: Filas com ponteiros são uma lista encadeada simples.
struct fila {
	struct noh_s *frente;
	struct noh_s *final;
};

/* Lista Duplamente Encadeada, utilizada... */ 
struct lista_d {
	struct noh_d *inicio;
	struct noh_d *fim;
};

/* ------------------------------------------------------ */

/* Comentários avulsos */
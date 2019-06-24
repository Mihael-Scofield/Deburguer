// Mihael Scofield de Azevedo GRR - 20182621.
// Eduardo Paim Filho GRR - 20182627
// Arquivo com as funções responsáveis pelas manipulações das estruturas.

#include "includes.h"

/* Pilha */

/* Devolve uma pilha inicializada */
struct pilha *ini_pilha(int cap) {
	struct pilha *p; // Pilha criada.
	p = (struct pilha *) malloc(sizeof(struct pilha)); // Alocada com espaço de uma pilha.
	p->capacidade = cap;
	p->topo = -1;
	p->vetor = (char *) malloc(p->capacidade * sizeof(char)); /* Vetor de char,  de tamanho cap vezes tipo utilizado.*/
	return p;
}

/* Verifica se a pilha está vazia */
int p_vazia(struct pilha *p) {
	if (p->topo == -1) // Igual a quando iniciada.
		return 1;
	return 0;
}

/* Verifica se a pilha está cheia */
int p_cheia(struct pilha *p) {
	if (p->topo == p->capacidade - 1) // Topo = capacidade total.
		return 1;
	return 0; // Ainda cabe mais.
}

/* Insere elemento passado na pilha */
int push(struct pilha *p, char dado) {
	if (p_cheia(p))
		return 0;
	else {
		p->topo++;
		p->vetor[p->topo] = dado;
		return 1;
	}
}

/* Remove elemento do topo da pilha */
void pop(struct pilha *p) {
	if (p_vazia(p))
		return;	
	else {
		p->vetor[p->topo] = ' ';
		p->topo--;

	}
}

/* ------------------------------------------------------ */

/* Fila */

/* Devolve uma fila inicializada */
struct fila *ini_fila(void) {
	struct fila *f;
	f = malloc(sizeof(struct fila));
	f->frente = NULL;
	f->final = NULL;
	return f;
}

/* Verifica se a fila está vazia */
int f_vazia(struct fila *f) {
	if ((f->frente == NULL) && (f->final = NULL))
		return 1;
	return 0;
}

/* Insere elemento passado na fila */
void enfileira(struct fila *f, char dado) {
	/* Cria nó simples */
	struct noh_s *n; // Nó novo.
	n = (struct noh_s *) malloc(sizeof(struct noh_s)); // Preenchido com tamanho de um nó.
	n->dado = dado; // Atualização de dados.
	n->prox = NULL;

	/* Enfileiramente propriamente dito */
	if (f_vazia(f)) { // Apenas aponto para o primeiro nó.
		f->frente = n;
		f->final = n;
	}
	else {
		f->final->prox = n; // Último aponta para nó novo.
		f->final = n; // Nó novo torna-se último.
	}
}

/* Devolve elemento passado da fila */
struct noh_s *desenfileira(struct fila *f) {
	if (!(f_vazia(f))) {
		struct noh_s *aux;
		aux = f->frente;
		f->frente = f->frente->prox;
		return aux;
	}
	return 0;
}

/* ------------------------------------------------------ */

/* Função que compara Pedido com bandeja, entrega pedido */
int verifica_pedido(char Pedido[], struct pilha *bandeja) {
	int i;

	if (p_vazia(bandeja))
	{
		return 1;
	}
	else
	{
		for (i = 0; bandeja->topo != -1; i++) {
			if (Pedido[bandeja->topo] != bandeja->vetor[bandeja->topo])
				return 1; // GAME OVER! PEDIDO ERRADO
			pop(bandeja);
		}
		return 0;
	}
}

/* Lista Duplamente Encadeada */

// Por enquanto, não preciso implementar as funções desse carinha não... 
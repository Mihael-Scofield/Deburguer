// Mihael Scofield de Azevedo GRR - 20182621.
// Eduardo Paim Filho GRR - 20182627
// Cabeçalho com as funcoes responsaveis por manipulação de mapa.


/* Lê coordenadas do arquivo passado */
int le_coord(int argc, char *argv[], int *lin, int *col, FILE **am);

/* Retorna mapa inicializado */
char** gera_mapa(int lin, int col, int *lina, int *cola, FILE *am);

/* Responsável por imprimir o mapa */
void imp_mapa(int lin, int col, char *mapa[], char Pedido[], struct pilha *Bandeja, int Ponto);

/* Verifica se é possível fazer o movimento em questão */
int verifica_jogada(int lina, int cola, int lin, int col, char *mapa[]);

/* Função responsável por modificar minhas estruturas de dados */
int altera_struc(char fc, char Pedido[], struct pilha *bandeja);

/* Lê jogada e refaz o mapa. Já implementada para curses */
int jogada(int lin, int col, int *lina, int *cola, char *mapa[], char Pedido[], struct pilha *bandeja);
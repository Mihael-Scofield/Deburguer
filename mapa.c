// Mihael Scofield de Azevedo GRR - 20182621.
// Eduardo Paim Filho GRR - 20182627
// Arquivo que imprime o mapa.

#include "includes.h"

/* Lê coordenadas do arquivo passado */
int le_coord(int argc, char *argv[], int *lin, int *col, FILE **am) {

	/* Leitura de arquivo do mapa */
	*am = fopen("mapcoord.txt", "r+"); // Apenas leitura.
	if (*am == NULL) {
		printf("Falha na abertura do arquivo.");
		return 1;
	}
	fscanf(*am, "%d", lin);
	fseek(*am, 2, SEEK_CUR); // Pula para próxima linha (devido ao enter).
	fscanf(*am, "%d", col);
	return 0;
}

/* Retorna mapa inicializado */
char** gera_mapa(int lin, int col, int *lina, int *cola, FILE *am) {
	int i, j;
	char **mapa;

	/* Criação da matriz */
	mapa = malloc(lin * sizeof(int *)); // Vetor de lin ponteiros (para linha).
	mapa[0] = malloc(lin * col * sizeof(int)); // Vetor com os elementos da matriz.
	for (i = 1; i < lin; i++) // Ajuste de ponteiros para linha (i > 0).
		mapa[i] = (mapa[0] + (i * col));

	/* Preenchimento da matriz */
	for (i = 0; i < lin; i++) {
	fseek(am, 2, SEEK_CUR); // Pula para próxima linha (devido ao enter).
		for (j = 0; j < col; j++) {
			fscanf(am, "%c", &mapa[i][j]);
		}
	}			
	*lina = 1;
	*cola = 1;
	mapa[*lina][*cola] = '&'; // Mestre cuca.
	return mapa;
}

/* Responsável por imprimir o mapa */
void imp_mapa(int lin, int col, char *mapa[], char Pedido[], struct pilha *Bandeja, int Ponto) {
	int i, j;
	
	/* Impressão da Matriz */
	clear();
	refresh();
	for (i = 0; i < lin; i++) {
		printw("\n");
		for (j = 0; j < col; j++) {
			if (mapa[i][j] == '&')
				printw ("&"); 
			else
				printw("%c", mapa[i][j]);
		}
	}
	printw("\n");
	printw("Bandeja: %s\n", Bandeja->vetor);
	printw("Pedido:  %s\n", Pedido);
	printw("Pontuacao:  %d\n", Ponto);
	// VELHO, ARRUMA A DESEMPILHAÇÃO.
	refresh();
}

// 0 = Fica no lugar.
// 1 = Ok, pode andar.
// 2 = Fica no lugar, adiciona pedido/bandeja.

/* Verifica se é possível fazer o movimento em questão */
int verifica_jogada(int lina, int cola, int lin, int col, char *mapa[]) 
{
	/* Verificação se as coordenadas passadas são válidas */
	if (mapa[lina][cola] == '@')
		return 2;
	if (cola <= 0 || cola >= col || lina <= 0 || lina >= lin)
		return 0;
	/* Verificação se é passável ou não */
	else 
	{
		if (mapa[lina][cola] == ' ')
			return 1;
		else
			return 2;
	}
}

/* Função responsável por modificar minhas estruturas de dados */
int altera_struc(char fc, char Pedido[], struct pilha *bandeja) {
 	switch (fc) {
 		case '@':
 			if (verifica_pedido(Pedido, bandeja) == 1)
 				return 1;
 			break;

 		case 'H':
 			push(bandeja, 'H');
 			break;

 		case 'P':
 			push(bandeja, 'P');
 			break;

 		case 'S':
 			push(bandeja, 'S');
 			break;

 		case 'Q':
 			push(bandeja, 'Q');
 			break;

 		case 'F':
 			push(bandeja, 'F');
 			break;

 		case '#':
 			pop(bandeja);
 			break;

 		default:
 			break;
 	}
 	return 0;
}

/* Lê jogada e refaz o mapa. Já implementada para curses */
int jogada(int lin, int col, int *lina, int *cola, char *mapa[], char Pedido[], struct pilha *bandeja)
{
	int jgd, aux, aux2;
	aux2 = 0;

	/* Faz a jogada */
	jgd = getch();
	switch(jgd) 
	{

		case KEY_UP:
			aux = verifica_jogada(*lina - 1, *cola, lin, col, mapa);
			if (aux == 1) // Nota: Implementar a função "verifica_jogada".
			{
				mapa[*lina][*cola] = ' '; // Apaga casa atual.
				*lina = *lina - 1; // Mover "cursor".
				mapa[*lina][*cola] = '&'; // Atualiza chapeiro.
			}
			else 
			{
				if (aux == 2) {
					aux2 = altera_struc(mapa[*lina-1][*cola], Pedido, bandeja);
					if (aux2 == 1)
						return 3; // Game Over
					if (mapa[*lina - 1][*cola] == '@')
						return 2;
				}
			}
			break;

		case KEY_RIGHT:
			aux = verifica_jogada(*lina, *cola + 1, lin, col, mapa);
			if (aux == 1) // Nota: Implementar a função "verifica_jogada".
			{
				mapa[*lina][*cola] = ' '; // Apaga casa atual.
				*cola = *cola + 1; // Mover "cursor".
				mapa[*lina][*cola] = '&'; // Atualiza chapeiro.
			}
			else 
			{
				if (aux == 2)
					altera_struc(mapa[*lina][*cola+1], Pedido, bandeja);
			}
			break;

		case KEY_DOWN:
			aux = verifica_jogada(*lina + 1, *cola, lin, col, mapa);
			if (aux == 1) // Nota: Implementar a função "verifica_jogada".
			{
				mapa[*lina][*cola] = ' '; // Apaga casa atual.
				*lina = *lina + 1; // Mover "cursor".
				mapa[*lina][*cola] = '&'; // Atualiza chapeiro.
			}
			else 
			{
				if (aux == 2)
					altera_struc(mapa[*lina+1][*cola], Pedido, bandeja);
			}
			break;

		case KEY_LEFT:
			aux = verifica_jogada(*lina, *cola - 1, lin, col, mapa);
			if (aux == 1) // Nota: Implementar a função "verifica_jogada".
			{
				mapa[*lina][*cola] = ' '; // Apaga casa atual.
				*cola = *cola - 1; // Mover "cursor".
				mapa[*lina][*cola] = '&'; // Atualiza chapeiro.
			}
			else 
			{
				if (aux == 2)
					altera_struc(mapa[*lina][*cola-1], Pedido, bandeja);
			}
			break;

		case 'q':
			return 1;
		default: // Ignora teclas desconhecidas.
			break;
	}
	return 0;
}
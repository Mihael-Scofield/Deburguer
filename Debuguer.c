// Mihael Scofield de Azevedo GRR - 20182621.
// Eduardo Paim Filho GRR - 20182627
// Debuguer! Patrocinio de UFH (Universidade Federal do Hamburguer).

#include "includes.h" // Todos os includes estão aqui, afim de evitar problemas com declarações.

/* Inicializa ncurses (biblioteca gráfica) */
void ini_ncurses();

/* Faz a geração ALEATÓRIA de pedido */
void gera_pedidos(int i, char Pedido[]);

int main (int argc, char *argv[]) {
	int i, m, game,j;
	int lin, col, lina, cola; // Lina = linha atual.
	char **mapa, Pedido[22];
	struct pilha *bandeja;
	FILE *am; // Arquivo de mapa.

    //PlaySound(TEXT("OST"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	system("mplayer -loop 0 spongebob-trap-remix-krusty-krab.mp3 >/dev/null 2>/dev/null &");
	/* Inicialização de estruturas de dados */
	bandeja = ini_pilha(100);

	/* Carregamento de informações */
	le_coord(argc, argv, &lin, &col, &am); // Altero linha, coluna e am.
	mapa = gera_mapa(lin, col, &lina, &cola, am); //Altero linha e coluna atual.

	/* Preparação para iniciar a Deburgação */
	int Ponto = -1; // Pontuação atual, baseada nos indices de cada pedido.
	game = 1; // Não é um game over.
	i = 0; 
	j = 0;
	ini_ncurses();

	/* Deburguer propriamente dito */
	while (game == 1) {
		gera_pedidos(i, Pedido); // Baseado no mod, gera um pedido aleatório.
		Ponto += (j % 14) + 1; // Calcula pontuação do Burguer atual
		j = i; // Salva para prox. calculo.
		i += 3;
		m = 0; // Controlador de movimento.
		imp_mapa(lin, col, mapa, Pedido, bandeja, Ponto);

		while(m == 0) { // Movimentos ainda válidos.
			m = jogada(lin, col, &lina, &cola, mapa, Pedido, bandeja);
			if (m == 1)
				game = 0; // Pediu pra sair.
			if (m == 3)
				game = 2;
			imp_mapa(lin, col, mapa, Pedido, bandeja, Ponto);
		}
	}

	if (game == 2) {
		clear();
		printw("ERRROOOU! GAME OVER!\n");
		printw("Pontuacao final: %d", Ponto);
		refresh();
		sleep(5);
	}

	endwin();
	fclose(am);
	free(mapa);
	system("pkill mplayer >/dev/null 2>/dev/null & ");
	return 0;
}

/* Inicializa ncurses (biblioteca gráfica) */
void ini_ncurses() {
	initscr();
	raw();				
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
}

/* Faz a geração ALEATÓRIA de pedido */
void gera_pedidos(int i, char Pedido[]) 
{
	int j;
	for (j = 0; j < 22; j++){
		Pedido[j] = ' ';
	}

	i = i % 14;
	switch (i) {

		case 0 :
			strncpy(Pedido, "PSP", 22*sizeof(char));
			break;

		case 1 :
			strncpy(Pedido, "PHSP", 22*sizeof(char));			
			break;

		case 2 :
			strncpy(Pedido, "PHQP", 22*sizeof(char));			
			break;

		case 3 :
			strncpy(Pedido, "PQHQSP", 22*sizeof(char));			
			break;

		case 4 :
			strncpy(Pedido, "PSPF", 22*sizeof(char));
			break;

		case 5 :
			strncpy(Pedido, "PHSPF", 22*sizeof(char));
			break;

		case 6 :
			strncpy(Pedido, "PHQPF", 22*sizeof(char));
			break;

		case 7 :
			strncpy(Pedido, "PQHQSPF", 22*sizeof(char));
			break;

		case 8 :
			strncpy(Pedido, "PSPPSPF", 22*sizeof(char));		
			break;

		case 9 :
			strncpy(Pedido, "PHSPPHSPF", 22*sizeof(char));		
			break;

		case 10 :
			strncpy(Pedido, "PHQPPHSPF", 22*sizeof(char));		
			break;

		case 11 :
			strncpy(Pedido, "PHQPPQHQSPF", 22*sizeof(char));		
			break;

		case 12 :
			strncpy(Pedido, "PQHQSPPQHQSPF", 22*sizeof(char));		
			break;

		case 13 :
			strncpy(Pedido, "PQHQSPFPQHQSPFPQHQSPF", 22*sizeof(char));		
			break;

		default:
			break; 
	}
}
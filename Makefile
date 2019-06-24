#Makefile

CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lncurses
#LDLIBS = -lSDL2 -lSDL2_gfx -lm

objects = Debuguer.o operacoes_s.o mapa.o
arq = Debuguer.c operacoes_s.c mapa.c

OBJ_NAME = Deburguer

# Regra default
all: Debuguer

# Remove arquivos temporários
clean:
	-rm -f *~ *.o

# Remove tudo o que não for código-fonte original
purge: clean
	-rm -f Debuguer

Debuguer.o: Debuguer.c includes.h
	$(CC) $(CFLAGS) -c Debuguer.c

operacoes_s: operacoes_s.c operacoes_s.h includes.h
	$(CC) $(CFLAGS) -c operacoes_s.c

mapa.o: mapa.c mapa.h includes.h
	$(CC) $(CFLAGS) -c mapa.c
	
Debuguer: $(objects)
	$(CC) $(CFLAGS) $(arq) $(LDLIBS) -o $(OBJ_NAME)
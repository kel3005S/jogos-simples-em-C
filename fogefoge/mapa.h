#ifndef _MAPA_H_
#define _MAPA_H_

#define VAZIO '.'
#define PAREDE_H '-'
#define PAREDE_V '|'
#define HEROI '@'
#define FANTASMA 'F'
#define PILULA 'P'

struct smapa{

    char** mapa;
    int linhas;
    int colunas;
};

typedef struct smapa MAPA;

struct posição{

    int y;
    int x;
};

typedef struct posição POSIÇÃO;


int encontramapa(MAPA* m, POSIÇÃO* p, char c);
void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void copiamapa(MAPA* destino, MAPA* origem);
int podeandar(MAPA* m, char personagem, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);

#endif
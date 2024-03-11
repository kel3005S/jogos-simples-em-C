#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"


void copiamapa(MAPA* destino, MAPA* origem){

    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocamapa(destino);
    
    for(int i = 0; i < origem->linhas; i++){

        strcpy(destino->mapa[i], origem->mapa[i]);
    }
}

int ehparede(MAPA* m, int x, int y){

    return m->mapa[x][y] == PAREDE_H ||
        m->mapa[x][y] == PAREDE_V;
}

int ehpersonagem(MAPA* m, char personagem, int x, int y){

    return m->mapa[x][y] == personagem;
}

int ehvalida(MAPA* m, int x, int y){

    if(x >= m->linhas)
        return 0;
    if(y >= m->colunas)
        return 0;

    return 1;
}

int ehvazia(MAPA* m, int x, int y){

    return m->mapa[x][y] == VAZIO;
}

void alocamapa(MAPA* m){

    m->mapa = malloc(sizeof(char*) * m->linhas);
    for(int i = 0; i < m->linhas; i++){

        m->mapa[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

int encontramapa(MAPA* m, POSIÇÃO* p, char c){

    for(int i = 0; i < m->linhas; i++){

        for(int j = 0; j < m->colunas; j++){

            if(m->mapa[i][j] == c){

                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }

    return 0;
}

int podeandar(MAPA* m, char personagem, int x, int y){
    return
        ehvalida(m, x, y) && 
        !ehparede(m, x, y) &&
        !ehpersonagem(m, personagem, x, y);
}

void lemapa(MAPA* m){

    FILE* fmap;
    fmap = fopen("ffmap.txt", "r");
    
    if(fmap == 0){

        printf("mapas não encontrados");
        exit(1);
    }

    fscanf(fmap, "%d %d", &(m->linhas), &(m->colunas));

    alocamapa(m);

    for(int i = 0; i < 7; i++){

        fscanf(fmap, "%s", m->mapa[i]);
    }

    fclose(fmap);
}



void liberamapa(MAPA* m){

    for(int i = 0; i < m->linhas; i++){

        free(m->mapa[i]);
    }
    free(m->mapa);    
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){

    char personagem = m->mapa[xorigem][yorigem];
    m->mapa[xdestino][ydestino] = personagem;
    m->mapa[xorigem][yorigem] = '.';
}
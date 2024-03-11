#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"

char desenhofantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoheroi[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void desenhaparte(char desenho[4][7], int parte){

    printf("%s", desenho[parte]);
}

void desenhamapa(MAPA* m){
    for(int i = 0; i < m->linhas; i++){

        for(int parte = 0; parte < 4; parte++){

            for(int j = 0; j < m->colunas; j++){

                switch(m->mapa[i][j]){
                    case FANTASMA:
                        desenhaparte(desenhofantasma, parte);
                        break;

                    case HEROI:
                        desenhaparte(desenhoheroi, parte);
                        break;

                    case PILULA:
                        desenhaparte(desenhopilula, parte);
                        break;

                    case PAREDE_V:
                    case PAREDE_H:
                        desenhaparte(desenhoparede, parte);
                        break;

                    case VAZIO:
                        desenhaparte(desenhovazio, parte);
                        break;
                }
            }
            printf("\n");
        }
    }
}
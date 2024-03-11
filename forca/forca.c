#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[TAMANHO_MAXIMO];
char chutes[26];
int chutesdados = 0;

void titulo(){

    printf("*************************\n");
    printf("**    jogo da forca    **\n");
    printf("*************************\n\n");
}

void chuta(){

    char chute;
    scanf(" %c" , &chute); 

    chutes[chutesdados] = chute;
    chutesdados++; 
}

int jachutou(char letra){

    int achou = 0;

    for(int j = 0; j < chutesdados; j++){
               
        if(chutes[j] == letra){
                  
            achou = 1;
            break;
        }
    }

    return achou;

}

void desenhaforca(){

    int erros = chuteserrados();

    printf("  ____________      \n");
    printf("  |/         |      \n");
    printf("  |         %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf("  |         %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf("  |          %c     \n", (erros >= 2 ? '|' : ' '));
    printf("  |         %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf("  |                 \n");
    printf("__|_________________\n");

    for(int i = 0; i < strlen(palavrasecreta); i++){

        int achou = jachutou(palavrasecreta[i]);

        if (achou){
            printf("%c " , palavrasecreta[i]);
        }
        else{
        printf("_ ");
        }
    }
    printf("\n");

}

void adicionapalavra(){

    char quer;

    printf("voce gostaria de adicionar uma nova palavra? (S/N)\n");
    scanf(" %c", &quer);

    if(quer == 'S' || quer == 's'){

        char novapalavra[TAMANHO_MAXIMO];
        printf("qual palavra voce gostaria de adicionar\n");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("forcapalavras.txt" , "r+");

        if(f == 0) {
        printf("banco de dados nao encontrado\n\n");
        exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);

        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }

}

void selecionapalavra(){

    FILE* f;

    f = fopen("forcapalavras.txt", "r");
    if(f == 0) {
        printf("banco de dados nao encontrado\n\n");
        exit(1);
    }

    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);


    srand(time(0));
    int randomico = rand() % qtdpalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);

}

int chuteserrados(){

    int erros = 0;

    for(int i = 0; i < chutesdados; i++){

        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++){

            if(chutes[i] == palavrasecreta[j]){

                existe = 1;
                break;
            }

        }
        
        if(!existe) erros++;
    }
    return erros;

}

int nao_ganhou(){

    for(int i = 0; i < strlen(palavrasecreta); i++){

        if (!jachutou(palavrasecreta[i])){

            return 0;
            break;

        }   

    }
    return 1;
}

int nao_enforcou(){

    return chuteserrados() >= 5;

}

int main(){


    selecionapalavra();

    titulo();
    
    do{

        desenhaforca();
        
        chuta();
        

    }while(!nao_ganhou() && !nao_enforcou());

    if(nao_ganhou()){

        printf("parabens voce ganhou\n");

    }
    else if(nao_enforcou()){

        printf("voce perdeu tente novamente\n");

    }

    adicionapalavra();
}
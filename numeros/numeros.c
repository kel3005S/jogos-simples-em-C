#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Titulo Do Jogo
    printf("******************************************\n");
    printf("* bem vindo ao jogo de adivinhar numeros *\n");
    printf("******************************************\n");

    int randomconfig = time(0);
    srand (randomconfig);
    int numrandom = rand();
    
    
    int numsecret = numrandom % 100;
    int numplayer;
    int tentativas = 1;
    double points = 1000;
    int acertou = 0;

    int nivel;
    printf("qual nivel voce quer jogar?\n");
    printf("(1)facil (2)medio (3)dificil\n\n");
    printf("escolha: ");
    scanf("%d" , &nivel);
    
    int chances;

    switch(nivel){

        case 1:
            chances = 20;
            break;
        
        case 2:
            chances = 10;
            break;
        
        default:
            chances = 5;
            break;

    }

    for(int i = 1; i <= chances; i++){

        
        printf("qual e o seu chute?\n");
        scanf("%d" , &numplayer);
        if(numplayer < 0){

            printf("voce nao pode chutar numeros negativos\n");
            continue;
        }

        acertou = (numplayer == numsecret);
        int nummaior = (numplayer < numsecret);
 

        printf("#*#* tentativa %d *#*#\n\n" , tentativas);

        
        if(acertou){
            break;
        }

        else if(nummaior){

            printf("# o numero secreto e maior que %d # \n\n" , numplayer);
        } 

        else{

            printf("# o numero secreto e menor que %d # \n\n" , numplayer);
        }    
        
        tentativas++;

        double lostpoints = abs(numplayer - numsecret) / (double)2;
        points = points - lostpoints;

    }
    if(acertou){

        printf("voce acertou na tentativa %d\n" , tentativas);
        printf("sua pontuacao total: %.1f\n" , points);

    }
    else{

        printf("voce errou\n");
        printf("tente de novo!\n");

    }
    int finaliza = 0;
    printf("digite qualquer coisa para finalizar");
    scanf("%d" , &finaliza);
    
}   

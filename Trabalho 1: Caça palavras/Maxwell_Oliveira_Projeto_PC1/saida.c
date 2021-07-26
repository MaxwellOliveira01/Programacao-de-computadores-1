#include <stdio.h>
#include "saida.h"

int printa_resposta(char mapa[81][81], char palavra[], int tam, int i, int incremento_i, int j, int incremento_j){
    
    /*  Para evitar código repetitivo, essa função funcionará não importando a 
    direção em que ela se encontra. Sabendo o comprimento da palavra e as posições iniciais
    é possível encontrá-la apenas com o incremento das direções.
        Caso a palavra seja encontrada na: 
            Vertical, então o incremento é 1 na linha e 0 na coluna;
            Horizontal, então o incremento é 0 na linha e 1 na coluna;
            Diagonal principal, então o incremento é 1 na linha e 1 na coluna;
            Diagonal secunária, então o incremento é 1 na linha e -1 na coluna;
    */


    int x;
    printf("%s ", palavra);
    
    for(x = 0; x < tam-1; x++){

        //printa até o penúltimo caractere seguido de um espaço.

        printf("(%d,%d) ",i,j);
        i += incremento_i;
        j += incremento_j;
    }  


    //printa o ultimo caractere e a quebra de linha.
    printf("(%d,%d)\n",i,j);

    /*O retorno é para dizer que a palavra foi encontrada na função de busca, 
    então não precisa mais processá-la.*/

    return 1;

}
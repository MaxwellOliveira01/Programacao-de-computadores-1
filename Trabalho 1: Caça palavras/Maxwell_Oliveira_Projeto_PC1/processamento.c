#include <stdio.h>
#include <string.h>
#include "processamento.h"
#include "saida.h"

int horizontal(char mapa[81][81], char palavra[], int n){

    int tam = strlen(palavra), i, j, p;

    for(i = 0; i < n; i++){ //Passa por todas as linhas
        for(j = 0; j < n-tam+1; j++){   //Passa em todas as colunas tal que a palavra pode estar lá,
                                        // ou seja, procura em toda coluna tal que o restante da palavra possa estar seguido.
            
            for(p = 0; p < tam; p++){  //Aqui a função irá verificar se a palavra começa na posição [i][j]
                
                if(mapa[i][j+p] != palavra[p]){ // Na primeira letra diferente podemos parar
                    break;
                }

                else if(p == tam-1){ //Se chegou até aqui, então a palavra foi encontrada.
                    return printa_resposta(mapa, palavra, tam, i, 0, j, 1);
                }
            }

            for(p = 0; p < tam; p++){ 
                
                /* 
                    Essa pedaço é semelhante ao anterior.
                    É utilizado para ver a palavra está ao contrário,
                    funciona comparando a primeira letra com a última,
                    a segunda com a penúltima e etc.
                */

                if(mapa[i][j+p] != palavra[tam-1-p]){
                    break;
                }

                else if(p == tam-1){
                    return printa_resposta(mapa, palavra, tam, i, 0, j, 1);
                }
            }

        }
    }

    return 0;

}

int vertical(char mapa[81][81], char palavra[], int n){

    int i, j, p, tam = strlen(palavra);

    for(j = 0; j < n; j++){ //Percorre as colunas
        for(i = 0; i < n - tam +1; i++){ //Percorre toda linha tal que a palavra ainda caiba verticalmente no tabuleiro
            
            for(p = 0; p < tam; p++){ //Compara letra a letra e se for diferente já pode parar.

                if(mapa[i+p][j] != palavra[p] )
                    break;

                else if(p == tam-1) //Caso chegue até a ultima letra, então a palavra foi encontrada.
                    return printa_resposta(mapa,palavra,tam,i,1,j,0);

            }

            for(p = 0; p < tam; p++){

                /* 
                    Essa pedaço é semelhante ao anterior.
                    É utilizado para ver a palavra está ao contrário,
                    funciona comparando a primeira letra com a última,
                    a segunda com a penúltima e etc.
                */

                if(mapa[i+p][j] != palavra[tam-1-p] )
                    break;

                else if(p == tam-1)
                    return printa_resposta(mapa,palavra,tam,i,1,j,0);

            }

        }
    }

    return 0;

}

int diagonal_principal(char mapa[81][81], char palavra[],int n){

    int i, j, p, tam = strlen(palavra);

    /*Para a palavra estar nessa direção ela deve caber tanto na 
    vertical quanto na horizontal de uma posição qualquer do mapa*/

    for(i = 0; i < n - tam + 1; i++){ //Percorre as linhas em que a palavra cabe
        for(j = 0; j < n - tam + 1; j++){ //Percorre as colunas em que a palavra cabe

            for(p = 0; p < tam; p++){ //Confere se realmente a palavra está aqui
                if(mapa[i+p][j+p] != palavra[p]) //Na primeira diferença pode-se parar.
                    break;

                else if(p == tam-1) //Se chegou até aqui então a palavra foi encontrada.
                    return printa_resposta(mapa,palavra,tam,i,1,j,1);
                
            }

            for(p = 0; p < tam; p++){

                /*Verifica se a palavra começa na posição atual, porém estando ao contrário.
                Compara a primeira com a ultima, segunda com penultima, e etc*/

                if(mapa[i+p][j+p] != palavra[tam-1-p])
                    break;

                else if(p == tam-1)
                    return printa_resposta(mapa,palavra,tam,i,1,j,1);
                
            }

        }
    }

   return 0;

}

int diagonal_secundaria(char mapa[81][81], char palavra[], int n){

    int i, j, p, tam = strlen(palavra);

    /*Para a palavra estar nessa direção ela deve caber na 
    vertical de uma posição qualquer e caber atrás da coluna em que se procura*/

    for(i = 0; i < n - tam +1; i++){ //Linhas em que a palavra cabe
        for(j = tam-1; j < n; j++){ //Colunas em que a palavra cabe

            for(p = 0; p < tam; p++){ //Confere se encontrou a palavra.
                if(mapa[i+p][j-p] != palavra[p])
                    break;

                else if(p == tam-1)
                    return printa_resposta(mapa,palavra,tam,i,1,j,-1);
                
            }

            for(p = 0; p < tam; p++){

                /*Verifica se a palavra começa na posição atual, porém estando ao contrário.
                Compara a primeira com a ultima, segunda com penultima, e etc*/

                if(mapa[i+p][j-p] != palavra[tam-1-p])
                    break;

                else if(p == tam-1)
                    return printa_resposta(mapa,palavra,tam,i,1,j,-1);
                
            }

        }
    }

   return 0;

}

int busca(char mapa[81][81], char palavra[], int n){

/*
    Economia de processamento:
        Como a palavra aparecerá apenas em uma das direções, 
        então quando ela for encontrada não há necessidade de
        procurar nas outras. 
*/

    if(!vertical(mapa,palavra,n)) 
        if(!horizontal(mapa,palavra,n))
            if(!diagonal_principal(mapa,palavra,n))
                if(!diagonal_secundaria(mapa,palavra,n))
                    return 0;

    return 1;
}
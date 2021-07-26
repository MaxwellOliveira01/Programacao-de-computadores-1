#include <stdio.h>
#include <stdlib.h>

#include "saida.h"

void salva_output(int n, int m, char** mapa, FILE* out){

    /*Salva o mapa no arquivo out após o processamento.*/

    int i,j;
    char qr = '\n';
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            fwrite(&mapa[i][j],1,1,out);
        }
        fwrite(&qr,1,1,out);
    }
}

void mostra_mapa(int n, int m, char** arr){

    /*Printa o mapa na tela. Função criada com a intenção 
    de ser utilizada no processo de debug*/

    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mostra_visitados(int n, int m, int** arr){

    /*Printa visitados na tela. Função criada com a intenção 
    de ser utilizada no processo de debug*/

    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
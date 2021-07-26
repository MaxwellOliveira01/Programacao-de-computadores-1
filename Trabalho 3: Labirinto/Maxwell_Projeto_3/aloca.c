#include <stdio.h>
#include <stdlib.h>

#include "aloca.h"

void aloca_mem(int n, int m, char** mapa, int** visitado){

    /*Aloca dinamicamente a memória necessária para o algoritmo.*/

    int i;    
    for(i = 0; i < n; i++){
        mapa[i] = calloc(m, sizeof(char));
        visitado[i] = calloc(m, sizeof(int));
    }

}

void libera_mem(int n, int m, char** mapa, int** visitado){

    /*Libera toda a memória alocada pela função acima.*/

    int i;
    
    for(i = 0; i < n; i++){
        free(mapa[i]);
        free(visitado[i]);
    }

    free(mapa);
    free(visitado);
}
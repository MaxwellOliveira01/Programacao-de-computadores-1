#include <stdio.h>
#include <stdlib.h>

#include "aloca.h"
#include "leitura.h"
#include "processamento.h"
#include "saida.h"

int main(int argc, char* argv[]){

    /*Abre os arquivos com caminho em argv*/
    FILE* in = fopen(argv[1],"r");
    FILE* out = fopen(argv[2],"w");
    
    int n, m;
    fscanf(in,"%d %d",&n,&m);
    
    /*Declaração dinâmica do mapa e de uma matriz de visitados.
    O motivo de criar um 'visitados' está no módulo de processamento.*/

    char** mapa = calloc(n,sizeof(char *));
    int** visitado = calloc(n,sizeof(int *));

    /*Aloca a memória necessária para as matrizes*/
    aloca_mem(n,m,mapa,visitado);

    /*Realiza a leitura de dados do arquivo*/
    leitura(n,m,mapa,visitado,in);

    /*Processa a entrada*/
    processa(n,m,mapa,visitado,out);

    /*Libera a memória alocada*/
    libera_mem(n,m,mapa,visitado);

    /*Fecha os arquivos*/
    fclose(in);
    fclose(out);

    return 0;
}
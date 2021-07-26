#include <stdio.h>
#include <stdlib.h>

#include "leitura.h"

void leitura(int n, int m, char** mapa, int** visitado, FILE* in){

    /*Realiza a leitura dos dados do arquivo.*/
    int i,j;

    /*O quebra_linha foi declarado para receber as quebras de linhas
    após a leitura de cada linha, evitando que estas fiquem no mapa.*/

    char quebra_linha;

    for(i = 0; i < n; i++){
        fscanf(in,"%c",&quebra_linha);
        for(j = 0; j < m; j++){
            fscanf(in,"%c",&mapa[i][j]);

            /*visitado[i][j] será 1 se mapa[i][j] for uma parede.
            Em outro caso será 0.*/

            visitado[i][j] = (mapa[i][j] == '#');
        }
    }
}

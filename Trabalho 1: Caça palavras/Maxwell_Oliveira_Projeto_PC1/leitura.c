#include <stdio.h>
#include "leitura.h"

void leitura(int n, int m, char mapa[81][81], char palavra[11][81]){
    int i;

    for(i = 0; i < m; i++){
        scanf("%s",palavra[i]);
    }

    for(i = 0; i < n; i++){
        scanf("%s",mapa[i]);
    }


}
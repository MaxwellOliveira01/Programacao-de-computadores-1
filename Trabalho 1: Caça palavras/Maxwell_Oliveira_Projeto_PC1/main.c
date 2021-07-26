#include <stdio.h>
#include "leitura.h"
#include "processamento.h"
#include "saida.h"

#define MAXN 81
#define MAXM 11

int main(void){
    int n, m, i;
    char mapa[MAXN][MAXN], palavra[MAXM][MAXN];
    scanf("%d %d", &n, &m);

    //realiza a leitura do mapa e das palavras
    leitura(n,m,mapa,palavra);

    //Procura cada palavra dada no mapa
    for(i = 0; i < m; i++)
        busca(mapa,palavra[i],n);

}

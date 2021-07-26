#include <stdio.h>
#include <stdlib.h>

#include "processamento.h"
#include "saida.h"

int posi_valida(int n, int m, int ii, int jj){
    /*Retorna se a posição [ii][jj] é válida para acesso
    das matrizes mapa e visitados. Esta função poderia ser trocada 
    por um if na função de busca. Porém, optei uma maior organização do código.*/
    return (ii >= 0 && jj >= 0 && ii < n && jj < m);
}

void busca(int n, int m, char** mapa, int** visitado, int ii, int jj, int* finaliza, FILE* out, int di[], int dj[]){
    
    /*Realiza uma DFS para encontrar a saída.*/

    /*Primeiro caso base:
        Se finaliza for verdadeiro, então eu já encontrei a resposta. 
        Se visitado[ii][jj] for verdadeiro, então eu já processei esta posição
    Em ambos os casos processar esta célula neste momento é desnecessário.*/
    
    if( (*finaliza) || visitado[ii][jj] )
        return;

    /*Segundo caso base:
        Se ii for igual a n-1 e jj igual a m-2, então eu acabo
    de encontrar a saída do labirinto. Portanto, salvo o caminho
    encontrado, marco finaliza como verdadeiro e finalizo esta chamada.*/

    if(ii == n-1 && jj == m-2){
        (*finaliza) = 1;
        mapa[0][1] = '@';
        mapa[ii][jj] = '@';
        salva_output(n,m,mapa,out);
        return;
    }

    /*Desmarque a linha abaixo para ver como a função funciona graficamente.*/
    //mostra_mapa(n,m,mapa);

    /*Se esta chamada chegou até aqui, então é a primeira vez que alcanço esta célula.
    Portanto, marco visitado como verdadeiro para que o caso base 1 evite processar
    esta posição novamente.*/
    visitado[ii][jj] = 1;

    /*Declarando as variáveis necessárias para esta chamada.*/
    int iAt, jAt, p;
    char old_chr;

    for(p = 0; p < 4 && !(*finaliza); p++){

        /*Olha as 4 direções possíveis: baixo, direita, cima, esquerda
        e, caso a célula correspondente seja válida e ainda não tenha
        sido processada, então chama a função para ela.*/

        iAt = ii + di[p];
        jAt = jj + dj[p];

        if( posi_valida(n,m,iAt,jAt) && !visitado[iAt][jAt] ){
            /*Salva o caractere que está na posição*/
            old_chr = mapa[iAt][jAt];
            
            /*Marca que esta posição faz parte do caminho da resposta*/
            mapa[iAt][jAt] = '@';
            
            /*Processa a posição da direção correspondente segundo p*/
            busca(n, m, mapa, visitado, iAt, jAt, finaliza, out,di,dj);
            
            /*Se a resposta foi encontrada, então já foi salva no arquivo.
            Se não foi, então esta posição não faz parte dela. Portanto,
            deixa o caractere que estava e processa a próxima direção*/
            mapa[iAt][jAt] = old_chr;
        }
    }

}

void processa(int n, int m, char** mapa, int** visitados, FILE* out){
    
    /*Inicia a recursão da função busca*/

    /*Ok é uma variável que indicará quando o caminho foi encontrado*/
    int ok = 0;
    int* finaliza = &ok;

    /*Vetores que correspondem ao incremento para que uma
    posição [x][y] se mova para as 4 direções. Na ordem:
    baixo, direita, cima, esquerda.
    Foram declaradas aqui para que a recursão carregue
    apenas o ponteiro para cada uma, diminuindo a memória
    necessária.*/
    int di[] = {1,0,-1,0};
    int dj[] = {0,1,0,-1};

    busca(n,m,mapa,visitados,0,1,finaliza,out,di,dj);
}
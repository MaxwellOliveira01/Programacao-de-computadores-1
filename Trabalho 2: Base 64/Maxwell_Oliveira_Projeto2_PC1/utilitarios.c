#include "utilitarios.h"

int get_int_from_table(char t){
    /*dado caracter, retorna a posição dele na tabela*/
    char s[66] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=\0";
    int i;
    for(i = 0; i < 65; i++){
        if(t == s[i])
            return i;
    }
    //espero que nao chegue aqui
    return 0;
}

char get_char_from_table(int t){
    /*dada a posição retorna o char correspondente na tabela*/
    char s[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    return s[t];
}

void to_bin(char* ptr, int tam, unsigned int num){

    /*Passa o numero num para um binário de tamanho tam e 
    salva em ptr*/

    int i = 0, j = tam-1;
    for(i = 0; i < tam; i++)
        ptr[i] = '0';
    while(num > 0){
        if(num%2) ptr[j] = '1';
        num /= 2; j--;
    }
    ptr[tam] = '\0';
}

unsigned int bin_to_num(char ptr[], int t){

    /*Dado uma sequencia em binário em ptr de tamanho t,
    retorna o int correspondente*/

    int pot = 1;
    unsigned int val = 0;
    t--;
    for(; t >= 0; --t){
        val += pot * (ptr[t] == '1');
        pot *= 2;
    }
    return val;
}

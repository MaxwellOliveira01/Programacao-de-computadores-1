#include <stdio.h>
#include <stdlib.h>
#include "codificador.h"
#include "utilitarios.h"

void codifica(char *argv[]){
    FILE* in = fopen(argv[2], "rb");
    FILE* out = fopen(argv[3], "wb");
    
    int bytes_lidos, i = 0, j = 0, p = 0;
    unsigned int recebe_retorno;
    char bits[24+1], guarda[6+1], pad = '=', re;
    unsigned char recebe[3];
    char *ptr_8 = malloc(8+1);
    
    guarda[6] = '\0'; bits[24] = '\0';

    while(bytes_lidos = fread(&recebe, sizeof(char), 3, in), bytes_lidos){
        /*recebe a entrada, converte para binário de 8 bits
        e salva em bits[]*/
        for(i = 0; i < bytes_lidos; i++){
            to_bin(ptr_8,8,recebe[i]);
            for(j = 0; j < 8; j++)
                bits[p++] = ptr_8[j];
        }

        /*Caso necessite de de usar o pad, esse while completa
        os bits da entrada com 0*/
        while(p%6) bits[p++] = '0';

        //Iremos adicionar nos arquivos p/6 octectos
        for(i = 0; i < (p/6); i++){
            for(j = 0; j < 6; j++){
                guarda[j] = bits[6*i+j];
            }

            /* guarda recebe 6 bits. Após isso, temos que converter
            esse binário para decimal com a função bin_to_num e 
            consultar a tabela. Após a consulta, basta salvar esse byte.
            */
            recebe_retorno = bin_to_num(guarda,(unsigned int)6);
            re = get_char_from_table(recebe_retorno);
            fwrite(&re,1,1,out);
        }

        /*Esse for irá adicionar todos os pad's que forem necessários. */
        for(i = 0; (bytes_lidos+i)%3; i++)
            fwrite(&pad,1,1,out);
            
        p = 0;
    }
    fclose(in); fclose(out); free(ptr_8);
}

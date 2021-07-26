#include <stdio.h>
#include <stdlib.h>
#include "decodificador.h"
#include "utilitarios.h"

void decodifica(char *argv[]){
    FILE *in = fopen(argv[2],"rb");
    FILE *out = fopen(argv[3], "wb");
    int bytes_lidos = 0, i = 0, j = 0, p = 0, posi = 0, pads = 0;
    unsigned int temp;
    unsigned char recebe[4], re;
    char bits[24+1+8], guarda[8+1], bits_salva[24+1];
    char *ptr = malloc(8+1);

    bits[24+8]  = '\0';
    guarda[8] = '\0';
    bits_salva[24] = '\0';
    ptr[8] = '\0';

    //Para decodificar, lemos 4 bytes e transformamos em 3
    while(bytes_lidos = fread(&recebe, 1, 4, in), bytes_lidos){
            
        /*Transforma todos os char's que foram lidos na sua representação
        binária e os concatena no vetor bits*/
        
        for(i = 0; i < bytes_lidos; i++){
            pads += (recebe[i] == '=');
            to_bin(ptr,8,recebe[i]);
            for(j = 0; j < 8; j++)
                bits[p++] = ptr[j];
        }
        p = 0; posi = 0;

        /*A cada 8 bits lidos, transforma em decimal e confere
        o que está nessa posição da tabela, transforma em binário novamente
        e salva em bits_salva*/

        for(i = 0; i < 4; i++){
            for(j = 0; j < 8; j++){
                guarda[j] = bits[8*i+j];
            }
            
            temp = get_int_from_table(bin_to_num(guarda,8));
            to_bin(ptr,8,temp);

            //pego 8 bits, mas pra desfazer só preciso dos 6 ultimos
            for(j = 2; j < 8; j++){
                bits_salva[posi++] = ptr[j];
            } 
        }

        /*Agora temos 24 bits, basta separar em 3 grupos de 8,
        transformar em decimal e usar a tabela ascii pra ter um char. 
        Daí, salvamos esse char*/

        /*O ideal seria salvar 3 caracteres, porém quando se a entrada 
        possuir algum pad, isso não deve ser executado. O comando a seguir
        salva os bytes que não tenham vindo de um pad*/

        for(i = 0; i < 3 - pads; i++){
            for(j = 0; j < 8; j++){
                /*reutilizando o vetor 'guarda' para salvar os bits
                do que irá ser escrito*/
                guarda[j] = bits_salva[8*i+j];
            }

            temp = bin_to_num(guarda,8);
            re = temp;
            fwrite(&re,1,1,out);
        }

        p = 0; posi = 0;
    }

    fclose(in); fclose(out); free(ptr);

}
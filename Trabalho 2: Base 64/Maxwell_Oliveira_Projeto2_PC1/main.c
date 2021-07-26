#include <stdio.h>
#include <stdlib.h>
#include "codificador.h"
#include "decodificador.h"

int main(int argc, char *argv[]){
    if(argv[1][1] == 'c'){
        codifica(argv);
    } else {
        decodifica(argv);
    }
    return 0;
}
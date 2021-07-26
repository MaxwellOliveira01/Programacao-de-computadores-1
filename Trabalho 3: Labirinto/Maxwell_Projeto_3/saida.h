#ifndef SAIDA_H
#define SAIDA_H

#include <stdio.h>
#include <stdlib.h>

void salva_output(int n, int m, char** mapa, FILE* out);
void mostra_mapa(int n, int m, char** arr);
void mostra_visitados(int n, int m, int** arr);

#endif
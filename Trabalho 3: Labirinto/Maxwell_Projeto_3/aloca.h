#ifndef ALOCA_H
#define ALOCA_H

void aloca_mem(int n, int m, char** mapa, int** visitado);
void libera_mem(int n, int m, char** mapa, int** visitado);

#endif
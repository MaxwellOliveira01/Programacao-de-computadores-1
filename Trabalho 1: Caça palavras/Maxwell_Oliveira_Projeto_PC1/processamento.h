#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

int horizontal(char mapa[81][81], char palavra[], int n);
int vertical(char mapa[81][81], char palavra[], int n);
int diagonal_principal(char mapa[81][81], char palavra[],int n);
int diagonal_secundaria(char mapa[81][81], char palavra[], int n);
int busca(char mapa[81][81], char palavra[11], int n);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#ifndef QUICKSORT_H
#define QUICKSORT_H

typedef struct{
	int chave, posicao;
} TipoRegistro;

void Insertion (int *, int, int);
int Mediana (int *, int, int, int);
void QuickSortLista (TipoLista *,Apontador, Apontador);
void QuickSortVetor (int *, int, int);
void QuickSortMediana (int *, int, int);
void QuickSortInsertion (int *, int, int);
int Comparacao ();
int Copia ();

#endif
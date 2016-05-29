#include <stdio.h>
#include <stdlib.h>
#ifndef LISTA_H
#define LISTA_H

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
	Apontador Ant, Prox;
	int chave, posicao;
} Celula;

typedef struct {
	Apontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *);
int Vazia(TipoLista);
void PreencherLista (int,TipoLista *,int);
void Inserir (TipoLista *, int );
void TrocaNo (Apontador,Apontador);
void TrocaPosicao (Apontador,Apontador);
void EsvaziarLista (TipoLista *);

#endif
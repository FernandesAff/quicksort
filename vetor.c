#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

void PreencherVetor (int seed, int *vetor, int tam){
	int i, chave;

	srand(seed);
	for(i=0;i<tam;i++){
		chave=rand();
		vetor[i]=chave;
	}
}

void TrocaChave (int *vetor, int chave1, int chave2){
	int aux;

	aux=vetor[chave1];
	vetor[chave1]=vetor[chave2];
	vetor[chave2]=aux;
}
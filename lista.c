#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia (TipoLista *Lista){
	Apontador aux=(Apontador) malloc (sizeof(Celula));

	Lista->Primeiro=aux;
	Lista->Primeiro->Ant=NULL;
	Lista->Primeiro->Prox=NULL;
	Lista->Primeiro->posicao=0;
	Lista->Ultimo=Lista->Primeiro;
}

int Vazia (TipoLista Lista){/*Verifica se a lista esta vazia*/
	return (Lista.Primeiro==Lista.Ultimo);
}

void PreencherLista (int seed, TipoLista *Lista, int tam){
	int i, chave;

	srand(seed);
	for(i=0;i<tam;i++){
		chave=rand();
		Inserir(Lista,chave);
	}
}

void Inserir (TipoLista *Lista, int chave){
	Apontador novo;

	novo=(Apontador) malloc (sizeof(Celula));

	novo->chave=chave;
	novo->posicao=Lista->Ultimo->posicao+1;
	novo->Prox=NULL;
	novo->Ant=Lista->Ultimo;
	Lista->Ultimo->Prox=novo;
	Lista->Ultimo=Lista->Ultimo->Prox;
}

void TrocaNo (Apontador no1, Apontador no2){
	Apontador aux=(Apontador) malloc(sizeof(Celula));

	if(no1->Prox==no2){
		if(no1->Ant!=NULL)no1->Ant->Prox=no2;
		if(no2->Prox!=NULL)no2->Prox->Ant=no1;
		no2->Ant=no1->Ant;
		no1->Prox=no2->Prox;
		no1->Ant=no2;
		no2->Prox=no1;
	}
	else{
		if(no2->Prox==no1){
			if(no2->Ant!=NULL)no2->Ant->Prox=no1;
			if(no1->Prox!=NULL)no1->Prox->Ant=no2;
			no1->Ant=no2->Ant;
			no2->Prox=no1->Prox;
			no2->Ant=no1;
			no1->Prox=no2;
		}
		else{
			aux->Ant=no2->Ant;
			aux->Prox=no2->Prox;
			if(no2->Ant!=NULL)no2->Ant->Prox=no1;
			if(no2->Prox!=NULL)no2->Prox->Ant=no1;
			no2->Ant=no1->Ant;
			no2->Prox=no1->Prox;
			if(no1->Ant!=NULL)no1->Ant->Prox=no2;
			if(no1->Prox!=NULL)no1->Prox->Ant=no2;
			no1->Ant=aux->Ant;
			no1->Prox=aux->Prox;
		}
	}

	free(aux);
	aux=NULL;
}

void TrocaPosicao (Apontador no1, Apontador no2){
	int aux;

	aux=no2->posicao;
	no2->posicao=no1->posicao;
	no1->posicao=aux;
}

void ImprimirLista (TipoLista Lista){
	Apontador Atual=Lista.Primeiro->Prox;
	int i=1;

	while(Atual!=NULL){
		printf("%d) %d\n",Atual->posicao, Atual->chave);
		Atual=Atual->Prox;
	}
}
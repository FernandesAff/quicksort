#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "vetor.h"
#include "quicksort.h"

static int comp=0;
static int copia=0;

void Insertion (int *vetor, int esq, int dir){
	int i,j,aux;

	if(dir-esq<2)return;

	for(i=0;i<dir-esq;i++){
		aux=vetor[i];
		copia++;
		for(j=i;vetor[j-1]>aux && j>0;--j){
			vetor[j]=vetor[j-1];
			comp++;
			copia++;
		}
		vetor[j]=aux;
		copia++;
	}
}

int Mediana (int *vetor, int esq, int dir, int k){
	int i,j;
	TipoRegistro aux[k], aux2;

	if(dir==esq)return dir;
	if(dir-esq<k)k=dir-esq;

	for (i=0;i<k;i++){
		aux[i].posicao=esq+(rand()%(dir-esq));
		aux[i].chave=vetor[aux[i].posicao];
	}

	for(i=0;i<k;i++){
		aux2.posicao=aux[i].posicao;
		aux2.chave=aux[i].chave;
		for(j=i;aux[j-1].chave>aux2.chave && j>0;--j){
			aux[j].chave=aux[j-1].chave;
			aux[j].posicao=aux[j-1].posicao;
		}
		aux[j].chave=aux2.chave;
		aux[j].posicao=aux2.posicao;
	}
	return (aux[k/2].posicao);
}

void QuickSortLista (TipoLista *Lista, Apontador esq, Apontador dir){
	Apontador pivo, maior,menor,aux;

	pivo=esq;
	maior=esq->Prox;
	menor=dir;
	while (1){
		while(pivo->chave>maior->chave && maior->posicao<dir->posicao){
			maior=maior->Prox;
			comp++;
		}	
		while(pivo->chave<menor->chave && menor->posicao>esq->posicao){
			menor=menor->Ant;
			comp++;
		}	
		if(menor==maior || menor->Prox==maior)break;
		TrocaNo(maior,menor);
		TrocaPosicao(maior,menor);
		copia+=6;//dado que cada funcao acima faz 3 copias de registros.
		if(dir==menor)dir=maior;
		aux=maior;
		maior=menor;
		menor=aux;
	}
	TrocaNo (pivo,menor);
	TrocaPosicao(pivo,menor);
	copia+=6;
	if(dir==menor)dir=pivo;
	esq=menor;
	if(pivo->posicao>esq->posicao && pivo->Ant!=NULL){
		if(pivo->Ant->posicao>esq->posicao){
			QuickSortLista(Lista,esq,pivo->Ant);
		}
	}	
	if(pivo->posicao<dir->posicao && pivo->Prox!=NULL){
		if(pivo->Prox->posicao<dir->posicao){	
			QuickSortLista(Lista,pivo->Prox, dir);
		}
	}	
}

void QuickSortVetor (int *vetor, int esq, int dir){
	int pivo, maior,menor,aux;

	pivo=esq;
	maior=esq+1;
	menor=dir;
	while (1){
		while(vetor[pivo]>vetor[maior] && maior<dir){
			++maior;
			comp++;
		}	
		while(vetor[pivo]<vetor[menor] && menor>esq){
			--menor;
			comp++;
		}	
		if(menor==maior || menor+1==maior)break;
		TrocaChave(vetor,maior,menor);
		copia+=3;
	}
	TrocaChave (vetor,pivo,menor);
	copia+=3;
	pivo=menor;
	if(pivo>esq)QuickSortVetor(vetor,esq,pivo-1);
	if(pivo<dir)QuickSortVetor(vetor,pivo+1,dir);
}

void QuickSortMediana (int *vetor, int esq, int dir){
	int pivo, maior,menor,aux;

	pivo=Mediana(vetor,esq,dir,3);
	maior=esq;
	menor=dir;
	while (1){
		while(vetor[pivo]>=vetor[maior] && maior<dir){
			++maior;
			comp++;
		}	
		while(vetor[pivo]<=vetor[menor] && menor>esq){
			--menor;
			comp++;
		}	
		if(menor<=maior)break;
		TrocaChave(vetor,maior,menor);
		copia+=3;
		++maior;
		--menor;
	}
	TrocaChave (vetor,pivo,menor);
	copia+=3;
	pivo=menor;
	if(pivo>esq)QuickSortMediana(vetor,esq,pivo-1);
	if(pivo<dir)QuickSortMediana(vetor,pivo+1,dir);
}

void QuickSortInsertion (int *vetor, int esq, int dir){
	int pivo, maior,menor,aux;

	if(dir-esq>100){
		pivo=esq;
		maior=esq+1;
		menor=dir;
		while (1){
			while(vetor[pivo]>vetor[maior] && maior<dir){
				++maior;
				++comp;
			}	
			while(vetor[pivo]<vetor[menor] && menor>esq){
				--menor;
				++comp;
			}	
			if(menor==maior || menor+1==maior)break;
			TrocaChave(vetor,maior,menor);
			copia+=3;
		}
		TrocaChave (vetor,pivo,menor);
		copia+=3;
		pivo=menor;
		if(pivo>esq)QuickSortInsertion(vetor,esq,pivo-1);
		if(pivo<dir)QuickSortInsertion(vetor,pivo+1,dir);
	}	
	else Insertion(vetor,esq,dir);
}

int Comparacao (){
	return comp;
}

int Copia (){
	return copia;
}
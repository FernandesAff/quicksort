#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "lista.h"
#include "vetor.h"
#include "quicksort.h"

void show_help(char *name) {/*Mostra uma tela de ajuda ao usuario*/
    fprintf(stderr, "\
            [uso] %s <opcoes>\n\n\
            -s	SEMENTE    	recebe a semente que vai ser usada para gerar as chaves aleatorias.\n\
            -i	INPUT    	recebe o nome do arquivo de entrada.\n\
            -o	OUTPUT		recebe o nome do arquivo de saída.\n", name);
    exit(-1) ;
}

/*void Saida (char *saidaarq){
	FILE *fp;
}*/

void InterfaceVetor (int seed, int tam){
	int *vetor, tempo,comp,copia;
	struct timeval inicio, final;

	vetor=(int *)malloc(tam*sizeof(int));
	PreencherVetor(seed,vetor,tam);
	printf("Lista Inserida:\n\n");
	ImprimirVetor(vetor,tam);

	gettimeofday(&inicio, NULL);
	QuickSortVetor(vetor,0,tam-1);
	gettimeofday(&final, NULL);
	tempo=(int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	
	printf("\nLista Ordenada:\n\n");
	ImprimirVetor(vetor,tam);
	
	printf("\n%d milisegundos\n", tempo);
	printf("%d comparacoes\n", comp=Comparacao());
	printf("%d copias\n", copia=Copia());

}

void InterfaceLista (int seed, int tam){
	TipoLista Lista;
	int tempo,comp,copia;
	struct timeval inicio, final;

	FLVazia(&Lista);
	PreencherLista (seed,&Lista,tam);
	printf("Lista Inserida:\n\n");
	ImprimirLista (Lista);
	
	gettimeofday(&inicio, NULL);
	QuickSortLista(&Lista,Lista.Primeiro->Prox, Lista.Ultimo);
	gettimeofday(&final, NULL);
	tempo=(int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);

	printf("\nLista Ordenada:\n\n");
	ImprimirLista (Lista);

	printf("\n%d milisegundos\n", tempo);
	printf("%d comparacoes\n", comp=Comparacao());
	printf("%d copias\n", copia=Copia());
}

void InterfaceMediana(int seed, int tam){
	int *vetor,tempo,comp,copia;
	struct timeval inicio, final;

	vetor=(int *)malloc(tam*sizeof(int));
	PreencherVetor(seed,vetor,tam);
	printf("Lista Inserida:\n\n");
	ImprimirVetor(vetor,tam);

	gettimeofday(&inicio, NULL);
	QuickSortMediana(vetor,0,tam-1);
	gettimeofday(&final, NULL);
	tempo=(int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);

	printf("\nLista Ordenada:\n\n");
	ImprimirVetor(vetor,tam);

	printf("\n%d milisegundos\n", tempo);
	printf("%d comparacoes\n", comp=Comparacao());
	printf("%d copias\n", copia=Copia());
}

void InterfaceInsertion(int seed, int tam){
	int *vetor,tempo,comp,copia;
	struct timeval inicio, final;

	vetor=(int *)malloc(tam*sizeof(int));
	PreencherVetor(seed,vetor,tam);
	printf("Lista Inserida:\n\n");
	ImprimirVetor(vetor,tam);

	gettimeofday(&inicio, NULL);
	QuickSortInsertion(vetor,0,tam-1);
	gettimeofday(&final, NULL);
	tempo=(int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);

	printf("\nLista Ordenada:\n\n");
	ImprimirVetor(vetor,tam);

	printf("\n%d milisegundos\n", tempo);
	printf("%d comparacoes\n", comp=Comparacao());
	printf("%d copias\n", copia=Copia());
}

void ApresentarInterface(int seed, char *entradaarq, char *saidaarq){
	int tam,opcao,valn;
	FILE *fp;

	fp=fopen(entradaarq, "r+");
	fscanf(fp,"%d\n", &valn);

	printf("Escolha uma forma de ordenacao:\n1.Quicksort Recursivo/Escolha simples de pivo/Dados armazenados em um vetor\n2.Quicksort Recursivo/Escolha simples de pivo/Dados armazenados em uma lista\n3.Quicksort Recursivo/Escolha de pivo usando a mediana/Dados armazenados em um vetor\n4.Quicksort Recursivo + Insertion/Escolha simples de pivo/Dados armazenados em um vetor\n");
	scanf("%d", &opcao);

	while(opcao<1 || opcao>4){
		printf("Opcao invalida, insira novamente:\n");
		scanf("%d", &opcao);
	}

	switch(opcao){
		case 1:
			while((fscanf(fp,"%d\n", &tam))!=EOF){
				InterfaceVetor(seed, tam);
			}
			break;
		case 2:
			while((fscanf(fp,"%d\n", &tam))!=EOF){
				InterfaceLista(seed, tam);
			}
			break;
		case 3:
			while((fscanf(fp,"%d\n", &tam))!=EOF){
				InterfaceMediana(seed, tam);
			}
			break;
		case 4:
			while((fscanf(fp,"%d\n", &tam))!=EOF){
				InterfaceInsertion(seed, tam);
			}
			break;		
	}
	fclose(fp);
}
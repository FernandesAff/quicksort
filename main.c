#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "interface.h"

int main (int argc, char **argv){
	int opt, seed, tempo, opcao;
	char *entradaarq, *saidaarq;

	if ( argc < 3 ){/*Mostra as opcoes de execucao do programa no terminal*/
		printf("Numero insuficiente de opcoes, insira ao menos duas:\n\n" );
		show_help(argv[0]);
	}	

	while ((opt=getopt(argc, argv, "hs:i:o:"))>0){
		switch (opt){
			case 's':
				seed= atoi(optarg);
				break;
			case 'i':
				entradaarq=optarg;
				break;	
			case 'o':
				saidaarq= optarg;
				break;	
			default:
                fprintf(stderr, "Opcao invalida ou faltando argumento: '%c'\n", optopt) ;
                return -1 ;	
		}
	}

	ApresentarInterface(seed,entradaarq,saidaarq);

	return 0;
}
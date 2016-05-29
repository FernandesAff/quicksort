all:programa limpa

programa:main.o interface.o lista.o vetor.o quicksort.o
	gcc main.o interface.o lista.o vetor.o quicksort.o -o quick -g

main.o:main.c
	gcc -c main.c -g

interface.o:interface.c interface.h
	gcc -c interface.c -g	

quicksort.o: quicksort.c quicksort.h
	gcc -c quicksort.c -g

vetor.o: vetor.c vetor.h
	gcc -c vetor.c -g

lista.o:lista.c lista.h
	gcc -c lista.c -g

limpa:
	rm *.o
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAMANHO 10

int main(){
    int vetor[TAMANHO];
    
    srand(time(NULL));
    for (int i;i<TAMANHO;i++){
        vetor[i] = rand() % 100;
        printf("Numero sorteado: %d\n", vetor[i]);
    }
    return 1;
}
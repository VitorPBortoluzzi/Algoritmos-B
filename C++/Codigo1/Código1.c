#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char nome[100];
    printf("Insira seu nome: ");
    scanf("%s", nome);
    int idade;
    printf("Entre com sua Idade: ");
    scanf("%d", &idade);
    double sono = idade/3;
    printf("%s voce ja dormiu %.2f anos",nome,sono);
    return 1; 
}
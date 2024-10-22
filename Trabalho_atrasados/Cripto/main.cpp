#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#define TAM 100

using namespace std;

#include "metodos.h"

int main(){
    string Iarquivo = "cripto.csv";
    Criptocoin lista[TAM];
    int qtdCadastrados = 0;

    qtdCadastrados = lerArquivoBase(Iarquivo,lista,TAM);
    menu(lista,qtdCadastrados,TAM,Iarquivo);

    return 1;
}
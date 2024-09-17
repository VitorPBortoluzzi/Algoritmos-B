#include <iostream>
#include <cstdlib>
#include <string>
#include "manArquivos.h"

using namespace std;

int main(){
    cout << "Insira o nome do arquivo:";
    string nomeArquivo;
    cin >> nomeArquivo;
    cin.ignore();

    arquivoGlicemia(nomeArquivo, 2 , 200 , "21:18 - 16/09/2024");

    return 0;
}
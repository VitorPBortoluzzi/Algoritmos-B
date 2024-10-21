#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#define TAM 10
#define TAM2 15

#include "util.h"

using namespace std;

int main(){
    int vetor[TAM];
    int vetor1[TAM2];
    int vetor2[TAM2] = {};
    popularVetor(vetor,TAM);
    exibirVetor(vetor,TAM);
    cout << endl;

    cout << "Atividade 1 e 2:"<< endl;

    menorValor(vetor,TAM);
    cout << "\t" << menorValorR(vetor,TAM);
    cout << endl;
    cout << "Atividade 3 e 4:"<<endl;
    somaVetor(vetor,TAM);
    cout << "\t" << somaVetorR(vetor,TAM);
    cout << endl;
    cout << "Atividade 5:"<<endl;
    cout << "vetor antes: ";
    exibirVetor(vetor,TAM);
    cout << endl;
    cout << "vetor apos: ";
    par_to_zero(vetor,TAM);
    cout << endl;
    popularVetor(vetor1,TAM2);
    cout << "Vetor 1: "; exibirVetor(vetor1,TAM2); cout << endl;
    cout << "Vetor 2: "; exibirVetor(vetor2,TAM2); cout << endl;
    vetor1_to_vetor2(vetor1,TAM2,vetor2);
    cout << "Vetor 2: "; exibirVetor(vetor2,TAM2); cout << endl;

    return 1;
}
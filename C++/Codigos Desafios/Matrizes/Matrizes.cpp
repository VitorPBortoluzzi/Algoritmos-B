/*
Dado o código abaixo:
1) qual a soma dos elementos da matriz gerada?
2) qual a média dos elementos da matriz gerada?
3) qual o maior elemento da matriz gerada?
4) qual a soma dos elementos da diagonal principal da matriz gerada?
5) qual a soma dos elementos da primeira linha da matriz gerada?
6) qual a soma dos elementos da última coluna da matriz gerada?
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define TAMANHO 5

int main() {
    system("cls");
    int matriz[TAMANHO][TAMANHO];

    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = rand() % 100;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    //Soma dos elementos da matriz gerada
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            soma += matriz[i][j];
        }
    }
    cout << "Soma dos elementos da matriz gerada: " << soma << endl;

    int media = soma / (TAMANHO * TAMANHO);
    cout << "Media dos elementos da matriz gerada: " << media << endl;

    int maior = matriz[0][0];
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }
    cout << "Maior elemento da matriz gerada: " << maior << endl;

    int somaDiagonal = 0;
    for (int i = 0; i < TAMANHO; i++) {
        somaDiagonal += matriz[i][i];
    }
    cout << "Soma dos elementos da diagonal principal da matriz gerada: " << somaDiagonal << endl;

    int somaDiagonalSecundaria = 0;
    for (int i = 0; i < TAMANHO; i++) {
        somaDiagonalSecundaria += matriz[i][TAMANHO - 1 - i];
    }

    cout << "Soma dos elementos da diagonal secundaria da matriz gerada: " << somaDiagonalSecundaria << endl;

    int somaPrimeiraLinha = 0;
    for (int i = 0; i < TAMANHO; i++) {
        somaPrimeiraLinha += matriz[0][i];
    }
    cout << "Soma dos elementos da primeira linha da matriz gerada: " << somaPrimeiraLinha << endl;

    int somaLinhaMeio = 0;
    if (TAMANHO % 2 == 0) {
        cout << "A matriz nao possui linha do meio" << endl;
    } else{
        for (int i = 0; i < TAMANHO; i++) {
            somaLinhaMeio += matriz[TAMANHO / 2][i];
        }
    }
    cout << "Linha do meio: " << TAMANHO / 2 + 1 << endl;
    cout << "Soma dos elementos da linha do meio da matriz gerada: " << somaLinhaMeio << endl;

    int somaUltimaColuna = 0;
    for (int i = 0; i < TAMANHO; i++) {
        somaUltimaColuna += matriz[i][TAMANHO - 1];
    }
    cout << "Soma dos elementos da ultima coluna da matriz gerada: " << somaUltimaColuna << endl;

    return 1;
}
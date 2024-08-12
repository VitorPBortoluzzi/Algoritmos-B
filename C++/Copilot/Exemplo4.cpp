//Fazer um programa em C ou C++ que popule e mostre um vetor com números inteiros e aleatórios. 
//A quantidade de números deve ser igual ao tamanho do vetor inteiro definido. 
//Em seguida, o programa deve mostrar todos os números que aparecem mais de 2 vezes no vetor.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main(){
    system("cls");

    int tamanho;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    //cria vetor de inteiros
    vector<int> vetor(tamanho);

    srand(time(NULL));
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 10;
        cout << vetor[i] << " ";
    }
    cout << endl;

    int contaOcorrencia,numeroAnalisado;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] != -27) {
            numeroAnalisado = vetor[i];
            contaOcorrencia = 0;
            for (int j = 0; j < tamanho; j++) {
                if (numeroAnalisado == vetor[j]) {
                    contaOcorrencia++;
                    if (contaOcorrencia > 1) {
                        vetor[j] = -27;
                    }
                }
            }
            if (contaOcorrencia > 1){
                cout << vetor[i] << " aparece " << contaOcorrencia << " vezes\n";
            }
        }
    }

    return 0;
}
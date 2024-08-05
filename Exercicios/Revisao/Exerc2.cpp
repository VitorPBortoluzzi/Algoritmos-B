#include <iostream>
#include <vector>
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()

using namespace std;

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    int tamanho;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    // Cria um vetor de inteiros com o tamanho definido
    vector<int> vetor(tamanho);

    // Popula o vetor com números aleatórios entre 0 e 99
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = rand() % 100;  // Números aleatórios entre 0 e 99
    }

    // Cria vetores para armazenar números ímpares e pares
    vector<int> vetorImpar(tamanho, -1);
    vector<int> vetorPar(tamanho, -1);

    // Analisa os números no vetor original e copia para os vetores apropriados
    int indexImpar = 0, indexPar = 0;
    for (int i = 0; i < tamanho; ++i) {
        if (vetor[i] % 2 == 0) {
            vetorPar[indexPar++] = vetor[i];
        } else {
            vetorImpar[indexImpar++] = vetor[i];
        }
    }

    // Exibe os números no vetor original
    cout << "Números no vetor original: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Exibe os números no vetor de ímpares
    cout << "Números ímpares: ";
    for (int i = 0; i < indexImpar; ++i) {
        cout << vetorImpar[i] << " ";
    }
    cout << endl;

    // Exibe os números no vetor de pares
    cout << "Números pares: ";
    for (int i = 0; i < indexPar; ++i) {
        cout << vetorPar[i] << " ";
    }
    cout << endl;

    return 0;
}

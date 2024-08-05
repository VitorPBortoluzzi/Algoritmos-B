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
        vetor[i] = rand() % 10;  // Números aleatórios entre 0 e 99
    }
    int numero;
    cout << "Insira o numero que deseja verificar quantas vezes aparece: ";
    cin >> numero;

    int contador = 0;
    for (int i = 0; i< tamanho; i++){
        if(vetor[i] == numero){
            contador++;
        }
    }

    // Exibe os números no vetor
    cout << "Números no vetor: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    cout << "O numero: " << numero << " aparece " << contador << " vezes";

    return 0;
}
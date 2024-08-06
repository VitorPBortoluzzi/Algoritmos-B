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

    // Exibe os números no vetor
    cout << "Números no vetor: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    int contaOcorrencia, numeroAnalisado;
    vector<int> vetorRepetidos(tamanho);
    int iRepetidos;
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] != -27) {
            numeroAnalisado = vetor[i];
            contaOcorrencia = 0;
            for (int j = i; j < tamanho; j++)
            {
                if(numeroAnalisado == vetor[j]){
                    contaOcorrencia++;
                    if(contaOcorrencia > 1){
                        vetor[j] = -27;
                    }
                }
            }
            if (contaOcorrencia > 1){
                cout << vetor[i] << " Aparece "<< contaOcorrencia << " Vezes\n";
            }
        }
        // if (contaOcorrencia > 1){
        //     vetorRepetidos[++iRepetidos] = numeroAnalisado;
        //     iRepetidos++;
        // }
        
    }
    // cout << "Numeros Repetidos ....";
    // for (int i = 0; i < iRepetidos; i++)
    // {
    //     cout << vetorRepetidos[i];
    // }
    // cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()
#include <map>

using namespace std;

int main() {
    system("cls");
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

    // Cria um map para contar as ocorrências de cada número
    map<int, int> contador;
    for (int i = 0; i < tamanho; ++i) {
        contador[vetor[i]]++;
    }

    // Cria um vetor para armazenar números que aparecem mais de 2 vezes
    vector<int> vetorRepetidos;
    for (const auto &par : contador) {
        if (par.second > 2) {
            vetorRepetidos.push_back(par.first);
        }
    }

    // Exibe a contagem dos números que aparecem mais de 2 vezes
    cout << "Números que aparecem mais de 2 vezes e suas contagens: " << endl;
    for (int num : vetorRepetidos) {
        cout << "Número " << num << " aparece " << contador[num] << " vez(es)." << endl;
    }

    return 0;
}
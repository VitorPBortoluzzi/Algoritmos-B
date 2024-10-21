#include <iostream>
#include <ctime>

using namespace std;
int numeros[10];
void sorteio(int n){
    srand(time(NULL));
    for (int i=0;i<=n;i++){
        int numeroSorteado = rand() % 1000;
        numeros[i-1] = numeroSorteado;
    }
}

void resultado(int n){
    for (int j=0;j<=n;j++){
        cout << numeros[j-1] << "\n";
    }
}

int main(){
    // int numeros[10];
    // srand(time(NULL));
    // for (int i=0;i<=10;i++){
    //     int numeroSorteado = rand() % 1000;
    //     //cout << numeroSorteado << "\t" << i << "\n";
    //     numeros[i-1] = numeroSorteado;
    // }
    // for (int i=0;i<=10;i++){
    //     cout << numeros[i-1] << "\t";
    // }
    // return 0;
    int n_sorteios;
    cout << "Insira a quantidade de valores a serem sorteados: ";
    cin >> n_sorteios;
    sorteio(n_sorteios);
    resultado(n_sorteios);

    return 1;
}
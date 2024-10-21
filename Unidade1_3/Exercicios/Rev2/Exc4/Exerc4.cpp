 /**
 * 4 - Faça um programa que leia uma palavra qualquer e depois mostre apenas as vogais.
 */ 

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    string palavra;
    cout << "Digite uma palavra: ";
    cin >> palavra;

    cout << "Vogais: ";
    int vogalRepetida;
    for (char c : palavra) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            cout << c << " ";
        }

    }
    cout << endl;

    return 1;
}
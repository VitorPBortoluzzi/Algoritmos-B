#include <iostream>
#include <string>

using namespace std;

#include "metodos.h"

int main(){
    cout << "Exercicio 1" << endl;
    cout << "Digite um numero para verificar se e impar ou par: ";
    int a = 0;
    cin >> a;
    imparpar(a);

    cout << "Exercicio 2" << endl;
    cout << "Digite uma frase para separar os caracteres: ";
    string frase;
    cin.ignore();
    getline(cin, frase);
    fraseCaracter(frase);
    cout << "Frase: " << frase << endl;

    cout << "Exercicio 3" << endl;
    cout << "Digite dois numeros para verificar se o primeiro e multiplo do segundo: ";
    int b = 0;
    cin >> a >> b;
    multiplo_Y_N(a, b);

    cout << "Exercicio 4" << endl;
    cout << "Array" << endl;
    cout << "Digite um numero para converter para romanos(de 1 a 10): ";
    cin >> a;
    int_Romanos(a);
    cout << "Switch case" << endl;
    cout << "Digite um numero para converter para romanos(de 1 a 10): ";
    cin >> a;
    toRomanos(a);
    cout << "Fim dos exercicios" << endl;

    return 1;
}
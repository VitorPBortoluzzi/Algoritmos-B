#include <iostream>
#include <string>

using namespace std;
int main(){ 
    string nome;
    cout << "Insira seu nome: ";
    getline(cin,nome);
    int idade;
    cout << "Insira sua idade: ";
    cin >> idade;
    double sono = idade/3;
    cout << nome << ", voce ja dormiu aproximadamente: "<< sono << "Anos de seus" << idade << "Anos";
    return 0; 
}
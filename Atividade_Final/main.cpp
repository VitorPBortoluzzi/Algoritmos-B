// Construir um sistema para realizar inscrições (nome completo, email e matrícula), salvando os dados no arquivo inscricoes.csv. O sistema deve possuir um Menu como:

// 1 - Realizar inscrição 

// 2 - Listar inscritos 

// 3 - Registrar frequência (via matrícula) 

// 4 - Gerar relatório de presença 

// 5 - Sair Opção:

// No item 3, toda vez que uma matrícula é salva/persistida, os dados armazenados são: matricula;data;hora

// A interface que captura a frequência permanece em repetição até que a matrícula seja -27.


using namespace std;

#define TAM 100

#include "funcoes.h"


int main(){
    int opcao;
    do{
        cout << "1 - Realizar inscrição" << endl;
        cout << "2 - Listar inscritos" << endl;
        cout << "3 - Registrar frequência" << endl;
        cout << "4 - Gerar relatório de presença" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                realizarInscricao();
                break;
            case 2:
                listarInscritos();
                break;
            case 3:
                registrarFrequencia();
                break;
            case 4:
                gerarRelatorioPresenca();
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida" << endl;
        }
    }while(opcao != 5);

    return 0;
}	
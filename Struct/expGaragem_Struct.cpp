#include <iostream>
#include <string>
using namespace std;

#define TAM 5

typedef struct {
    string placa;
    string dataE;
    string horaE;
    string horaS;
    int tempoPermanencia;
    float valor;
} Garagem;

int timeToMinutes(const string& time) {
    // Split the string into hours and minutes
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    
    // Convert the time to total minutes
    return hours * 60 + minutes;
}

int main() {
    int opcao;
    Garagem lista[TAM];
    int totalVeiculos = 0;

    for (int i = 0; i < TAM; i++) {
        lista[i].placa = "";
        lista[i].dataE = "";
        lista[i].horaE = "";
        lista[i].horaS = "";
        lista[i].tempoPermanencia = 0;
        lista[i].valor = 0;
    }
    
    do {
        system("cls");
        cout << "Menu Garagem\n";
        cout << "1 - Entrada veiculo\n";
        cout << "2 - Saida veiculo\n";
        cout << "3 - Lista veiculos em garagem\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Entrando veiculo....\n";
            if (totalVeiculos == TAM) {
                cout << "Garagem lotada\n";
            } else {
                //Localizar vaga disponivel
                for (int i = 0; i < TAM; i++) {
                    if (lista[i].placa == "") {
                        cout << "Digite a placa: ";
                        cin >> lista[i].placa;
                        cout << "Digite a data de entrada(dd/mm/aa): ";
                        cin >> lista[i].dataE;
                        cout << "Digite a hora de entrada(hh:mm):";
                        cin >> lista[i].horaE;
                        totalVeiculos++;
                        break;
                    }
                //for (int i = 0; i< TAM && lista[i].placa != ""; i++) --> Alternativa de uma linha;
                }
            }
            break;
        case 2:
            cout << "Saindo veiculo....\n";
            if (totalVeiculos == 0) {
                cout << "Garagem vazia\n";
            } else {
                //desafio
                cout << "Digite a placa: ";
                string carroSaindo;
                cin >> carroSaindo;
                bool encontrado = false;
                for (int i = 0; i < TAM; i++){
                    if (lista[i].placa == carroSaindo){
                        encontrado = true;
                        cout << "Carro de placa: " << lista[i].placa << " saindo\n";
                        cout << "Data de Entrada: " << lista[i].dataE << endl;
                        cout << "Hora de Entrada: " << lista[i].horaE << endl;
                        cout << "Digite a hora de saida(hh:mm): ";
                        cin >> lista[i].horaS;
                        int horaE = timeToMinutes(lista[i].horaE);
                        int horaS = timeToMinutes(lista[i].horaS);
                        lista[i].tempoPermanencia = horaS - horaE;
                        if (lista[i].tempoPermanencia > 60){
                            cout << "Tempo de permanencia é de: " << lista[i].tempoPermanencia / 60 << " horas e " << lista[i].tempoPermanencia % 60 << " minutos" << endl;
                            cout << "Valor do minuto R$ 0,44" << endl;
                            lista[i].valor = lista[i].tempoPermanencia * 0.44;
                            cout << "Valor a pagar: R$ " << lista[i].valor << endl;
                        } else {
                            cout << "Tempo de permanencia é de: " << lista[i].tempoPermanencia << " minutos\n";
                            cout << "Valor do minuto R$ 0,44 " << endl;
                            lista[i].valor = lista[i].tempoPermanencia * 0.44;
                            cout << "Valor a pagar: R$ " << lista[i].valor << endl;
                        }

                        lista[i].placa = "";
                        lista[i].dataE = "";
                        lista[i].horaE = "";
                        lista[i].horaS = "";
                        lista[i].tempoPermanencia = 0;
                        lista[i].valor = 0;
                        totalVeiculos--;
                        break;
                    } if (!encontrado){
                        cout << "Veiculo nao encontrado\n";
                    }
                }
                
            }
            break;
        case 3:
            cout << "Listando garagem....\n";
            if (totalVeiculos == 0) {
                cout << "Garagem vazia\n";
            } else {
                string horaAtual;
                cout << "Hora atual: ";
                cin >> horaAtual;
                int horaA = timeToMinutes(horaAtual);
                for (int i = 0; i < totalVeiculos; i++) {
                    if (lista[i].placa != ""){
                        cout << "Veiculo: " << lista[i].placa << endl;
                        int horaE = timeToMinutes(lista[i].horaE);
                        int tempoPermanenciaA = horaA - horaE;
                        cout << "Tempo de permanencia é de: " << tempoPermanenciaA / 60 << " horas e " << tempoPermanenciaA % 60 << " minutos" << endl;
                    }
                }
            }
            break;
        case 4:
            cout << "Obrigado por usar o sistema\n";            
            break;
        
        default:
            cout << "Opcao invalida!\n";
            break;
        }
        system("pause");
    } while (opcao != 4);
    return 1;
}
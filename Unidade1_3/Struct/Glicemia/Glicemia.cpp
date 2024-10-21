#include <iostream>
#include <string>
#include <cstdlib>

#define TAM 5
using namespace std;

typedef struct {
    int medida = -1;
    string data;
    string hora;
} Glicemia;


int main() {
    Glicemia lista[TAM];
    int opcao;
    char letra;
    int total = 0;
    string data;
    string escolha;

    do {
        system("cls");
        cout << "MENU\n";
        cout << "1 - Inserir medida\n";
        cout << "2 - Listar medidas\n";
        cout << "3 - Consultar por data\n";
        cout << "4 - Sair\n";
        if(total == TAM){
            cout << "Armazenamento LOTADO \n";
            cout << "-27 - Limpar Armazenamento \n";
            }
        else if (total >= 0.9 * TAM)
        {
            cout << "Armazenamento quase lotado: 90% \n";
            cout << "-27 - Limpar Armazenamento \n";
        }
        
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        cout << "1 - Inserir medida\n";
            if (total == TAM){
                cout << "Unidade de armazenamento lotada \n";
                cout << "Limpe-a ou Substitua-a \n";
                break;
            if (total >= 0.9 * TAM)
            {
                cout << "Armazenamento quase lotado \n";
            }
            } else{
                cout << "Insira a medida glicemica: ";
                cin >> lista[total].medida;
                cout << "Insira a data (dd/mm/aa): ";
                cin >> lista[total].data;
                cout << "Insira a hora (hh:mm): ";
                cin >> lista[total].hora;
                total++;
                break;
            }
        case 2:
            cout << "Listar medidas glicemicas\n";
            for (int i = 0; i < TAM && lista[i].medida != -1; i++){
                cout << "Medicao: " << (i+1) << " Valor Glicemico: " << lista[i].medida << " Data: " << lista[i].data << " - " << lista[i].hora << endl;
            }
            break;
        case 3:
        cout << "3 - Consultar por data\n";
            if (total == 0){
                cout << "Armazenamento vazio \n";
            } else {
                bool encontrei = false;
                cout << "Informe a Data \n";
                cout << "OBS: No formato dd/mm/aa \n";
                cin >> data;
                for (int i = 0; i < TAM && lista[i].medida != -1; i++){
                    if (lista[i].data == data)
                    {
                    cout << "Medicao: " << (i+1) << " Valor Glicemico: " << lista[i].medida << " Data: " << lista[i].data << " - " << lista[i].hora << endl;
                    encontrei = true;
                    }
                }
                if (!encontrei){
                    cout << "Nenhum registro encontrado no armazenamento \n";
                }
            }
            
            break;
        case 4:
            cout << "Obrigado por usar o sistema\n";

            break;
    
        case -27:
            cout << "Deseja Limpar o Armazenamento: (Yes / No)\n";
            cout << "::";
            cin >> escolha;
            if (escolha == "Yes"){
                for(int i = 0; i < TAM;i++){
                    lista[i].medida = -1;
                    lista[i].data = "";
                    lista[i].hora = "";
                }
                total = 0;
                break;
            } else {
                cout << "Armazenamento total ocupado = " << total/TAM * 100 << "%\n";
                break;
            }
        default:
            cout << "Opcao invalida. Atencao\n";
            break;
        }
        system("pause");
        
    } while (opcao != 4);
    return 1;
}
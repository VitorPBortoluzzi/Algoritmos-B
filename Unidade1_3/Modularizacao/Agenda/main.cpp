#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define TAM 100

#include "funcao.h"

/*        
Agenda de Contatos
    1 - Inserir;
    2 - Remover;
    3 - Atualizar;
    4 - Listar;
    5 - Pesquisar;
    6 - Sair;
*/

int main(){
    Contato vetor[TAM];
    inicializar(vetor, TAM);
    int qtd_contatos = 0;
    int opcao;

    do{
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover" << endl;
        cout << "3 - Atualizar" << endl;
        cout << "4 - Listar" << endl;
        cout << "5 - Pesquisar" << endl;
        cout << "6 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch(opcao){
            case 1:
                cout << "Inserir" << endl;
                if (inserir(vetor, &qtd_contatos)){
                    cout << "Contato inserido com sucesso" << endl;
                    cout << qtd_contatos << endl;
                } else {
                    cout << "Agenda cheia" << endl;
                }
                break;

            case 2:
                cout << "Remover" << endl;
                if (remover(vetor, &qtd_contatos)){
                    cout << "Contato removido com sucesso" << endl;
                } else {
                    cout << "Contato não encontrado" << endl;
                }
                break;
            // case 3:
            //     cout << "Atualizar" << endl;
            //     if(atualizar(vetor, qtd_contatos)){
            //         cout << "Contato atualizado" << endl;
            //     } else {
            //         cout << "Contato não encontrado" << endl;
            //     }
            //     break;
            case 3:
                cout << "Atualizar" << endl;
                switch(atualizar(vetor, qtd_contatos)) {
                    case ATUALIZAR_SUCESSO:
                        cout << "Contato atualizado com sucesso" << endl;
                        break;
                    case ATUALIZAR_FALHA_AGENDA_VAZIA:
                        cout << "Agenda vazia" << endl;
                        break;
                    case ATUALIZAR_FALHA_CONTATO_NAO_ENCONTRADO:
                        cout << "Contato não encontrado" << endl;
                        break;
                    case ATUALIZAR_CANCELADO:
                        cout << "Atualização cancelada" << endl;
                        break;
                    default:
                        cout << "Erro desconhecido" << endl;
                        break;
                }
                break;
            case 4:
                cout << "Listar" << endl;
                if ( listar(vetor, qtd_contatos)){
                    cout << "Contatos Cadastrados:\n";
                } else {
                    cout << "Agenda vazia" << endl;
                }
                break;
            case 5:
                cout << "Pesquisar" << endl;
                if(pesquisar(vetor, qtd_contatos)){
                    cout << "Contato encontrado" << endl;
                } else {
                    cout << "Contato não encontrado" << endl;
                }
                break;
            case 6:
                cout << "Sair" << endl;
                cout << "Obrigado por usar a agenda" << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    }while (opcao != 6);
    return 1;
}

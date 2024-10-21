#include <iostream>
#include <string>
#include <vector>

#define TAM 4

using namespace std;

#include "Aluno_Struct.h" // Importação, ou uso de módulos via arquivo.

int main(){
    vector <Aluno> alunos(TAM);
    int opcao;
    int qtd_alunos = 0;
    int matricula;
    string nome;
    string email;
    bool encontrado;

    for (int i=0; i<TAM; i++){
        alunos[i].matricula = 0;
        alunos[i].nome = "";
        alunos[i].email = "";
    }
    
    do{
        system("cls");
        cout << "1 - Cadastrar Aluno" << endl;
        cout << "2 - Listar Alunos" << endl;
        cout << "3 - Sair" << endl;
        cout <<"Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Informe a matricula: ";
            cin >> matricula;
                
            encontrado = false;
            for (int i=0;i<TAM;i++){
                if(matricula == alunos[i].matricula){
                    cout << "!!Matricula ja cadastrada!!" << endl;
                    encontrado = true;
                    break;
                }
            }
            if(!encontrado){
                fflush(stdin);
                cout << "Digite o nome para cadastro: ";
                getline(cin,nome);

                fflush(stdin);  
                cout << "Digite o email de contato: ";
                getline(cin,email);

                alunos[qtd_alunos].matricula=matricula;
                alunos[qtd_alunos].nome=nome;
                alunos[qtd_alunos].email=email;
                qtd_alunos++;
            }
            break;
        case 2:
            cout << "Listar Alunos" << endl;
            if (qtd_alunos == 0)
            {
                cout << "Nao ha nenhum aluno cadastrado";
            } else {
                for (int i=0; i<TAM && alunos[i].matricula != 0;i++){
                    cout << "Aluno n: " << i+1 << endl;
                    cout << "Matricula: " << alunos[i].matricula << endl;
                    cout << "Nome: " << alunos[i].nome << endl;
                    cout << "Email: " << alunos[i].email << endl;
                } break;
            }
        
        case 3:
            cout << "Sair" << endl;
            break;

        default:
            cout << "Opção inválida" << endl;
        }
        system("pause");
    } while (opcao != 3);

    return 1;
}
// Construir um sistema para realizar inscricoes (nome completo, email e matrícula), salvando os dados no arquivo inscricoes.csv. O sistema deve possuir um Menu como:

// 1 - Realizar inscricão 

// 2 - Listar inscritos 

// 3 - Registrar frequência (via matrícula) 

// 4 - Gerar relatório de presenca 

// 5 - Sair Opcão:

// No item 3, toda vez que uma matrícula é salva/persistida, os dados armazenados são: matricula;data;hora

// A interface que captura a frequência permanece em repeticão até que a matrícula seja -27.
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

#include "obterHora.h"
#include "split.h"

typedef struct {
    string nome;
    string email;
    string matricula;
} Inscricao;

typedef struct {
    string matricula;
    string dataHora;
} Frequencia;

void realizarInscricao(){
    Inscricao inscricao;
    cout << "Nome completo: ";
    cin.ignore();
    getline(cin, inscricao.nome);
    cout << "Email: ";
    getline(cin, inscricao.email);
    cout << "Matrícula: ";
    getline(cin, inscricao.matricula);

    ofstream arquivo("inscricoes.csv", ios::app);
    if(arquivo.is_open()){
        arquivo << inscricao.nome << ";" << inscricao.email << ";" << inscricao.matricula << endl;
        arquivo.close();
    }else{
        cout << "Erro ao abrir o arquivo" << endl;
    }   
}

void listarInscritos(){
    ifstream arquivo("Banco/inscricoes.csv");
    string linha;

    cout << "Listagem de inscritos" << endl;
    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            cout << linha << endl;
        }
        arquivo.close();
    }else{
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

bool verificarMatricula(string& matricula){
    ifstream arquivoIns("Banco/inscricoes.csv", ios::in);
    string linha;
    string splits[3];

    if(arquivoIns.is_open()){
       while (getline(arquivoIns, linha)) {
        split(splits,linha,";");
        if (splits[2] == matricula){
            arquivoIns.close();
            return true;
            }
        }
    }
    else{
    arquivoIns.close();
    cout << "Erro ao abrir o arquivo" << endl;
    return false;
    }
}

void registrarFrequencia(){
    string matricula;
    ofstream arquivo("Banco/frequencia.csv", ios::app);

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    cout << "Registrar presenca (Digite -27 para sair)" << endl;
    while(true){
        cout << "Digite a matricula: ";
        cin >> matricula;
        if(matricula == "-27"){ break; }
        if (verificarMatricula(matricula) == true){
            string dataHora = obterDataHoraAtual();
            arquivo << matricula << ";" << dataHora << endl;
            cout << "Presenca registrada" << endl;
        } else {
            cout << "Matrícula não encontrada. Inscricão necessária" << endl;
        }
        cin.ignore();
    }
    arquivo.close();
}

void gerarRelatorioPresenca(){
    ifstream arquivo("Banco/frequencia.csv");
    string linha;

    ofstream Relatorio("Banco/relatorio.csv");
    Relatorio.is_open();
    cout << "Relatório de presenca" << endl;
    if(Relatorio.is_open()){
        if(arquivo.is_open()){
            while(getline(arquivo, linha)){
                Relatorio << linha << endl;

            }
            arquivo.close();
        }
    }else{
        cout << "Erro ao abrir o arquivo" << endl;
    }
    Relatorio.close();
}

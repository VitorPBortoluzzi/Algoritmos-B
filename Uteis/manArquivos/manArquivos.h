// Criar os códigos basicos de manipulação de arquivos como métodos.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

//================================================ Métodos Ler arquivo =================================================
void Arquivo_R(string nomeArquivo){
    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo, ios::in);   // ios::in para leitura do arquivo

    if (!procuradorArquivo.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }

    string linha;
    while (getline(procuradorArquivo, linha)){
        cout << linha << endl;
    }
    procuradorArquivo.close();
}



// ================================================ Métodos Escrever arquivo ================================================
void Arquivo_W(string nomeArquivo,string texto){    //criar arquivo e escrever.
    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo, ios::in);   // ios::in para leitura do arquivo

    if (procuradorArquivo.is_open()){
        cout << "Arquivo já existe" << endl;
        procuradorArquivo.close();
        exit(1);
    }
    procuradorArquivo.close();
    ofstream procuradorArquivoOut;
    procuradorArquivoOut.open(nomeArquivo, ios::out); // ios::out para escrita no arquivo


    if (!procuradorArquivoOut.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }

    procuradorArquivoOut << texto;
    procuradorArquivoOut.close();
}

void Arquivo_W_app(string nomeArquivo,string texto){
    ofstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo, ios::app); // ios::app para adicionar ao final do arquivo
    
    if (!procuradorArquivo.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }

    procuradorArquivo << "\n" <<texto;
}

void Arquivo_W_truc(string nomeArquivo,string texto){
    ofstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo, ios::trunc); // ios::trunc para limpar o arquivo e escrever
    
    if (!procuradorArquivo.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }

    procuradorArquivo << texto;
}


// ================================================ Métodos Com Formato I/O ================================================
// Input: #ID;valorGlicemia;Data/Hora

#include <sstream>
void Arquivo_R_formato(string nomeArquivo){ //Usando biblioteca <sstream> para separar os dados por ponto e vírgula
    // Formato do arquivo:
    // #ID;valorGlicemia;Data/Hora
    // 1;125;20:39 - 16/09/2024

    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo, ios::in);   // ios::in para leitura do arquivo
    if (!procuradorArquivo.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }
    int Id;
    int valorGlicemia;
    string dataHora;
    string linha;

    getline(procuradorArquivo, linha);

    while(getline(procuradorArquivo,linha)){
        istringstream iss(linha);
        string idStr, valorGlicemiaStr;

        // Lê o ID, valorGlicemia e Data/Hora usando ponto e vírgula como delimitador
        getline(iss, idStr, ';'); // Lê até o ponto e vírgula
        getline(iss, valorGlicemiaStr, ';'); // Lê até o ponto e vírgula
        getline(iss, dataHora); // Lê o resto da linha

        Id = stoi(idStr);
        valorGlicemia = stoi(valorGlicemiaStr);
        cout << "ID: " << Id << "\tValor Glicemia: " << valorGlicemia << "\tData/Hora: " << dataHora << endl;

        procuradorArquivo.close();
    }


}

#include "split.h"
void Arquivo_R_formato_strip(string nomeArquivo){ //Usando a função split para separar os dados por ponto e vírgula
    // Formato do arquivo:
    // #ID;valorGlicemia;Data/Hora
    // 1;125;20:39 - 16/09/2024

    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo, ios::in);   // ios::in para leitura do arquivo
    if (!procuradorArquivo.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }
    string linha;
    getline(procuradorArquivo, linha); // Pula a primeira linha
    while(getline(procuradorArquivo,linha)){
        string vetor[3];
        split(vetor, linha, ";");   // Função split definida em split.h (vetor, string, delimitador)
        cout << "ID: " << vetor[0] << "\tValor Glicemia: " << vetor[1] << "\tData/Hora: " << vetor[2] << endl;
    }
    procuradorArquivo.close();
}
//==========================================================================================================================
// Output: #ID;valorGlicemia;Data/Hora

void arquivoGlicemia(string nomeArquivo, int id, int valorGlicemia, string dataHora){

    // Se não existente criar o arquivo com cabeçalho:#ID;valorGlicemia;Data/Hora
    ifstream procuradorArquivo; 
    procuradorArquivo.open(nomeArquivo, ios::in);   // ios::in para leitura do arquivo
    if (!procuradorArquivo.is_open()){
        ofstream procuradorArquivoOut;
        procuradorArquivoOut.open(nomeArquivo, ios::out); // ios::out para escrita no arquivo
        procuradorArquivoOut << "#ID;valorGlicemia;Data/Hora" << endl;
        procuradorArquivoOut.close();
        procuradorArquivoOut.open(nomeArquivo, ios::app); // ios::app para adicionar ao final do arquivo
        procuradorArquivoOut << id << ";" << valorGlicemia << ";" << dataHora << endl;
        procuradorArquivoOut.close();
    }    
    else{
        procuradorArquivo.close();
        ofstream procuradorArquivoOut;
        procuradorArquivoOut.open(nomeArquivo, ios::app); // ios::app para adicionar ao final do arquivo
        procuradorArquivoOut << id << ";" << valorGlicemia << ";" << dataHora << endl;
        procuradorArquivoOut.close();
    }

}
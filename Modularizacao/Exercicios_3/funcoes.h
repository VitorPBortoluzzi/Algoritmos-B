#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

#include "obterHora.h"

enum TipoCerveja {
    PILSEN,
    IPA,
    APA,
    WEISS,
    NUM_TIPOS
};

struct Degustacao {
    string nomeDegustador;
    TipoCerveja tipoCerveja;
    string fabricante;
    float nota;
    string dataHora;
};

string tipoCervejaParaString(TipoCerveja tipo) {
    switch (tipo) {
        case PILSEN: return "Pilsen";
        case IPA: return "IPA";
        case APA: return "APA";
        case WEISS: return "Weiss";
        default: return "Tipo inválido";
    }
}

void cadastrarDegustacao(vector<Degustacao>& degustacoes) {
    Degustacao novaDegustacao;
    cout << "Nome do degustador: ";
    getline(cin, novaDegustacao.nomeDegustador);

    int tipoEscolhido;
    cout << "Selecione o tipo da cerveja:\n";
    cout << "0 - Pilsen\n1 - IPA\n2 - APA\n3 - Weiss\n";
    cout << "Opção: ";
    cin >> tipoEscolhido;
    cin.ignore();

    if (tipoEscolhido >= 0 && tipoEscolhido < NUM_TIPOS) {
        novaDegustacao.tipoCerveja = static_cast<TipoCerveja>(tipoEscolhido);
    } else {
        cout << "Tipo de cerveja inválido. Usando Pilsen como padrão.\n";
        novaDegustacao.tipoCerveja = PILSEN;
    }

    cout << "Fabricante da cerveja: ";
    getline(cin, novaDegustacao.fabricante);
    cout << "Nota (0 a 5): ";
    cin >> novaDegustacao.nota;
    cin.ignore();
    novaDegustacao.dataHora = obterDataHoraAtual();

    degustacoes.push_back(novaDegustacao); // push_back é um método da classe vector da biblioteca padrão do C++. Ele é usado para adicionar um novo elemento ao final do vetor. Essa operação aumenta o tamanho do vetor em 1 e coloca o novo elemento na última posição.
    cout << "Degustação cadastrada com sucesso!\n";
}

void listarDegustacoes(const vector<Degustacao>& degustacoes) {
    if (degustacoes.empty()) {
        cout << "Nenhuma degustação cadastrada.\n";
        return;
    }
    for (const auto& degustacao : degustacoes) {
        cout << "Degustador: " << degustacao.nomeDegustador
             << ", Tipo: " << tipoCervejaParaString(degustacao.tipoCerveja)
             << ", Fabricante: " << degustacao.fabricante
             << ", Nota: " << degustacao.nota
             << ", Data e Hora: " << degustacao.dataHora << "\n";
    }
}

// void pesquisarPorTipoCerveja(const vector<Degustacao>& degustacoes) {
//     string tipo;
//     cout << "Digite o tipo de cerveja para pesquisar: ";
//     getline(cin, tipo);

//     vector<Degustacao> resultados;
//     for (const auto& degustacao : degustacoes) {
//         if (tipoCervejaParaString(degustacao.tipoCerveja) == tipo) {
//             resultados.push_back(degustacao);
//         }
//     }

//     if (resultados.empty()) {
//         cout << "Nenhuma degustação encontrada para o tipo " << tipo << ".\n";
//         return;
//     }

//     // Ordena as degustações por nota em ordem decrescente
//     sort(resultados.begin(), resultados.end(), [](const Degustacao& a, const Degustacao& b) {
//         return a.nota > b.nota;
//     });

//     cout << "Degustações do tipo " << tipo << ":\n";
//     for (const auto& degustacao : resultados) {
//         cout << "Degustador: " << degustacao.nomeDegustador
//              << ", Nota: " << degustacao.nota
//              << ", Data e Hora: " << degustacao.dataHora << "\n";
//     }
// }

void pesquisarPorTipoCerveja(const vector<Degustacao>& degustacoes) {
    // Exibe as opções de tipos de cerveja
    cout << "Selecione o tipo de cerveja para pesquisar:\n";
    cout << "0 - Pilsen\n1 - IPA\n2 - APA\n3 - Weiss\n";
    cout << "Opção: ";

    int tipoEscolhido;
    cin >> tipoEscolhido;
    cin.ignore(); // Limpa o buffer do cin

    if (tipoEscolhido < 0 || tipoEscolhido >= NUM_TIPOS) {
        cout << "Tipo de cerveja inválido.\n";
        return;
    }

    TipoCerveja tipoSelecionado = static_cast<TipoCerveja>(tipoEscolhido);

    vector<Degustacao> resultados;
    for (const auto& degustacao : degustacoes) {
        if (degustacao.tipoCerveja == tipoSelecionado) {
            resultados.push_back(degustacao);
        }
    }

    if (resultados.empty()) {
        cout << "Nenhuma degustação encontrada para o tipo " << tipoCervejaParaString(tipoSelecionado) << ".\n";
        return;
    }

    // Ordena as degustações por nota em ordem decrescente
    sort(resultados.begin(), resultados.end(), [](const Degustacao& a, const Degustacao& b) {
        return a.nota > b.nota;
    });

    cout << "Degustações do tipo " << tipoCervejaParaString(tipoSelecionado) << ":\n";
    for (const auto& degustacao : resultados) {
        cout << "Degustador: " << degustacao.nomeDegustador
             << ", Nota: " << degustacao.nota
             << ", Data e Hora: " << degustacao.dataHora << "\n";
    }
}

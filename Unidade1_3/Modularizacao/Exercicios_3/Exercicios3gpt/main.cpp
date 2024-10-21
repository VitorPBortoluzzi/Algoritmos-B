#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Enum para tipos de cerveja
enum TipoCerveja {
    PILSEN,
    IPA,
    APA,
    WEISS,
    NUM_TIPOS // Contador de tipos, útil para validação
};

// Struct para degustação
struct Degustacao {
    string nomeDegustador;
    TipoCerveja tipoCerveja;
    string fabricante;
    float nota;
    string dataHora;
};

// Função para converter o enum para string
string tipoCervejaParaString(TipoCerveja tipo) {
    switch (tipo) {
        case PILSEN: return "Pilsen";
        case IPA: return "IPA";
        case APA: return "APA";
        case WEISS: return "Weiss";
        default: return "Tipo inválido";
    }
}

// Função para obter a data e hora atual
string obterDataHoraAtual() {
    time_t now = time(0);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}

// Função para cadastrar degustação
void cadastrarDegustacao(vector<Degustacao>& degustacoes) {
    Degustacao novaDegustacao;
    cout << "Nome do degustador: ";
    getline(cin, novaDegustacao.nomeDegustador);

    int tipoEscolhido;
    cout << "Selecione o tipo da cerveja:\n";
    cout << "0 - Pilsen\n1 - IPA\n2 - APA\n3 - Weiss\n";
    cout << "Opção: ";
    cin >> tipoEscolhido;
    cin.ignore(); // Limpa o buffer do cin

    if (tipoEscolhido >= 0 && tipoEscolhido < NUM_TIPOS) {
        novaDegustacao.tipoCerveja = static_cast<TipoCerveja>(tipoEscolhido);
    } else {
        cout << "Tipo de cerveja inválido. Usando Pilsen como padrão.\n";
        novaDegustacao.tipoCerveja = PILSEN; // Valor padrão
    }

    cout << "Fabricante da cerveja: ";
    getline(cin, novaDegustacao.fabricante);
    cout << "Nota (0 a 5): ";
    cin >> novaDegustacao.nota;
    cin.ignore(); // Limpa o buffer do cin
    novaDegustacao.dataHora = obterDataHoraAtual();

    degustacoes.push_back(novaDegustacao);
    cout << "Degustação cadastrada com sucesso!\n";
}

// Função para listar degustações
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

// Função para pesquisar por tipo de cerveja
void pesquisarPorTipoCerveja(const vector<Degustacao>& degustacoes) {
    string tipo;
    cout << "Digite o tipo de cerveja para pesquisar: ";
    getline(cin, tipo);

    vector<Degustacao> resultados;
    for (const auto& degustacao : degustacoes) {
        if (tipoCervejaParaString(degustacao.tipoCerveja) == tipo) {
            resultados.push_back(degustacao);
        }
    }

    if (resultados.empty()) {
        cout << "Nenhuma degustação encontrada para o tipo " << tipo << ".\n";
        return;
    }

    // Ordena as degustações por nota em ordem decrescente
    sort(resultados.begin(), resultados.end(), [](const Degustacao& a, const Degustacao& b) {
        return a.nota > b.nota;
    });

    cout << "Degustações do tipo " << tipo << ":\n";
    for (const auto& degustacao : resultados) {
        cout << "Degustador: " << degustacao.nomeDegustador
             << ", Nota: " << degustacao.nota
             << ", Data e Hora: " << degustacao.dataHora << "\n";
    }
}

int main() {
    vector<Degustacao> degustacoes;
    int opcao;

    do {
        cout << "\nMenu:\n"
             << "1 - Cadastrar degustação\n"
             << "2 - Listar degustações\n"
             << "3 - Pesquisar por tipo de cerveja\n"
             << "4 - Sair\n"
             << "Opção: ";
        cin >> opcao;
        cin.ignore(); // Limpa o buffer do cin

        switch (opcao) {
            case 1:
                cadastrarDegustacao(degustacoes);
                break;
            case 2:
                listarDegustacoes(degustacoes);
                break;
            case 3:
                pesquisarPorTipoCerveja(degustacoes);
                break;
            case 4:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 4);

    return 0;
}

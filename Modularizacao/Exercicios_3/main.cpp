#include "funcoes.h"

using namespace std;

int main() {
    vector<Degustacao> degustacoes;
    int opcao;

    do {
        cout << "\nMenu:\n"
             << "1 - Cadastrar degustacao\n"
             << "2 - Listar degustacoes\n"
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
                cout << "Opção invhalida. Tente novamente.\n";
                break;
        }
    } while (opcao != 4);

    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>  // Para std::setprecision

using namespace std;

void formatDouble(double value, string &formatted) {
    formatted = to_string(value);
    // Remove os zeros à direita e o ponto decimal, se necessário
    formatted.erase(formatted.find_last_not_of('0') + 1, string::npos);
    if (formatted.back() == '.') {
        formatted.pop_back();
    }
}

int main() {
    const int numFuncionarios = 5;
    struct Funcionario {
        string codigo;
        double salarioAtual;
    };

    Funcionario funcionarios[numFuncionarios] = {
        {"F001", 9500.00},
        {"F002", 15000.00},
        {"F003", 28000.00},
        {"F004", 12000.00},
        {"F005", 5000.00}
    };

    cout << fixed << setprecision(2);  // Define a precisão para 2 casas decimais

    for (int i = 0; i < numFuncionarios; ++i) {
        double salarioAtual = funcionarios[i].salarioAtual;
        double reajuste;
        double salarioReajustado;
        double porcentagemReajuste;

        // Calcula o reajuste com base no salário
        if (salarioAtual < 10000) {
            reajuste = salarioAtual * 0.55;
            porcentagemReajuste = 55.0;
        } else if (salarioAtual >= 10000 && salarioAtual <= 25000) {
            reajuste = salarioAtual * 0.30;
            porcentagemReajuste = 30.0;
        } else {
            reajuste = salarioAtual * 0.20;
            porcentagemReajuste = 20.0;
        }

        // Calcula o salário reajustado
        salarioReajustado = salarioAtual + reajuste;

        // Formata os resultados para exibição
        string salarioAtualFormatted, reajusteFormatted, salarioReajustadoFormatted;
        formatDouble(salarioAtual, salarioAtualFormatted);
        formatDouble(reajuste, reajusteFormatted);
        formatDouble(salarioReajustado, salarioReajustadoFormatted);

        // Imprime os resultados na tela
        cout << "Código do Funcionário: " << funcionarios[i].codigo 
             << " | Salário atual: R$ " << salarioAtualFormatted 
             << " | Reajuste: R$ " << reajusteFormatted << " (" << porcentagemReajuste << "%)" 
             << " | Salário reajustado: R$ " << salarioReajustadoFormatted << endl;
    }

    return 0;
}

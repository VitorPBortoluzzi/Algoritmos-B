 /**
 * 3 - Escreva um algoritmo para calcular o reajuste salarial de uma empresa que possui 1000 
 * funcionários, de acordo com os seguintes critérios:
 *	• os funcionários com salário inferior a 10.000 devem receber 55% de reajuste
 *	• os funcionários com salário entre 10.000 e 25.000 devem receber 30% de reajuste.
 *	• os funcionários com salário acima de 25.000 devem receber 20% de reajuste.
 */ 

#include <iostream>
#include <string>
#include <cstdio>  // Para snprintf

using namespace std;

void formatDouble(double value, string &formatted) {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%.2f", value);
    formatted = buffer;
}

int main() {
    // Abre o arquivo de entrada e saída
    FILE *infile = fopen("funcionarios.txt", "r");
    FILE *outfile = fopen("resultados.txt", "w");
    
    if (infile == nullptr) {
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }

    if (outfile == nullptr) {
        cerr << "Erro ao abrir o arquivo de saída!" << endl;
        fclose(infile);
        return 1;
    }

    double salario_atual;
    double reajuste;
    double salario_reajustado;
    double porcentagem_reajuste;
    char linha[256];  // Buffer para armazenar a linha do arquivo

    // Processa cada linha do arquivo
    while (fgets(linha, sizeof(linha), infile)) {
        string linha_str(linha);
        size_t pos = 0;
        string cod_funcionario, salario_atual_str, total_de_vendas_str;

        // Lê o código do funcionário
        pos = linha_str.find(';');
        cod_funcionario = linha_str.substr(0, pos);
        cod_funcionario = cod_funcionario.substr(cod_funcionario.find(':') + 1);
        linha_str.erase(0, pos + 1);

        // Lê o salário atual
        pos = linha_str.find(';');
        salario_atual_str = linha_str.substr(0, pos);
        salario_atual_str = salario_atual_str.substr(salario_atual_str.find(':') + 1);
        salario_atual = stod(salario_atual_str);
        linha_str.erase(0, pos + 1);

        // Lê e ignora o total de vendas
        total_de_vendas_str = linha_str;

        // Calcula o reajuste com base nos critérios fornecidos
        if (salario_atual < 10000) {
            reajuste = salario_atual * 0.55;
            porcentagem_reajuste = 55.0;
        } else if (salario_atual >= 10000 && salario_atual <= 25000) {
            reajuste = salario_atual * 0.30;
            porcentagem_reajuste = 30.0;
        } else {
            reajuste = salario_atual * 0.20;
            porcentagem_reajuste = 20.0;
        }

        // Calcula o salário reajustado
        salario_reajustado = salario_atual + reajuste;

        // Formata os resultados para exibição
        string salario_atual_formatted, reajuste_formatted, salario_reajustado_formatted;
        formatDouble(salario_atual, salario_atual_formatted);
        formatDouble(reajuste, reajuste_formatted);
        formatDouble(salario_reajustado, salario_reajustado_formatted);

        // Escreve os resultados no arquivo de saída
        fprintf(outfile, "Código do Funcionário: %s \t | Salário atual: R$ %s \t| Reajuste: R$ %s (%.0f%%) \t| Salário reajustado: R$ %s\n",
                cod_funcionario.c_str(), salario_atual_formatted.c_str(),
                reajuste_formatted.c_str(), porcentagem_reajuste,
                salario_reajustado_formatted.c_str());
    }

    fclose(infile);
    fclose(outfile);

    cout << "Processamento concluído. Resultados salvos em 'resultados.txt'." << endl;

    return 0;
}

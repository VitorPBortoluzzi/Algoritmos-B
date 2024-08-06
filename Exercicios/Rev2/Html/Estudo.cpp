#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void formatDouble(double value, string &formatted) {    //Define uma função que não retorna nenhum valor (void). Ela recebe dois parâmetros:
    char buffer[50];                                    // Declara um array de caracteres com tamanho 50. Este buffer será usado para armazenar o valor formatado como uma string.
    snprintf(buffer, sizeof(buffer), "%.2f", value);    //  é uma função da biblioteca padrão C (<cstdio>), que escreve uma string formatada no buffer.
    formatted = buffer;                                 // Atribui o conteúdo do buffer à variável formatted, que agora contém a string formatada com duas casas decimais.
}

int main() {
    FILE *infile = fopen ("funcionarios.txt","r");
    FILE *outfile = fopen ("resultados.html","w");

    if (infile == nullptr){
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }
    if (outfile == nullptr){
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }

    double salario_atual;
    double reajuste;
    double salario_reajustado;
    double porcentagem_reajuste;
    char linha[256];

    //Cabeçalho HTML
    fprintf(outfile, "<!DOCTYPE html>\n<html>\n<head>\n<title>Resultados de Reajuste</title>\n</head>\n<body>\n");
    fprintf(outfile, "<h1>Resultados de Reajuste</h1>\n");
    fprintf(outfile, "<table border=\"1\">\n");
    fprintf(outfile, "<tr><th>Código do Funcionário</th><th>Salário atual</th><th>Reajuste</th><th>Salário reajustado</th></tr>\n");

    while (fgets(linha, sizeof(linha), infile)){
        string linha_str(linha);
        size_t pos = 0;
        string cod_funcionario, salario_atual_str, total_de_vendar_str;

        //Lê o código do funcionario
        pos = linha_str.find(';'); // Encontra a posição do caractere ';' na string linha_str e armazena essa posição na variável pos.
        cod_funcionario = linha_str.substr(0,pos); // Extrai a substring de linha_str que vai do início da string até a posição pos (ou seja, até o caractere ';') e armazena essa substring em cod_funcionario.
        cod_funcionario = cod_funcionario.substr(cod_funcionario.find(':') + 1); // Dentro da substring armazenada em cod_funcionario, encontra a posição do caractere ':' e extrai a substring que começa imediatamente após esse caractere. O resultado é armazenado de volta em cod_funcionario.
        linha_str.erase(0,pos + 1); // Remove a parte da string linha_str que vai do início até pos + 1 (ou seja, até e incluindo o caractere ';'). Isso deixa apenas a parte da string que vem depois do caractere ';'.

        //Lê o salário atual:
        pos = linha_str.find(';');
        salario_atual_str = linha_str.substr(0,pos);
        salario_atual_str = salario_atual_str.substr(salario_atual_str.find(':') + 1);
        salario_atual = stod(salario_atual_str); // String to Double (stod) - Converte a string em double --> Converte o valor da string salario_atual_str para um tipo double e armazena esse valor na variável salario_atual.

        //Lê e ignora o total de vendas: --Come linha;
        total_de_vendar_str = linha_str; 
        
        //Calcula o reajuste com base nos critérios fornecidos:
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

        // Escreve os resultados no arquivo de saída em HTML
        fprintf(outfile, "<tr><td><b>%s</b></td><td><b>R$ %s</b></td><td><b>R$ %s (%.0f%%)</b></td><td><b>R$ %s</b></td></tr>\n",
        cod_funcionario.c_str(), salario_atual_formatted.c_str(),
        reajuste_formatted.c_str(), porcentagem_reajuste,
        salario_reajustado_formatted.c_str());
    }
    // Fecha tags HTML
    fprintf(outfile, "</table>\n</body>\n</html>\n");

    fclose(infile);
    fclose(outfile);

    cout << "Processamento concluído. Resultados salvos em 'resultados.html'." << endl;

    return 0;
}
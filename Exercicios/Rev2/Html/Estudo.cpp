#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

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

    }
}
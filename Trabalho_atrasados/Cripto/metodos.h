typedef struct {
    string nome;
    string sigla;
    string valor;
} Criptocoin;

#include "uteis.h"

int lerArquivoBase(string Iarquivo, Criptocoin lista[], int n){
    ifstream procuradorArquivo;
    procuradorArquivo.open(Iarquivo, ios::in);
    if (!procuradorArquivo.is_open()){
        cout << "Erro ao abrir o arquivo";
        exit(1);
    }
    int qtd = 0;
    string linha;
    while (getline(procuradorArquivo,linha))
    {
        if(linha != ""){
            string vetor[3];
            split(vetor,linha,";");

            lista[qtd].nome = vetor[0];
            lista[qtd].sigla = vetor[1];
            lista[qtd].valor = vetor[2];
            
            qtd++;
        }
    }
    procuradorArquivo.close();
    return qtd;
}

void listar(Criptocoin lista[], int qtdCadastrados){
    if(qtdCadastrados == 0){
        cout << "Lista Vazia\n";
    } else {
        for (int i = 0; i < qtdCadastrados; i++)
        {
            cout << "Cripto: " << lista[i].nome << endl;
        }
        cout << "Todas de tipos de Cripto Moedas Cadastradas: "<< qtdCadastrados << endl;
    }
}

void atualizarArquivo(string nome, string sigla, string valor, string IArquivo){
    ofstream procuradorArquivo;
    procuradorArquivo.open(IArquivo, ios::app); // ios::app para adicionar ao final do arquivo

    procuradorArquivo << nome << ";" << sigla << ";" << valor << "\n";

    procuradorArquivo.close();
}

void atualizarRemocao(Criptocoin lista[], int qtdCadastrados, string IArquivo)
{
    ofstream escritor;
    escritor.open(IArquivo);
    for (int i = 0; i < qtdCadastrados; i++)
    {
        escritor << lista[i].nome << ";" << lista[i].sigla << ";" << lista[i].valor << "\n";
    }

    escritor.close();
}

bool jaCadastrado(string nome, Criptocoin lista[], int totalCadastrados)
{
    for (int i = 0; i < totalCadastrados; i++)
    {
        if (nome == lista[i].nome)
        {
            return true; //ja cadastrado
        }
    }
    return false; //verificamos todas as posicoes e a cript nao cadastrada
}

int cadastrar(Criptocoin lista[], int qtdCadastrados, int n, string IArquivo){
    if (qtdCadastrados == n) {
        cout << "Lista cheia \n";
    } else {
        string nome;
        string sigla;
        string valor;
        cout << "Nome da cripto moeda: ";
        getline(cin,nome);
        nome = paraMaiusculo(nome);
        cin.ignore();

        cout << "Sigla da cripto moeda: ";
        getline(cin,sigla);
        sigla = paraMaiusculo(sigla);
        cin.ignore();

        cout << "Valor da cripto moeda: ";
        getline(cin,valor);
        cin.ignore();

        if (jaCadastrado(nome,lista,qtdCadastrados)){
            cout << "Cripto já cadastrado: ";
            return qtdCadastrados;
        } else {
            lista[qtdCadastrados].nome = nome;
            lista[qtdCadastrados].sigla = sigla;
            lista[qtdCadastrados].valor = valor;
            atualizarArquivo(nome,sigla,valor,IArquivo);
        }
        return ++qtdCadastrados;
    }
}

void copiarLista(Criptocoin origem[], Criptocoin destino[], int qtdCadastrados)
{
    for (int i = 0; i < qtdCadastrados; i++)
    {
        destino[i] = origem[i];
    }
}

int remover(Criptocoin lista[], int qtdCadastrados, int n, string IArquivo)
{
    if (qtdCadastrados == 0) 
    {
        cout << "Lista vazia\n";
    } else 
    {
        string nome;        
        cout << "Nome da cripto moeda a ser excluida: ";
        getline(cin, nome);
        nome = paraMaiusculo(nome);
        cin.ignore();

        Criptocoin listaTMP[n];
        int j = 0;
        bool encontrou = false;
        for (int i = 0; i < qtdCadastrados; i++) {
            if (nome != lista[i].nome) 
            {
                listaTMP[j] = lista[i];
                j++;

            } else {
                encontrou = true;
            }
        }

        if (!encontrou)
        {
            cout << "Cripto nao localizada\n";
            return qtdCadastrados;
        } else
        {
            qtdCadastrados--;
            copiarLista(listaTMP, lista, qtdCadastrados);
            atualizarRemocao(listaTMP, qtdCadastrados, IArquivo);
        }
        
        return qtdCadastrados;
    }
}

void menu(Criptocoin lista[], int qtdCadastrados, int n, string IArquivo)
{
    int opcao;
    do
    {
        system("cls");
        cout << "MENU\n";
        cout << "1 - Listar criptos\n";
        cout << "2 - Cadastrar cripto\n";
        cout << "3 - Remover cripto\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            cout << "Listagem de criptos.....\n";
            listar(lista, qtdCadastrados);
            break;
        case 2:
            cout << "Cadastro de cripto.....\n";
            qtdCadastrados = cadastrar(lista, qtdCadastrados, n, IArquivo);
            break;
        case 3:
            cout << "Remocao de cripto.....\n";
            qtdCadastrados = remover(lista, qtdCadastrados, n, IArquivo);
            break;
        case 4:
            cout << "Tchau.....\n";
            break;        
        default:
            cout << "Opcao invalida.....\n";
            break;
        }
        system("pause");        
    } while (opcao != 4);    
}
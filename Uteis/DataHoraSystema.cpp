#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    // Capturando a data e hora atual do sistema
    time_t tempo = time(nullptr); // Obtém o tempo atual em segundos desde 1 de janeiro de 1970
    tm* agora = localtime(&tempo); // Converte o tempo para a estrutura local 'tm'

    // Capturando o dia, mês e ano
    string dia = to_string(agora->tm_mday); // Obtém o dia do mês (1-31)
    string mes = to_string(agora->tm_mon + 1); // Obtém o mês (0-11), então somamos 1
    string ano = to_string(agora->tm_year + 1900); // Obtém o ano desde 1900, então somamos 1900

    // Formatando a hora atual em uma única linha
    stringstream paraHora; // Cria um objeto stringstream para formatar a hora
    paraHora << setw(2) << setfill('0') << agora->tm_hour << ":" << setw(2) << setfill('0') << agora->tm_min; // Obtém a hora e os minutos

    // Exibindo a data e a hora capturadas
    cout << "Data atual: " << dia << "/" << mes << "/" << ano << endl; // Exibe a data formatada
    cout << "Hora atual: " << paraHora.str() << endl; // Exibe a hora formatada

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}

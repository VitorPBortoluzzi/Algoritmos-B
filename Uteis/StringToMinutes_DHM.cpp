#include <iostream>
#include <string>

using namespace std;

int timeToMinutes(const string& time) {
    // Encontrar as posições dos delimitadores
    size_t colon1 = time.find(':'); // Para encontrar o primeiro ':'
    size_t colon2 = time.find(':', colon1 + 1); // Para encontrar o segundo ':'
    
    // Extrair dias, horas e minutos
    int days = stoi(time.substr(0, colon1)); // Parte antes do primeiro ':'
    int hours = stoi(time.substr(colon1 + 1, colon2 - colon1 - 1)); // Parte entre os dois ':'
    int minutes = stoi(time.substr(colon2 + 1)); // Parte depois do segundo ':'
    
    // Converter o tempo total em minutos
    return days * 1440 + hours * 60 + minutes; // 1 dia = 1440 minutos
}

int main() {
    string time = "2:3:45"; // 2 dias, 3 horas, 45 minutos
    int totalMinutes = timeToMinutes(time);

    cout << "Total minutes: " << totalMinutes << endl;

    return 0;
}

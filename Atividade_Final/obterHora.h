#include <iostream>
#include <string>
#include <vector>

using namespace std;

string obterDataHoraAtual() {
    time_t now = time(0);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}
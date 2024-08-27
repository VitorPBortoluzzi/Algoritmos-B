// #include <iostream>
// #include <string>
// using namespace std;

void imparpar(int a){
    if (a%2==0){
        cout << "Par" << endl;
    } else {
        cout << "Impar" << endl;
    }
}

string imPar(int a){
    if (a%2==0){
        return "Par";
    } else {
        return "Impar";
    }
}

void fraseCaracter(string frase){
    for (int i = 0; i < frase.size(); i++){
        cout << frase[i] << endl;
    }
}

void multiplo_Y_N(int a, int b){
    if (a%b==0){
        cout << "E multiplo" << endl;
    } else {
        cout << "Nao  multiplo" << endl;
    }
}
void toRomanos(int a){
    switch (a)
    {
    case 1:
        cout << "I" << endl;
        break;
    case 2:
        cout << "II"<< endl;
        break;
    case 3:
        cout << "III"<< endl;
        break;
    case 4:
        cout << "IV"<< endl;
        break;
    case 5:
        cout << "V"<< endl;
        break;
    case 6:
        cout << "VI"<< endl;
        break;
    case 7:
        cout << "VII"<< endl;
        break;
    case 8:
        cout << "VIII"<< endl;
        break;
    case 9:
        cout << "IX"<< endl;
        break;
    case 10:
        cout << "X"<< endl;
        break;
    default:
        cout << "Fora de parametros" << endl;
        break;
    }
}

void int_Romanos(int a) {
    string romanos[] = {"Fora de parametros", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
    
    if (a >= 1 && a <= 10) {
        cout << romanos[a] << endl;
    } else {
        cout << romanos[0] << endl;
    }
}
#include <iostream>
using namespace std;

typedef struct {
    int codigo;
    float salarioFixo;
    float totalVendas;
    float comissao;
    float salarioTotal;
} Vendedor;

int main(){
    Vendedor umVendedor;

    cout << "Digite o código: ";
    cin >> umVendedor.codigo;

    cout << "Digite o salário fixo: ";
    cin >> umVendedor.salarioFixo;

    cout << "Digite o total de vendas: ";
    cin >> umVendedor.totalVendas;

    if(umVendedor.totalVendas <= 1000){
        umVendedor.comissao = (umVendedor.totalVendas * 0.03);
    } else if (umVendedor.totalVendas <= 2000){
        umVendedor.comissao = (umVendedor.totalVendas * 0.05);
    } else {
        umVendedor.comissao = (umVendedor.totalVendas * 0.07);
    }
    
    umVendedor.salarioTotal = umVendedor.salarioFixo + umVendedor.comissao;
    cout << "O salário total do vendedor é: " << umVendedor.salarioTotal << endl;

    return 0;
}
using namespace std;

void popularVetor(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }
}

void exibirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << ",";
    }
}

/*
Método sem retorno que receba um vetor de inteiros e seu tamanho e escreva o menor elemento.
Método com retorno que receba um vetor de inteiros e seu tamanho e retorne o menor elemento.
*/

void menorValor(int v[], int n){
    int menorValor = 10000;
    for(int i=0; i <n; i++){
        if(v[i] <= menorValor){
            menorValor =  v[i];
        }
    }
    cout << menorValor;
}

int menorValorR(int v[],int n){
    int menorValor = 10000;
    for(int i=0; i <n; i++){
        if(v[i] <= menorValor){
            menorValor =  v[i];
        }
    }
    return menorValor;
}

/*
Método sem retorno que receba um vetor de inteiros e seu tamanho. Em seguida calcule e escreva a soma dos elementos.
Método com retorno que receba um vetor de inteiros e seu tamanho. Em seguida calcule e retorne a soma dos elementos.
*/

void somaVetor(int v[],int n){
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma = soma + v[i];
    }
    cout << soma;
}

int somaVetorR(int v[],int n){
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma = soma + v[i];
    }
    return soma;
}

/*
Método que receba um vetor de inteiros e seu tamanho. Em seguida, substitua todos os números pares do vetor por 0
*/

void par_to_zero(int v[],int n){
    for (int i = 0; i < n; i++)
    {
        if(v[i] % 2 == 0) v[i] = 0;
    }
    exibirVetor(v,n);
}


/*
Método que receba um vetor de inteiros indicando a origem, o seu tamanho e um vetor de inteiros indicando o destino. 
O método deve copiar todo o conteúdo do vetor origem para o vetor destino.
*/

void vetor1_to_vetor2(int v1[],int n,int v2[]){
    for (int i = 0; i < n; i++)
    {
        v2[i] = v1[i];
    }
}
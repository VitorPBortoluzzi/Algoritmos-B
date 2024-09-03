typedef struct {
    string nome;
    string email;
    string telefone;
}Contato;

void inicializar(Contato vetor[], int n){
    for (int i = 0; i < n; i++){
        vetor[i].nome = "";
        vetor[i].email = "";
        vetor[i].telefone = "";
    }
}

string paraMaisculo(string texto){
    for (int i = 0; i < texto.size(); i++){
        texto[i] = toupper(texto[i]);
    }
    return texto;
}

bool validaNomeCompleto(string nome){
    for (int i=0;i<nome.length();i++){
        if (nome[i] == ' ' && (nome[i+1] != ' ' || nome[i+1] != '\n')){
            return true;
        }
    }
    return false;
}

bool inserir(Contato vetor[], int *qtd){
    if (*qtd == TAM) return false;
    string nome, email;
    for (int i=0; i<TAM;i++){
        if (vetor[i].nome == ""){
            (*qtd)++;
            //recebendo um nome
            do{
                cout << "Entre com o nome completo:";
                getline(cin, nome);
                nome = paraMaisculo(nome);
            } while (!validaNomeCompleto(nome));
            vetor[i].nome = nome;

            //recebendo um email
            cout << "Entre com o email válido:";
            getline(cin, email);
            email = paraMaisculo(email);
            vetor[i].email = email;

            //recebendo um telefone
            cout << "Entre com o telefone válido: ";
            getline(cin, vetor[i].telefone);
            break;
        }
    }
    return true;
}

bool remover(Contato vetor[],int *qtd){
    if (*qtd == 0) return false;
    string nomePesquisa;
    cout << "Entre com nome a ser removido: ";
    getline(cin, nomePesquisa);
    nomePesquisa = paraMaisculo(nomePesquisa);
    int confirma;

    for(int i=0; i< *qtd; i++){
        if(vetor[i].nome != ""){
            if (vetor[i].nome.find(nomePesquisa) != -1){
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
                cout << "Deseja remover o contato? (1 - sim, 2 - não): ";
                cin >> confirma;
                if (confirma == 1){
                    vetor[i].nome = "";
                    vetor[i].email = "";
                    vetor[i].telefone = "";
                    (*qtd)--;
                    return true;
                }
            }
        }
    }

}

// bool atualizar(Contato vetor[],int qtd){
//     if (qtd == 0) return false;
//     string nomePesquisa;
//     string nome, email,telefone;
//     cout << "Entre com nome a ser atualizado: ";
//     getline(cin, nomePesquisa);
//     nomePesquisa = paraMaisculo(nomePesquisa);
//     int confirma;
//     bool encontrado = false;

//     for(int i=0; i< qtd; i++){
//         if(vetor[i].nome != ""){
//             if (vetor[i].nome == nomePesquisa){
//                 encontrado = true;
//                 cout << "Nome: " << vetor[i].nome << endl;
//                 cout << "Email: " << vetor[i].email << endl;
//                 cout << "Telefone: " << vetor[i].telefone << endl;
//                 cout << "Deseja atualizar o contato? (1 - sim, 2 - não): ";
//                 cin >> confirma;
//                 if (confirma == 1){
//                     //recebendo um nome
//                     do {
//                         cout << "Entre com o nome completo:";
//                         getline(cin, nome);
//                         nome = paraMaisculo(nome);
//                     } while (validaNomeCompleto(nome));
//                     vetor[i].nome = nome;

//                     //recebendo um email:
//                     cout << "Entre com o email válido:";
//                     getline(cin, email);
//                     email = paraMaisculo(email);
//                     vetor[i].email = email;

//                     //recebendo um telefone:
//                     cout << "Entre com o telefone válido: ";
//                     getline(cin, vetor[i].telefone);
//                     return true;
//                 }
//             }
//         }
//     }
//     if (!encontrado) return false;
//     else return true;
// }

enum AtualizarResultado {
    ATUALIZAR_SUCESSO,
    ATUALIZAR_FALHA_AGENDA_VAZIA,
    ATUALIZAR_FALHA_CONTATO_NAO_ENCONTRADO,
    ATUALIZAR_CANCELADO
};

AtualizarResultado atualizar(Contato vetor[], int qtd) {
    if (qtd == 0) return ATUALIZAR_FALHA_AGENDA_VAZIA;

    string nomePesquisa;
    string nome, email, telefone;
    cout << "Entre com o nome a ser atualizado: ";
    getline(cin, nomePesquisa);
    nomePesquisa = paraMaisculo(nomePesquisa);

    int confirma;
    bool encontrado = false;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].nome != "") {
            if (vetor[i].nome == nomePesquisa) {
                encontrado = true;
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
                cout << "Deseja atualizar o contato? (1 - sim, 2 - não): ";
                cin >> confirma;
                cin.ignore(); // Ignorar o newline após a entrada de confirmação

                if (confirma == 1) {
                    // Recebendo um nome
                    do {
                        cout << "Entre com o nome completo: ";
                        getline(cin, nome);
                        nome = paraMaisculo(nome);
                    } while (!validaNomeCompleto(nome));
                    vetor[i].nome = nome;

                    // Recebendo um email
                    cout << "Entre com o email válido: ";
                    getline(cin, email);
                    email = paraMaisculo(email);
                    vetor[i].email = email;

                    // Recebendo um telefone
                    cout << "Entre com o telefone válido: ";
                    getline(cin, vetor[i].telefone);

                    return ATUALIZAR_SUCESSO;
                } else {
                    return ATUALIZAR_CANCELADO;
                }
            }
        }
    }
    if (!encontrado) return ATUALIZAR_FALHA_CONTATO_NAO_ENCONTRADO;

    return ATUALIZAR_FALHA_CONTATO_NAO_ENCONTRADO;
}


bool listar(Contato vetor[], int qtd){
    if (qtd == 0) return false;

    for (int i = 0; i < qtd; i++){
        if (vetor[i].nome != ""){
            cout << "Nome: " << vetor[i].nome << endl;
            cout << "Email: " << vetor[i].email << endl;
            cout << "Telefone: " << vetor[i].telefone << endl;
        }
    }
    return true;
}

bool pesquisar(Contato vetor[], int qtd){
    if (qtd == 0) return false;
    string nomePesquisa;
    cout << "Entre com nome a ser procurado: ";
    getline(cin, nomePesquisa);
    nomePesquisa = paraMaisculo(nomePesquisa);

    for (int i=0;i<qtd;i++){
        if(vetor[i].nome != ""){
            if (vetor[i].nome.find(nomePesquisa) != -1){
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
            }
        }
    }
    return true;
}

=========
main
case 3:
                cout << "Atualizar" << endl;
                switch(atualizar(vetor, qtd_contatos)) {
                    case ATUALIZAR_SUCESSO:
                        cout << "Contato atualizado com sucesso" << endl;
                        break;
                    case ATUALIZAR_FALHA_AGENDA_VAZIA:
                        cout << "Agenda vazia" << endl;
                        break;
                    case ATUALIZAR_FALHA_CONTATO_NAO_ENCONTRADO:
                        cout << "Contato não encontrado" << endl;
                        break;
                    case ATUALIZAR_CANCELADO:
                        cout << "Atualização cancelada" << endl;
                        break;
                    default:
                        cout << "Erro desconhecido" << endl;
                        break;
                }
                break;

=======

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
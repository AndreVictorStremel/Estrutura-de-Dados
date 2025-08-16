#include <iostream>
using namespace std;

struct no {
    int dado;
    struct no* prox;
};

struct no* lista = NULL;


void insereLista(int valor) {
    struct no *novo = new no;
    novo->dado = valor;
    novo->prox = NULL;

    if (lista == NULL || valor < lista->dado) {
        if (lista != NULL && lista->dado == valor) {
            cout << "Valor ja existe na lista.\n";
            delete novo;
            return;
        }
        novo->prox = lista;
        lista = novo;
        cout << "Valor inserido com sucesso.\n";
        return;
    }

    struct no *atual = lista, *anterior = NULL;
    while (atual != NULL && valor > atual->dado) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->dado == valor) {
        cout << "Valor ja existe na lista.\n";
        delete novo;
        return;
    }

    novo->prox = atual;
    anterior->prox = novo;
    cout << "Valor inserido com sucesso.\n";
}


void removeValor(int valor) {
    struct no *atual = lista, *anterior = NULL;

    while (atual != NULL && atual->dado < valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL || atual->dado != valor) {
        cout << "Valor nao encontrado na lista.\n";
        return;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    delete atual;
    cout << "Valor removido com sucesso.\n";
}


void recuperaLista(int posicao) {
    struct no *atual = lista;
    int i = 0;

    while (atual != NULL && i < posicao) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        cout << "Posicao invalida.\n";
    } else {
        cout << "Valor na posicao " << posicao << ": " << atual->dado << endl;
    }
}


void buscaLista(int valor) {
    struct no *atual = lista;
    int posicao = 0;

    while (atual != NULL && atual->dado < valor) {
        atual = atual->prox;
        posicao++;
    }

    if (atual != NULL && atual->dado == valor) {
        cout << "Valor encontrado na posicao: " << posicao << endl;
    } else {
        cout << "Valor nao encontrado na lista.\n";
    }
}


void imprime() {
    struct no* atual = lista;
    if (atual == NULL) {
        cout << "Lista vazia.\n";
        return;
    }

    cout << "Lista: ";
    while (atual != NULL) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}


void liberaLista() {
    struct no* atual = lista;
    while (atual != NULL) {
        struct no* temp = atual;
        atual = atual->prox;
        delete temp;
    }
    lista = NULL;
    cout << "Memoria liberada com sucesso.\n";
}


int main() {
    int opcao, valor, posicao;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Inserir valor\n";
        cout << "2. Remover valor\n";
        cout << "3. Recuperar valor por posição\n";
        cout << "4. Buscar valor\n";
        cout << "5. Imprimir lista\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                insereLista(valor);
                break;
            case 2:
                cout << "Digite o valor a remover: ";
                cin >> valor;
                removeValor(valor);
                break;
            case 3:
                cout << "Digite a posicao a recuperar: ";
                cin >> posicao;
                recuperaLista(posicao);
                break;
            case 4:
                cout << "Digite o valor a buscar: ";
                cin >> valor;
                buscaLista(valor);
                break;
            case 5:
                imprime();
                break;
            case 0:
                cout << "Encerrando o programa.\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    liberaLista(); 
    return 0;
}

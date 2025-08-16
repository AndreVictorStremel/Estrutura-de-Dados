#include <iostream>
using namespace std;

struct no {
    int dado;
    struct no *prox; // ponteiro para o proximo elemento
};

struct no *topo = NULL;

void push(int valor) {
    struct no *novo;
    novo = new(struct no);
    novo->dado = valor;
    novo->prox = topo;
    topo = novo;
    cout << "Elemento " << valor << " inserido" << endl;
}

void pop() {
    struct no *apaga;
    if (topo == NULL) {
        cout << "Pilha vazia" << endl;
        return;
    } else {
        apaga = topo;
        topo = topo->prox;
        cout << "Elemento " << apaga->dado << " removido" << endl;
        delete(apaga);
    }
}

void topopilha() {
    if (topo == NULL) {
        cout << "Pilha vazia" << endl;
        return;
    } else {
        cout << "Topo da pilha: " << topo->dado << endl;
    }
}

void imprime() {
    struct no *aux;
    if (topo == NULL) {
        cout << "Pilha vazia" << endl;
        return;
    } else {
        aux = topo;
        cout << "Pilha: ";
        while (aux != NULL) {
            cout << aux->dado << " ";
            aux = aux->prox;
        }
        cout << endl;
    }
}

int main() {
    cout << "=== Exemplo de uso da pilha ===" << endl;

    push(10);
    push(20);
    push(30);
    imprime();

    topopilha();

    pop();
    imprime();

    pop();
    imprime();

    pop();
    imprime();

    pop(); // tentativa de remover de pilha vazia

    return 0;
}

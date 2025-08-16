#include <iostream>
using namespace std;

struct no {
    int dado;
    struct no *esq;
    struct no *dir;
};

struct no *raiz = NULL;

void insereArvore(int valor){
    struct no *atual, *anterior, *novo;
    novo = new struct no;
    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if(raiz == NULL){
        raiz = novo;
        return;
    }

    atual = raiz;
    while(atual != NULL){
        if(valor == atual->dado){
            cout << "Numero repetido\n";
            delete(novo);
            return;
        }

        anterior = atual;
        if(valor < atual->dado){
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    if(valor < anterior->dado){
        anterior->esq = novo;
    } else {
        anterior->dir = novo;
    }
}

void emordem(struct no *atual){
    if(atual != NULL){
        emordem(atual->esq);
        cout << atual->dado << " ";
        emordem(atual->dir);
    }
}

void buscaArvore(int valor){
    struct no *atual = raiz;

    while(atual != NULL){
        if(valor == atual->dado){
            cout << "Encontrei o numero\n";
            return;
        } else if(valor < atual->dado){
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    cout << "Nao encontrei o numero\n";
}

int main(){
    insereArvore(10);
    insereArvore(20);
    insereArvore(30);
    insereArvore(5);
    insereArvore(15);

    cout << "Em ordem: ";
    emordem(raiz);
    cout << endl;

    buscaArvore(30);
    buscaArvore(100);

    return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

const int TAM = 20000;

int vetor[TAM];
float comparaSD = 0, comparaSO = 0, comparaB = 0, comparaAB = 0, comparaAVL = 0;

struct no {
    int dado;
    struct no *esq;
    struct no *dir;
    int bal;
};

struct no* raiz = NULL, *raiz_avl = NULL;


// Rotacao para a esquerda
void esquerda(struct no *p) {
    struct no *q, *hold;
    q = p->dir;
    hold = q->esq;
    q->esq = p;
    p->dir = hold;
}

// Rotacao para a direita
void direita(struct no *p) {
    struct no *q, *hold;
    q = p->esq;
    hold = q->dir;
    q->dir = p;
    p->esq = hold;
}

// Cria um no
struct no *cria_no(int valor) {
    struct no *aux = new (struct no);
    aux->dado = valor;
    aux->dir = NULL;
    aux->esq = NULL;
    aux->bal = 0;
    return aux;
}

void insere_bal(int chave) {
    struct no *pp = NULL, *p = raiz_avl, *pajovem = NULL, *ajovem = raiz_avl, *q, *filho;
    int imbal;

    if (p == NULL) { // arvore vazia
        raiz_avl = cria_no(chave);
        return;
    }

    while (p != NULL) {
        if (chave < p->dado)
            q = p->esq;
        else
            q = p->dir;
        if (q != NULL)
            if (q->bal != 0) {
                pajovem = p;
                ajovem = q;
            }
        pp = p;
        p = q;
    }

    q = cria_no(chave);
    if (chave < pp->dado)
        pp->esq = q;
    else
        pp->dir = q;

    if (chave < ajovem->dado)
        filho = ajovem->esq;
    else
        filho = ajovem->dir;

    p = filho;
    while (p != q) {
        if (chave < p->dado) {
            p->bal = 1;
            p = p->esq;
        } else {
            p->bal = -1;
            p = p->dir;
        }
    }

    if (chave < ajovem->dado)
        imbal = 1;
    else
        imbal = -1;

    if (ajovem->bal == 0) {
        ajovem->bal = imbal;
        return;
    }

    if (ajovem->bal != imbal) {
        ajovem->bal = 0;
        return;
    }

    if (filho->bal == imbal) {
        p = filho;
        if (imbal == 1)
            direita(ajovem);
        else
            esquerda(ajovem);
        ajovem->bal = 0;
        filho->bal = 0;
    } else {
        if (imbal == 1) {
            p = filho->dir;
            esquerda(filho);
            ajovem->esq = p;
            direita(ajovem);
        } else {
            p = filho->esq;
            direita(filho);
            ajovem->dir = p;
            esquerda(ajovem);
        }
        if (p->bal == 0) {
            ajovem->bal = 0;
            filho->bal = 0;
        } else {
            if (p->bal == imbal) {
                ajovem->bal = -imbal;
                filho->bal = 0;
            } else {
                ajovem->bal = 0;
                filho->bal = imbal;
            }
        }
        p->bal = 0;
    }

    if (pajovem == NULL)
        raiz_avl = p;
    else if (ajovem == pajovem->dir)
        pajovem->dir = p;
    else
        pajovem->esq = p;
}

void insereArvore(int valor) {
    struct no *atual, *anterior, *aux;
    aux = new(struct no);
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;

    if (raiz == NULL) {
        raiz = aux;
        return;
    }

    atual = raiz;
    while (atual != NULL) {
        anterior = atual;
        if (valor < atual->dado)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    if (valor < anterior->dado)
        anterior->esq = aux;
    else
        anterior->dir = aux;
}

int particao(int p, int r) {
    int pivo, temp, i, j;
    pivo = vetor[p];
    i = p - 1;
    j = r + 1;
    while (true) {
        do { j = j - 1; } while (vetor[j] > pivo);
        do { i = i + 1; } while (vetor[i] < pivo);
        if (i < j) {
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        } else return j;
    }
}

void quick(int p, int r) {
    int q;
    if (p < r) {
        q = particao(p, r);
        quick(p, q);
        quick(q + 1, r);
    }
}

void geraVetor() {
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % (TAM * 10);
    }
    quick(0, TAM - 1);
}

void buscaSequencial(int chave) {
    for (int i = 0; i < TAM; i++) {
        comparaSD++;
        if (chave == vetor[i])
            break;
    }
}

void buscaSequencialOrdenada(int chave) {
    for (int i = 0; i < TAM; i++) {
        comparaSO++;
        if (chave <= vetor[i])
            break;
    }
}

void buscaBinaria(int chave) {
    int meio, primeiro = 0, ultimo = TAM - 1;
    while (primeiro <= ultimo) {
        comparaB++;
        meio = (primeiro + ultimo) / 2;
        if (vetor[meio] == chave)
            return;
        if (chave < vetor[meio])
            ultimo = meio - 1;
        else
            primeiro = meio + 1;
    }
}

void buscaArvore(int chave) {
    struct no *atual = raiz;
    while (atual != NULL) {
        comparaAB++;
        if (chave == atual->dado)
            return;
        else if (chave < atual->dado)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
}

void buscaArvoreAVL(int info) {
    struct no *atual = raiz_avl;
    while (atual != NULL) {
        comparaAVL++;
        if (info == atual->dado)
            return;
        else if (info < atual->dado)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
}

int main() {
    geraVetor();
    for (int i = 0; i < TAM; i++) {
        insereArvore(vetor[i]);
        insere_bal(vetor[i]);
    }
    quick(0, TAM - 1);

    for (int i = 0; i < 1000; i++) {
        int chave = rand() % (TAM * 10);
        buscaSequencial(chave);
        buscaSequencialOrdenada(chave);
        buscaBinaria(chave);
        buscaArvore(chave);
        buscaArvoreAVL(chave);
    }

    cout << "Busca sequencial: " << comparaSD / 1000 << endl;
    cout << "Busca sequencial ordenada: " << comparaSO / 1000 << endl;
    cout << "Busca binaria: " << comparaB / 1000 << endl;
    cout << "Busca arvore binaria: " << comparaAB / 1000 << endl;
    cout << "Busca arvore AVL: " << comparaAVL / 1000 << endl;

    return 0;
}





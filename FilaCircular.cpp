#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // tamanho maximo da fila

typedef struct {
    int itens[MAX];
    int frente, tras, quantidade;
} FilaCircular;

// Inicializa a fila
void inicializar(FilaCircular *f) {
    f->frente = 0;
    f->tras = -1;
    f->quantidade = 0;
}

// Verifica se a fila esta cheia
int cheia(FilaCircular *f) {
    return f->quantidade == MAX;
}

// Verifica se a fila esta vazia
int vazia(FilaCircular *f) {
    return f->quantidade == 0;
}

// Enfileirar
void enfileirar(FilaCircular *f, int valor) {
    if (cheia(f)) {
        printf("Fila cheia! Nao e possivel adicionar %d.\n", valor);
        return;
    }
    f->tras = (f->tras + 1) % MAX;
    f->itens[f->tras] = valor;
    f->quantidade++;
    printf("Enfileirado: %d\n", valor);
}

// Desenfileirar
int desenfileirar(FilaCircular *f) {
    if (vazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->quantidade--;
    return valor;
}

// Mostrar fila
void mostrar(FilaCircular *f) {
    if (vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    int i, idx;
    for (i = 0; i < f->quantidade; i++) {
        idx = (f->frente + i) % MAX;
        printf("%d ", f->itens[idx]);
    }
    printf("\n");
}

int main() {
    FilaCircular fila;
    inicializar(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    enfileirar(&fila, 40);
    enfileirar(&fila, 50);
    mostrar(&fila);

    printf("Removido: %d\n", desenfileirar(&fila));
    mostrar(&fila);

    enfileirar(&fila, 60);
    mostrar(&fila);

    return 0;
}

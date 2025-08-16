#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM 10

int A[TAM];

// Funcao para imprimir o vetor
void mostrar_vetor() {
    for (int i = 0; i < TAM; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Gera vetor aleatorio
void gerar() {
    for (int i = 0; i < TAM; i++) {
        A[i] = rand() % 100; // numeros de 0 a 99
    }
}

// =================== Insertion Sort ===================
void Insertion_sort() {
    int i, k, x;
    bool found;

    for (k = 1; k < TAM; k++) {
        x = A[k];
        i = k - 1;
        found = false;

        while (!found && i >= 0) {
            if (A[i] > x) {
                A[i + 1] = A[i];
                i--;
            } else {
                found = true;
            }
        }
        A[i + 1] = x;
    }
}

// =================== Shell Sort ===================
void Shell_sort() {
    int i, j, k, temp;
    bool found;
    int n = TAM;

    k = 1;
    while (k < n / 2) k = k * 2 + 1;

    while (k >= 1) {
        for (i = k; i < n; i++) {
            j = i - k;
            found = false;
            while (j >= 0 && !found) {
                if (A[j] > A[j + k]) {
                    temp = A[j];
                    A[j] = A[j + k];
                    A[j + k] = temp;
                    j -= k;
                } else {
                    found = true;
                }
            }
        }
        k /= 2;
    }
}

// =================== MAIN ===================
int main() {
    srand(time(NULL));

    // Vetor original
    gerar();
    printf("Vetor original:\n");
    mostrar_vetor();

    // Ordena com Insertion Sort
    Insertion_sort();
    printf("Vetor ordenado com Insertion Sort:\n");
    mostrar_vetor();

    // Gera novo vetor aleatorio
    gerar();
    printf("Novo vetor:\n");
    mostrar_vetor();

    // Ordena com Shell Sort
    Shell_sort();
    printf("Vetor ordenado com Shell Sort:\n");
    mostrar_vetor();

    return 0;
}

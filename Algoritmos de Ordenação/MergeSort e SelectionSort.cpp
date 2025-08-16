#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int A[TAM];
int scratch[TAM]; 

void SELECTION_SORT(int n) {
    for (int i = 0; i < n - 1; i++) {
        int current = i;
        for (int k = i + 1; k < n; k++) {
            if (A[current] > A[k]) {
                current = k;
            }
        }
        // Troca
        int temp = A[i];
        A[i] = A[current];
        A[current] = temp;
    }
}


void MERGESORT(int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        MERGESORT(lo, mid);
        MERGESORT(mid + 1, hi);

        int L = lo;
        int H = mid + 1;

        for (int k = lo; k <= hi; k++) {
            if (L <= mid && (H > hi || A[L] <= A[H])) {
                scratch[k] = A[L];
                L++;
            } else {
                scratch[k] = A[H];
                H++;
            }
        }
        for (int k = lo; k <= hi; k++) {
            A[k] = scratch[k];
        }
    }
}


void gerar() {
    for (int i = 0; i < TAM; i++) {
        A[i] = rand() % 100; // números de 0 a 99
    }
}

void imprime(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    printf("Vetor original:\n");
    gerar();
    imprime(TAM);

    SELECTION_SORT(TAM);
    printf("Ordenado com Selection Sort:\n");
    imprime(TAM);

   
    gerar();
    printf("Vetor novo:\n");
    imprime(TAM);

    MERGESORT(0, TAM - 1);
    printf("Ordenado com MergeSort:\n");
    imprime(TAM);

    return 0;
}

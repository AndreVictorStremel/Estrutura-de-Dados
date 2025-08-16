#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM 50000

int A[TAM], scratch[TAM];


void SELECTION_SORT() {
    int temp, current;
    for (int i = 0; i < TAM - 1; i++) {
        current = i;
        for (int k = i + 1; k < TAM; k++) {
            if (A[current] > A[k]) {
                current = k;
            }
        }
        if (current != i) {
            temp = A[i];
            A[i] = A[current];
            A[current] = temp;
        }
    }
}


void MERGESORT(int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        MERGESORT(lo, mid);
        MERGESORT(mid + 1, hi);
        int L = lo, H = mid + 1;

        for (int k = lo; k <= hi; k++) {
            if (L <= mid && (H > hi || A[L] <= A[H])) {
                scratch[k] = A[L++];
            } else {
                scratch[k] = A[H++];
            }
        }

        for (int k = lo; k <= hi; k++) {
            A[k] = scratch[k];
        }
    }
}


void BUBBLE_SORT() {
    int pass = 1;
    bool sorted = false;

    while (!sorted && pass < TAM) {
        sorted = true;
        for (int i = 0; i <= TAM - pass - 1; i++) {
            if (A[i] > A[i + 1]) {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                sorted = false;
            }
        }
        pass = pass + 1;
    }
}


int PARTITION(int p, int r) {
    int piv = A[p];
    int i = p - 1;
    int j = r + 1;

    while (1) {
        do {
            j--;
        } while (A[j] > piv);

        do {
            i++;
        } while (A[i] < piv);

        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        } else {
            return j;
        }
    }
}

void QUICKSORT(int p, int r) {
    if (p < r) {
        int q = PARTITION(p, r);
        QUICKSORT(p, q);
        QUICKSORT(q + 1, r);
    }
}


void SHELLSORT() {
    int k = 1;
    do {
        k = k * 2 + 1;
    } while (k < TAM);

    while (k != 1) {
        k = k / 2;
        for (int i = k; i < TAM; i++) {
            int j = i - k;
            bool found = false;
            while (j >= 0 && !found) {
                if (A[j] > A[j + k]) {
                    int temp = A[j];
                    A[j] = A[j + k];
                    A[j + k] = temp;
                    j = j - k;
                } else {
                    found = true;
                }
            }
        }
    }
}


void INSERTION_SORT() {
    for (int k = 1; k < TAM; k++) {
        int x = A[k];
        int i = k - 1;
        bool found = false;

        while (!found && i >= 0) {
            if (A[i] > x) {
                int temp = A[i + 1];
                A[i + 1] = A[i];
                A[i] = temp;
                i--;
            } else {
                found = true;
            }
        }
    }
}


void gerar() {
    for (int i = 0; i < TAM; i++) {
        A[i] = rand();
    }
}


int main() {
    clock_t start, end;
    double tempo;

    printf("Comparando algoritmos com %d elementos\n\n", TAM);

    gerar();
    start = clock();
    SELECTION_SORT();
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo SELECTION_SORT: %.4f segundos\n", tempo);

    gerar();
    start = clock();
    MERGESORT(0, TAM - 1);
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo MERGESORT: %.4f segundos\n", tempo);

    gerar();
    start = clock();
    BUBBLE_SORT();
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo BUBBLE_SORT: %.4f segundos\n", tempo);

    gerar();
    start = clock();
    QUICKSORT(0, TAM - 1);
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo QUICKSORT: %.4f segundos\n", tempo);

    gerar();
    start = clock();
    SHELLSORT();
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo SHELLSORT: %.4f segundos\n", tempo);

    gerar();
    start = clock();
    INSERTION_SORT();
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo INSERTION_SORT: %.4f segundos\n", tempo);

    return 0;
}

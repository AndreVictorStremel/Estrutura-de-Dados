#include <iostream>
using namespace std;

// Funcao para fazer a particao
int PARTITION(int A[], int p, int r) {
    int piv = A[p]; // pivo como o primeiro elemento
    int i = p - 1;
    int j = r + 1;

    while (true) {
        // Move j para a esquerda
        do {
            j--;
        } while (A[j] > piv);

        // Move i para a direita
        do {
            i++;
        } while (A[i] < piv);

        // Se indices se cruzaram, retorna j
        if (i >= j) return j;

        // Troca os elementos fora de lugar
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

// Funcao recursiva de ordenacao
void QUICKSORT(int A[], int p, int r) {
    if (p < r) {
        int q = PARTITION(A, p, r);
        QUICKSORT(A, p, q);
        QUICKSORT(A, q + 1, r);
    }
}

int main() {
    int A[] = {33, 10, 55, 71, 29, 1, 90, 15};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Vetor original: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;

    QUICKSORT(A, 0, n - 1);

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;

    return 0;
}

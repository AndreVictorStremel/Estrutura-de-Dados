#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TAM = 5;

void bubble(float A[]) {
    int pass = 1;
    bool sorted = false;

    while (!sorted && pass < TAM) {
        sorted = true;
        for (int i = 0; i <= TAM - pass - 1; i++) {
            if (A[i] > A[i + 1]) {
                float temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                sorted = false;
            }
        }
        pass = pass + 1;
    }
}

int main() {
    srand(time(0));
    float vet[TAM];

    cout << "vetor original:\n";
    for (int j = 0; j < TAM; j++) {
        vet[j] = (rand() % 100);  
        cout << vet[j] << " ";
    }
    cout << "\n";

    bubble(vet);

    cout << "vetor ordenado:\n";
    for (int j = 0; j < TAM; j++) {
        cout << vet[j] << " ";
    }
    cout << "\n";

    return 0;
}

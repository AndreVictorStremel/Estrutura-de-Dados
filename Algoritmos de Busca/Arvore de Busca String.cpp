#include <iostream>
#include <cstring>
#include <clocale>
using namespace std;

struct no {
    char dado[50];
    int contador;
    struct no *esq;
    struct no *dir;
};

struct no *raiz = NULL;
char palavraFrequente[50];
char maiorpalavra[50];
int tamanho = 0;
int maior = 0;

struct no* raiz;

void insereArvore(int valor) {

    struct no *atual, *anterior, *aux;

    aux = new(struct no);
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;

    if (raiz==NULL) {
        raiz = aux;
        return;
    }

    atual=raiz;

    while (atual!=NULL) {
        anterior=atual;
        if (valor < atual->dado)
            atual=atual->esq;
        else atual=atual->dir;
    }
    if (valor < anterior->dado)
        anterior->esq=aux;
    else anterior->dir=aux;
}

void insereArvoreSemRepetidos(char valor[]) {

    struct no *atual, *anterior, *aux;

    aux = new(struct no);
    strcpy(aux -> dado,valor);
    aux -> contador = 1;
    aux->esq = NULL;
    aux->dir = NULL;

    atual=raiz;

    if (atual==NULL) {
        raiz = aux;
        return;
    }

    while (atual!=NULL) {
        anterior = atual;
        if(strcmp(valor, atual -> dado) == 0){
            atual -> contador++;
            delete(aux);
            return;
        }if(strcmp(valor,atual -> dado) < 0){
            atual = atual -> esq;
        }
        if (valor==atual->dado) {
            printf("Numero repetido \n");
            return;
        }
        anterior=atual;
        if (valor < atual->dado)
            atual=atual->esq;
        else atual=atual->dir;
    }
    if (valor < anterior->dado)
        anterior->esq=aux;
    else anterior->dir=aux;
}

void em_ordem(struct no *atual) {
    if (atual!=NULL) {
        em_ordem(atual->esq);
        cout<<atual -> dado << ":";
        cout<<atual -> contador << endl;
        if(strlen(atual -> dado) > tamanho) {
            strcpy(maiorpalavra, atual ->dado);
            tamanho = strlen(atual -> dado);
        }
        if(atual -> contador > maior){
            strcpy(palavraFrequente, atual -> dado);
            maior = atual -> contador;
        }
        }
        em_ordem(atual->dir);
    }
}


void buscaArvore(int info) {
    struct no *atual;

    atual=raiz;

    while (atual!=NULL) {
        if (info==atual->dado) {
            printf("Encontrei o numero\n");
            return;
        } else if (info<atual->dado)
            atual=atual->esq;
        else atual=atual->dir;
    }
    printf("Nao encontrei o numero\n");
}

int main() {
    char palavra [50];
    FILE *fp;
    setlocale(LC_ALL<"");
    fp = fopen("texto.txt", "r");
    if(fp == NULL){
       count<<"erro";
       return;
    }
    
    while(!feof(fp)){
        fscanf(fp, "%s", palavra);
        for(int i = 0; palavra[i] != '\0'; i++){
            palavra [i] = tolower(palavra[i]);
        }
        insereArvore(palavra);
        
    }
    fclose(fp);
    em.ordem(raiz);
    cout<<"maior palavra"<<maiorpalavra;
    cout<<"mais frequente"<<palavraFrequente;
}

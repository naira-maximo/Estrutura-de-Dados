#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    int chave;
    struct no* esq;
    struct no* dir;
} no;

int contador = 0;

no* cria_arvore(int valor) {
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->chave = contador++;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

no* insere_arvore(no* raiz, int valor) {
    if (raiz == NULL) {
        return cria_arvore(valor); 
    }
    if (valor < raiz->valor) {
        raiz->esq = insere_arvore(raiz->esq, valor);
    } else {
        raiz->dir = insere_arvore(raiz->dir, valor);
    }
    return raiz;
}

void imprime_em_ordem(no* raiz) {
    if (raiz != NULL) {
        imprime_em_ordem(raiz->esq);
        printf("Valor: %d, Chave: %d\n", raiz->valor, raiz->chave); 
        imprime_em_ordem(raiz->dir);
    }
}

no** busca_no(no** raiz, int valor) {
    if (*raiz == NULL) return NULL;

    if (valor == (*raiz)->valor) {
        return raiz;
    } else if (valor < (*raiz)->valor) {
        return busca_no(&(*raiz)->esq, valor);
    } else {
        return busca_no(&(*raiz)->dir, valor);
    }
}

int remover_no(no** raiz) {
    if (*raiz == NULL) return -1; // Retorna -1 em vez de NULL (convenção em C?)

    int valor_remover = (*raiz)->valor;

    if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
        free(*raiz);
        *raiz = NULL;
    } else if ((*raiz)->dir == NULL) {
        no* temp = (*raiz)->esq;
        free(*raiz);
        *raiz = temp;
    } else if ((*raiz)->esq == NULL) {
        no* temp = (*raiz)->dir;
        free(*raiz);
        *raiz = temp;
    } else {
        no** nova_raiz = &(*raiz)->esq;
        no** pai = NULL;

        while ((*nova_raiz)->dir != NULL) {
            pai = nova_raiz;
            nova_raiz = &(*nova_raiz)->dir;
        }

        no* temp = *nova_raiz;

        if (pai != NULL) {
            (*pai)->dir = temp->esq;
        } else {
            (*raiz)->esq = temp->esq;
        }

        temp->esq = (*raiz)->esq;
        temp->dir = (*raiz)->dir;

        free(*raiz);
        *raiz = temp;
    }

    return valor_remover;
}

int main() {
    no* raiz = NULL;

    printf("ERD:\n");
    raiz = insere_arvore(raiz, 10);
    imprime_em_ordem(raiz);
    printf("\nERD:\n");
    raiz = insere_arvore(raiz, 5);
    imprime_em_ordem(raiz);
    printf("\nERD:\n");
    raiz = insere_arvore(raiz, 15);
    imprime_em_ordem(raiz);
    printf("\nERD:\n");
    raiz = insere_arvore(raiz, 2);
    imprime_em_ordem(raiz);
    printf("\nERD:\n");
    raiz = insere_arvore(raiz, 7);
    imprime_em_ordem(raiz);
    printf("\nERD:\n");
    raiz = insere_arvore(raiz, 12);
    imprime_em_ordem(raiz);
    printf("\nERD:\n");
    raiz = insere_arvore(raiz, 20);
    imprime_em_ordem(raiz);
    
    printf("\nRemovendo:\n");
    no** no_encontrado = busca_no(&raiz, 10);
    if (no_encontrado != NULL) remover_no(no_encontrado);
    imprime_em_ordem(raiz);

    printf("\nRemovendo:\n");
    no_encontrado = busca_no(&raiz, 5);
    if (no_encontrado != NULL) remover_no(no_encontrado);
    imprime_em_ordem(raiz);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* esq;
    struct no* dir;
} no;

no* cria_no(int valor) {
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

typedef struct arvore {
    no* raiz;
} arvore;

arvore* cria_arvore() {
    arvore* nova_arvore = (arvore*)malloc(sizeof(arvore));
    nova_arvore->raiz = NULL;
    return nova_arvore;
}

no* inserir_no(no* atual, no* novo) {
    if (atual == NULL) {
        return novo;
    }
    if (novo->valor < atual->valor) {
        atual->esq = inserirNo(atual->esq, novo);
    } else {
        atual->dir = inserirNo(atual->dir, novo);
    }
    return atual;
}

void inserir(arvore* arvore, int valor) {
    no* novo = criaNo(valor);
    arvore->raiz = inserirNo(arvore->raiz, novo);
}

void imprime_em_ordem(no* atual) {
    if (atual != NULL) {
        imprime_em_ordem(atual->esq);
        printf("%d, ", atual->valor);
        imprime_em_ordem(atual->dir);
    }
}

no* remover(no* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    } else {
        // Sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }
        // Um filho
        else if (raiz->esq == NULL) {
            no* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            no* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        // Dois filhos
        else {
            no* temp = raiz->dir;
            while (temp->esq != NULL) {
                temp = temp->esq;
            }
            raiz->valor = temp->valor;
            raiz->dir = remover(raiz->dir, temp->valor);
        }
    }
    return raiz;
}

void remover(arvore* arvore, int valor) {
    arvore->raiz = remover(arvore->raiz, valor);
}

int main() {
    arvore* minha_arvore = criaArvore();

    inserir(minha_arvore, 13);
    inserir(minha_arvore, 10);
    inserir(minha_arvore, 25);
    inserir(minha_arvore, 2);
    inserir(minha_arvore, 12);
    inserir(minha_arvore, 20);
    inserir(minha_arvore, 31);
    inserir(minha_arvore, 29);
    inserir(minha_arvore, 32);

    remover(minha_arvore, 32);

    printf("\nÁrvore In-Ordem:\n");
    imprime_em_ordem(minha_arvore->raiz);
    printf("\n");

    return 0;
}

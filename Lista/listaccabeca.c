#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;           
    struct No* proximo;
} No;

No* cria_no(int valor) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (!novo_no) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

No* inicializa_lista() {
    No* cabeca = (No*) malloc(sizeof(No));
    if (!cabeca) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    cabeca->proximo = NULL;
    return cabeca;
}

void insere_no(No* cabeca, int valor) {
    No* novo_no = cria_no(valor);
    No* temp = cabeca;

    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }

    temp->proximo = novo_no; 
}

void imprime_lista(No* cabeca) {
    No* temp = cabeca->proximo;

    if (temp == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

void libera_lista(No* cabeca) {
    No* atual = cabeca;
    No* proximo_no;

    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);  // Libera o nó atual
        atual = proximo_no;
    }
}

int main() {
    No* lista = inicializa_lista();

    insere_no(lista, 10);
    insere_no(lista, 20);
    insere_no(lista, 30);

    printf("Elementos da lista: ");
    imprime_lista(lista);

    libera_lista(lista);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* cria_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));  // Aloca memória dinamicamente para o nó
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

void insere_no(No** primeiro, int valor) {
    No* novo = cria_no(valor);
    if (*primeiro == NULL) { 
        *primeiro = novo; // Se o primeiro nó não existir, o novo nó será o primeiro
        return;
    }

    No* atual = *primeiro;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo; // O novo nó será o próximo do último nó
}

void insere_meio(No* existente, int valor) {
    if (existente == NULL) {
        printf("O nó passado é nulo. Não pode inserir.\n");
        return;
    }
    No* novo = cria_no(valor);
    novo->proximo = existente->proximo; // O próximo do novo nó será o próximo do nó existente
    existente->proximo = novo; // O próximo do nó existente será o novo nó
}

void remove_no(No** primeiro, No* no_remover) {
    if (*primeiro == NULL || no_remover == NULL) {
        printf("O nó não existe");
        return;
    }
    if (*primeiro == no_remover) {
        *primeiro = no_remover->proximo;  // O primeiro nó agora aponta para o próximo nó
        free(no_remover);
        return;
    }

    // Percorre a lista para encontrar o nó anterior ao nó a ser removido
    No* atual = *primeiro;
    while (atual != NULL && atual->proximo != no_remover) {
        atual = atual->proximo;
    }
    if (atual != NULL) {
        atual->proximo = no_remover->proximo;  // Pula o nó que será removido
        free(no_remover);
    }
}

void imprime_lista(No* primeiro) {
    if (primeiro == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No* atual = primeiro;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("null\n");
}

void libera_lista(No* primeiro) {
    No* atual = primeiro;
    No* proximo_no;

    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);  // Libera o nó atual
        atual = proximo_no;
    }
}

int main() {
    No* primeiro = NULL;  // O ponteiro para o primeiro nó é inicializado como NULL

    insere_no(&primeiro, 10);
    insere_no(&primeiro, 20);
    insere_no(&primeiro, 30);

    printf("Elementos da lista: ");
    imprime_lista(primeiro);

    No* atual = primeiro->proximo;
    insere_meio(atual, 25);

    printf("Lista após inserir 25 após 20: ");
    imprime_lista(primeiro);

    No* no_para_remover = atual->proximo; 
    remove_no(&primeiro, no_para_remover);

    printf("Lista após remover 25: ");
    imprime_lista(primeiro);

    libera_lista(primeiro);

    return 0;
}

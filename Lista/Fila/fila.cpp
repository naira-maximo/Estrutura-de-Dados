#include <iostream>
#include <stdexcept>

struct No {
    int valor;
    No* proximo;

    No(int v) : valor(v), proximo(nullptr) {}
};

void enfileirar(No** primeiro, No** ultimo, int valor) {
    No* novo = new No(valor);
    if (*ultimo == nullptr) { // Se a fila está vazia, o novo é tanto o início quanto o último
        *primeiro = novo;
    } else {
        (*ultimo)->proximo = novo; // ponteiro próximo aponta para o novo
    }
    *ultimo = novo; // ponteiro último atualiza para o novo
}

int desenfileirar(No** primeiro, No** ultimo) {
    if (*primeiro == nullptr) {
        throw std::runtime_error("Erro: a fila está vazia");
    }
    
    No* auxiliar = *primeiro;
    int valor = auxiliar->valor;
    
    *primeiro = (*primeiro)->proximo;
    
    if (*primeiro == nullptr) {
        *ultimo = nullptr;
    }

    delete auxiliar;
    return valor;
}

void imprimirFila(No* primeiro) {
    No* atual = primeiro;
    while (atual != nullptr) {
        std::cout << atual->valor << " ";
        atual = atual->proximo;
    }
    std::cout << "\n";
}

int main() {
    No* primeiro = nullptr;
    No* ultimo = nullptr;

    enfileirar(&primeiro, &ultimo, 1);
    enfileirar(&primeiro, &ultimo, 2);
    enfileirar(&primeiro, &ultimo, 3);

    imprimirFila(primeiro);

    std::cout << "\nDesenfileirado: " << desenfileirar(&primeiro, &ultimo) << "\n";
    imprimirFila(primeiro);

    std::cout << "\nDesenfileirado: " << desenfileirar(&primeiro, &ultimo) << "\n";
    imprimirFila(primeiro);

    std::cout << "\nDesenfileirado: " << desenfileirar(&primeiro, &ultimo) << "\n";
    imprimirFila(primeiro);

    return 0;
}
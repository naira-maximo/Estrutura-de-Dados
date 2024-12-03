#include <stdio.h>

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_index]) {
                min_index = j;
            }
        }

        troca(&lista[i], &lista[min_index]);
        printf("Passo %d: ", i + 1);
        imprime_lista(lista, n);
    }
}

void imprime_lista(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int lista[] = {100, 90, 64, 35, 22, 12, 5, 1};
    // int lista[] = {1, 5, 12, 22, 35, 64, 90, 100};
    int n = sizeof(lista) / sizeof(lista[0]);

    printf("Lista original: ");
    imprime_lista(lista, n);

    selection_sort(lista, n);

    printf("Lista ordenada: ");
    imprime_lista(lista, n);

    return 0;
}
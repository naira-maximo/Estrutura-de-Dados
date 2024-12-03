#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int arr[], int primeiro, int ultimo) {
    int pivo = arr[ultimo];
    int i = primeiro - 1;

    for (int j = primeiro; j <= ultimo - 1; j++) {
        printf("Comparando arr[%d] = %d com pivo = %d\n", j, arr[j], pivo);
        if (arr[j] <= pivo) {
            i++;
            troca(&arr[i], &arr[j]);
            printf("Troca: ");
            imprimeArray(arr, ultimo + 1);
        }
    }
    troca(&arr[i + 1], &arr[ultimo]);
    printf("Troca final com pivo: ");
    imprimeArray(arr, ultimo + 1);
    return (i + 1); // Retorna a posição do pivô
}

void quickSort(int arr[], int primeiro, int ultimo) {
    if (primeiro < ultimo) {
        int pi = particiona(arr, primeiro, ultimo); // índice do pivô

        printf("\nQuick Esquerda:");
        quickSort(arr, primeiro, pi - 1);
        printf("\nQuick Direita:");
        quickSort(arr, pi + 1, ultimo); 
    }
}

void imprimeArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 9, 8, 7, 5, 4, 1};
    // int arr[] = {10, 7, 8, 9, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray original:");
    imprimeArray(arr, n);

    printf("\nStart QuickSort:\n");
    quickSort(arr, 0, n - 1);

    printf("\nArray ordenado:");
    imprimeArray(arr, n);

    return 0;
}

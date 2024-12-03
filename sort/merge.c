#include <stdio.h>
#include <stdlib.h>

void imprimeArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int esquerda[n1];
    int direita[n2];

    for (int i = 0; i < n1; i++)
        esquerda[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        direita[j] = arr[meio + 1 + j];

    printf("\nArray esquerda: ");
    imprimeArray(esquerda, n1);
    printf("Array direita: ");
    imprimeArray(direita, n2);

    int i = 0;
    int j = 0;
    int k = inicio;

    // Mescla os arrays temporários de volta ao array original
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            arr[k] = esquerda[i];
            i++;
        } else {
            arr[k] = direita[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim);

        printf("\nMergeSort = %d: ", fim);
        imprimeArray(arr, fim + 1);
    }
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 1, 2, 3};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    imprimeArray(arr, tamanho);

    mergeSort(arr, 0, tamanho - 1);

    printf("\nArray ordenado: \n");
    imprimeArray(arr, tamanho);

    return 0;
}

void insertion_sort(int n, int v[]) {
    int i, j, valor;
    for (j = 1; j < n; j++) {
        valor = v[j];
        // Move os elementos maiores para a direita
        for (i = j - 1; i >= 0 && v[i] > valor; i--) {
            v[i + 1] = v[i];
        }
        // Insere o valor no lugar correto
        v[i + 1] = valor;
    }
}

void print_array(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n = 20;
    int v[20] = {29, 10, 14, 37, 13, 5, 3, 1, 7, 25, 15, 11, 8, 19, 33, 20, 30, 22, 2, 17};

    printf("Vetor original: ");
    print_array(n, v);

    int i, j, valor;
    for (j = 1; j < n; j++) {
        valor = v[j];
        printf("\nInserindo o valor %d:\n", valor);
        
        for (i = j - 1; i >= 0 && v[i] > valor; i--) {
            v[i + 1] = v[i];
            printf("Deslocando: ");
            print_array(n, v);
        }
        
        v[i + 1] = valor;
        printf("Vetor atualizado com valor %d: ", valor);
        print_array(n, v);
    }

    printf("\nVetor ordenado final: ");
    print_array(n, v);

    return 0;
}
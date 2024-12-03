#include <stdio.h>

// void shell(int array[], int n) {
//     for (int gap = n / 2; gap > 0; gap /= 2) {
//         for (int i = gap; i < n; i++) {
//             int temp = array[i];
//             int j;
            
//             for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
//                 array[j] = array[j - gap];
//             }
//             array[j] = temp;
//         }
//         printf("Gap %d: ", gap);
//         for (int k = 0; k < n; k++) {
//             printf("%d ", array[k]);
//         }
//         printf("\n");
//     }
// }

void shell(int array[], int n) {
    int max_gaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        max_gaps++;
    }
    int* gaps = (int*)malloc(max_gaps * sizeof(int));

    int gap = n / 2;
    int num_gaps = 0;
    while (gap > 0) {
        gaps[num_gaps++] = gap;
        gap /= 2;
    }

    for (int g = 0; g < num_gaps; g++) {
        gap = gaps[g];
        for (int i = gap; i < n; i++) {
            int temp = array[i];
            int j;
            
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        printf("Gap %d: ", gap);
        for (int k = 0; k < n; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
    free(gaps);
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {12, 34, 54, 23, 3, 1, 45, 56, 89, 78, 67, 41, 33, 25};
    // int array[] = {12, 34, 54, 23, 3, 1, 45, 56, 89};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    printArray(array, n);

    shell(array, n);

    return 0;
}

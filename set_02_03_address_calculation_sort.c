#include <stdio.h>
#include <stdlib.h>

void addressCalculationSort(int arr[], int n, int maxValue) {
    // create an auxiliary array (initialized to 0)
    int *aux = (int *)calloc(maxValue + 1, sizeof(int));

    // count occurrences of each element
    for (int i = 0; i < n; i++) {
        aux[arr[i]]++;
    }

    // reconstruct the sorted array
    int k = 0;
    for (int i = 0; i <= maxValue; i++) {
        while (aux[i] > 0) {
            arr[k++] = i;
            aux[i]--;
        }
    }

    free(aux);
}

int main() {
    int arr[] = {25, 12, 11, 22, 25, 12, 64};
    int n = sizeof(arr) / sizeof(arr[0]);

    // assume we know the max value (like in bucket sort)
    int maxValue = 64;

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    addressCalculationSort(arr, n, maxValue);

    printf("\nSorted array:   ");
    for (in

#include <stdio.h>
#include <stdlib.h>

// Get maximum value in array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting sort according to digit (exp = 1 for ones, 10 for tens, etc.)
void countingSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert count[] so that it contains actual positions
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output back into arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

// Radix sort function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Sort for each digit (exp = 1, 10, 100, …)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    radixSort(arr, n);

    printf("\nSorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Helper function to merge two sorted halves
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Structure to represent a range (like recursive parameters)
typedef struct {
    int l, r, state;
} Frame;

// Iterative Merge Sort using stack
void mergeSortIterative(int arr[], int n) {
    Frame *stack = (Frame*) malloc(n * 2 * sizeof(Frame)); // stack
    int top = -1;

    // Push initial problem
    stack[++top] = (Frame){0, n - 1, 0};

    while (top >= 0) {
        Frame cur = stack[top--];

        int l = cur.l;
        int r = cur.r;
        int state = cur.state;

        if (l >= r) continue; // single element

        if (state == 0) {
            // Simulate recursion:
            // 1. After left & right, we merge
            stack[++top] = (Frame){l, r, 1};

            int m = l + (r - l) / 2;

            // Push right part
            stack[++top] = (Frame){m + 1, r, 0};
            // Push left part
            stack[++top] = (Frame){l, m, 0};
        }
        else {
            // state == 1 → time to merge
            int m = l + (r - l) / 2;
            merge(arr, l, m, r);
        }
    }

    free(stack);
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Example usage
int main() {
    int n ; scanf("%d",&n) ;
    int arr[n] ; for(int i = 0 ; i < n ; i ++) scanf("%d",arr + i) ;

    printf("Original array:\n");
    printArray(arr, n);

    mergeSortIterative(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

// Inlined merge function with loop interchange
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort left and right halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Inlined merge logic with loop interchange
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArray[n1], rightArray[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            leftArray[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArray[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        // Apply loop interchange: single merged loop
        for (k = left; k <= right; k++) {
            if (i >= n1) {
                arr[k] = rightArray[j++];
            } else if (j >= n2) {
                arr[k] = leftArray[i++];
            } else if (leftArray[i] <= rightArray[j]) {
                arr[k] = leftArray[i++];
            } else {
                arr[k] = rightArray[j++];
            }
        }
    }
}

// Main function
int main() {
    int arr[ARRAY_SIZE];
    srand(time(0));

    // Initialize array with random integers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 10000;
    }

    printf("Unsorted array (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("...\n");

    // Perform merge sort
    merge_sort(arr, 0, ARRAY_SIZE - 1);

    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("...\n");

    return 0;
}

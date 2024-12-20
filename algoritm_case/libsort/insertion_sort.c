#include "libsort.h"


// O(n**2)
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int k = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}


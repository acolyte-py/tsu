#include "libsort.h"


// O(n**2)
void selection_sort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int max = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}


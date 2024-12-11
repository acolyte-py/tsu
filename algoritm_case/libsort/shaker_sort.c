#include "libsort.h"


// O(n**2)
void shaker_sort(int arr[], int n) {
    int i, j, temp;
    int left = 0; 
    int right = n - 1;
    int new_left, new_right;

    while (left < right) {
        new_left = right;
        new_right = left;

        for (j = left; j < right; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                new_right = j;
            }
        }
        right = new_right;

        for (j = right; j > left; j--) {
            if (arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                new_left = j;
            }
        }
        left = new_left;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 100


void print_array(int arr[], int n) {
    printf("Массив - [");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}


int max_element(int arr[], int n) {
    int max_element = arr[0];
    int max_index = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_element) {
            max_index = i;
            max_element = arr[i];
        }
    }

    return max_index;
}


void sequence(int arr[], int n) {
    int index = max_element(arr, n);

    int res1 = index;
    int res2 = index;
    int cur = 1;
    int max = 1;
    
    for(int i = index + 1; i < n; i++) {
        if(arr[i] < arr[i - 1]) {
            cur++;
            if(cur > max) {
                max = cur;
                res1 = i - cur + 1;
                res2 = i;
            }
        } else {
            cur = 1;
        }
    }
    
    if(index + 1 == n) {
        puts("В массиве нет убывающий последовательности!");
    } else {
        printf("Последовательность - [%d, %d]\n", res1, res2);
    }
}


int main() {
    int n, res;

    printf("Введите размер массива: ");
    scanf("%i", &n);
    srand(time(0));

    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    print_array(arr, n);

    res = max_element(arr, n);
    printf("Индекс максимального элемента - [%d]\n", res);
    sequence(arr, n);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_VALUE 100


void print_array(int arr[], int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n - 1) {
            printf(" ");
        }
    }
    printf("] ");
}


int max_number(int arr[], int n) {
    int max_element = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    return max_element;
}


int min_number(int arr[], int n) {
    int min_element = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min_element) {
            min_element = arr[i];
        }
    }

    return min_element;
}


int calc_d(int min_a, int max_a, int max_b, int max_c) {
    if (min_a > 0) {
        return max_b + (max_c / 2);
    } else {
        return 1 + max_a;
    }
}


int main() {
    srand(time(0));

    int n = 5;
    int a[MAX_VALUE];
    int b[MAX_VALUE];
    int c[MAX_VALUE];

    for(int i = 0; i < n; i++) {
        a[i] = (rand() % (2 * MAX_VALUE)) - MAX_VALUE;
        b[i] = (rand() % (2 * MAX_VALUE)) - MAX_VALUE;
        c[i] = (rand() % (2 * MAX_VALUE)) - MAX_VALUE;
        //arr[i] = rand() % MAX_VALUE;
    }

    print_array(a, n);
    print_array(b, n);
    print_array(c, n);

    int min_a = min_number(a, n);
    int max_a = max_number(a, n);
    int max_b = max_number(b, n);
    int max_c = max_number(c, n);

    printf("\n%i %i %i %i", min_a, max_a, max_b, max_c);
    printf("\nd равно: %i", calc_d(min_a, max_a, max_b, max_c));
    
    return 0;
}


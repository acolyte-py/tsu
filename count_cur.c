#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(int *arr, int n) {
    printf("[");
    for(int i = 0; i < n; i++){
        printf("%i", *(arr + i));
        if(i < n - 1){
            printf(" ");
        }
    }
    printf("]\n");
}


int count_cur(int *arr, int n, int b){
    int result = 0;
    for(int i = 0; i < n; i++){
        if(*(arr + i) == b){
            result++;
        }
    }
    return result;
}


int main(){
    srand(time(0));
    int n = 0;
    int b = 0;
    int res = 0;

    printf("Введите размер массива: ");
    scanf("%i", &n);

    printf("Введите число b (от 1 до 100): ");
    scanf("%i", &b);
    
    int *arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        *(arr + i) = rand() % 101;
    }

    print_array(arr, n);
    res = count_cur(arr, n, b);
    printf("Число - %i в массиве A: %i\n", b, res);

    free(arr);
    return 0;
}


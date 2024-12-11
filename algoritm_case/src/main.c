#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../libsort/libsort.h"


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


void measure_time(void (*func)(int[], int), int arr[], int n){
    clock_t t;
    t = clock();

    func(arr, n);

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf(" выполнилась за %f секунд\n", time_taken);
}


void bench_testing(void){
    int n = 10000;
    int arr[10000];
    int temp[10000];

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }
    
    printf("Сортировка пузырьком");
    memcpy(temp, arr, n * sizeof(int));
    measure_time(bubble_sort, temp, n);

    printf("Сортировка прямой вставки");
    memcpy(temp, arr, n * sizeof(int));
    measure_time(insertion_sort, temp, n);
    
    printf("Сортировка прямого выбора");
    memcpy(temp, arr, n * sizeof(int));
    measure_time(selection_sort, temp, n);
    
    //print_array(arr, n);
    printf("Сортировка Шейкера");
    memcpy(temp, arr, n * sizeof(int));
    measure_time(shaker_sort, temp, n);
    //print_array(temp, n);
}


int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("[ERROR] Укажите алгоритм сортровки: [bubble, insertion, selection, shaker]\n");
        printf("[ERROR] Либо укажите [bench] для тестирование производительности\n");
        return 1;
    }
    
    if(strcmp(argv[1], "bench") == 0){
        printf("Тестирование на производительность\n");
        bench_testing();
        return 1;
    }

    int n;

    printf("[INFO] Введите размер массива: ");
    scanf("%i", &n);
    srand(time(0));

    int arr[MAX_VALUE];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    
    print_array(arr, n);
    if(strcmp(argv[1], "bubble") == 0) {
        printf("Сортировка пузырьком:\n");
        bubble_sort(arr, n);
        print_array(arr, n);

    } else if(strcmp(argv[1], "insertion") == 0) {
        printf("Сортировка прямой вставки:\n");
        insertion_sort(arr, n);
        print_array(arr, n);

    } else if(strcmp(argv[1], "selection") == 0) {
        printf("Сортировка прямого выбора:\n");
        selection_sort(arr, n);
        print_array(arr, n);

    } else if(strcmp(argv[1], "shaker") == 0) {
        printf("Сортировка Шейкера:\n");
        shaker_sort(arr, n);
        print_array(arr, n); 
    } else {
        printf("[ERROR] Неизвестный алгоритм: %s\n", argv[1]);
        return 1;
    }

    return 0;
}


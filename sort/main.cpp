#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"cherish.h"


int main() {
    srand(time(NULL));  // 用于随机数生成的种子

    int size;
    printf("请输入数组大小: ");
    scanf_s("%d", &size);

    int* arr = NULL;
    // 将 end_bubble 的声明和初始化移到外部
    clock_t end_bubble = 0;

    int choice;
    do {
        printf("\n1. 生成随机数组\n");
        printf("2. 冒泡排序\n");
        printf("3. 选择排序\n");
        printf("4. 插入排序\n");
        printf("5. 快速排序\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            generateRandomArray(&arr, size);
            printf("随机数组生成成功:\n");
            printArray(arr, size);
            break; }
        case 2: {
            comparisons = 0;
            {
                clock_t start_bubble = clock();
                bubbleSort(arr, size);
                end_bubble = clock();
                printf("冒泡排序完成:\n");
                printArray(arr, size);
                printf("排序比较次数: %lld\n", comparisons);
                printf("排序时间: %f 秒\n", ((double)(end_bubble - start_bubble)) / CLOCKS_PER_SEC);
            }
            break; }
        case 3: {
            comparisons = 0;
            clock_t start_selection = clock();
            selectionSort(arr, size);
            clock_t end_selection = clock();
            printf("选择排序完成:\n");
            printArray(arr, size);
            printf("排序比较次数: %lld\n", comparisons);
            printf("排序时间: %f 秒\n", ((double)(end_selection - start_selection)) / CLOCKS_PER_SEC);
            break; }
        case 4: {
            comparisons = 0;
            clock_t start_insertion = clock();
            insertionSort(arr, size);
            clock_t end_insertion = clock();
            printf("插入排序完成:\n");
            printArray(arr, size);
            printf("排序比较次数: %lld\n", comparisons);
            printf("排序时间: %f 秒\n", ((double)(end_insertion - start_insertion)) / CLOCKS_PER_SEC);
            break; }
        case 5: {
            comparisons = 0;
            clock_t start_quick = clock();
            quickSort(arr, 0, size - 1);
            clock_t end_quick = clock();
            printf("快速排序完成:\n");
            printArray(arr, size);
            printf("排序比较次数: %lld\n", comparisons);
            printf("排序时间: %f 秒\n", ((double)(end_quick - start_quick)) / CLOCKS_PER_SEC);
            break; }
        case 0: {
            free(arr);  // 释放动态分配的数组内存
            printf("程序退出\n");
            break; }
        default: {
            printf("无效的选择，请重新输入\n"); }
        }
    } while (choice != 0);

    return 0;
}







#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"cherish.h"


int main() {
    srand(time(NULL));  // ������������ɵ�����

    int size;
    printf("�����������С: ");
    scanf_s("%d", &size);

    int* arr = NULL;
    // �� end_bubble �������ͳ�ʼ���Ƶ��ⲿ
    clock_t end_bubble = 0;

    int choice;
    do {
        printf("\n1. �����������\n");
        printf("2. ð������\n");
        printf("3. ѡ������\n");
        printf("4. ��������\n");
        printf("5. ��������\n");
        printf("0. �˳�\n");
        printf("��ѡ�����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            generateRandomArray(&arr, size);
            printf("����������ɳɹ�:\n");
            printArray(arr, size);
            break; }
        case 2: {
            comparisons = 0;
            {
                clock_t start_bubble = clock();
                bubbleSort(arr, size);
                end_bubble = clock();
                printf("ð���������:\n");
                printArray(arr, size);
                printf("����Ƚϴ���: %lld\n", comparisons);
                printf("����ʱ��: %f ��\n", ((double)(end_bubble - start_bubble)) / CLOCKS_PER_SEC);
            }
            break; }
        case 3: {
            comparisons = 0;
            clock_t start_selection = clock();
            selectionSort(arr, size);
            clock_t end_selection = clock();
            printf("ѡ���������:\n");
            printArray(arr, size);
            printf("����Ƚϴ���: %lld\n", comparisons);
            printf("����ʱ��: %f ��\n", ((double)(end_selection - start_selection)) / CLOCKS_PER_SEC);
            break; }
        case 4: {
            comparisons = 0;
            clock_t start_insertion = clock();
            insertionSort(arr, size);
            clock_t end_insertion = clock();
            printf("�����������:\n");
            printArray(arr, size);
            printf("����Ƚϴ���: %lld\n", comparisons);
            printf("����ʱ��: %f ��\n", ((double)(end_insertion - start_insertion)) / CLOCKS_PER_SEC);
            break; }
        case 5: {
            comparisons = 0;
            clock_t start_quick = clock();
            quickSort(arr, 0, size - 1);
            clock_t end_quick = clock();
            printf("�����������:\n");
            printArray(arr, size);
            printf("����Ƚϴ���: %lld\n", comparisons);
            printf("����ʱ��: %f ��\n", ((double)(end_quick - start_quick)) / CLOCKS_PER_SEC);
            break; }
        case 0: {
            free(arr);  // �ͷŶ�̬����������ڴ�
            printf("�����˳�\n");
            break; }
        default: {
            printf("��Ч��ѡ������������\n"); }
        }
    } while (choice != 0);

    return 0;
}







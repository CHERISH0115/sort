#pragma once
#include<stdlib.h>
#include<stdio.h>

// ȫ�ֱ��������ڼ�¼����Ƚϴ���
long long comparisons = 0;

void generateRandomArray(int** arr, int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void generateRandomArray(int** arr, int size) {
    *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*arr)[i] = rand() % 100;  // ����0��99�������
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;  // ÿ�αȽ϶����Ӽ�����
            if (arr[j] > arr[j + 1]) {
                // ���� arr[j] �� arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;  // ÿ�αȽ϶����Ӽ�����
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // ���� arr[i] �� arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;  // ÿ�αȽ϶����Ӽ�����
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;  // ÿ�αȽ϶����Ӽ�����
        if (arr[j] < pivot) {
            i++;
            // ���� arr[i] �� arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // ���� arr[i + 1] �� arr[high]
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

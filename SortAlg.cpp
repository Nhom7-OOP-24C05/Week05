#include "SortAlg.h"

void (*SortAlg::currentAlg)(float arr[], int n) = SortAlg::BubbleSort;

void SortAlg::SelectionSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        float temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void SortAlg::BubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SortAlg::InsertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void SortAlg::SetAlgorithm(void(*pAlg)(float[], int))
{
    if (pAlg != nullptr) currentAlg = pAlg;
}

void SortAlg::Sort(float arr[], int n)
{
    if (currentAlg != nullptr) currentAlg(arr, n);
}
#include "SeqList.h"


//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(SqList *&L) {
    int i, j, temp;
    for (i = 1; i < L->length; i++) {
        if (L->data[i] < L->data[i - 1]) {
            temp = L->data[i];
            for (j = i - 1; j >= 0 && L->data[j] > temp; j--)
                L->data[j + 1] = L->data[j];
            L->data[j + 1] = temp;
        }
    }
}

//’€∞Î≤Â»Î
void InsertSortP(SqList *&L) {
    int i, j, low, high, mid, temp;
    for (i = 1; i < L->length; i++) {
        if (L->data[i] < L->data[i - 1]) {
            temp = L->data[i];
            low = 0;
            high = i - 1;
            while(low <= high) {
                mid = (low + high) / 2;
                if (temp < L->data[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= low; j--)
                L->data[j + 1] = L->data[j];
            L->data[j + 1] = temp;
        }
    }
}

//œ£∂˚≈≈–Ú
void ShellSort(SqList *&L) {
    int i, j, d, temp;

    for (d = L->length / 2; d >= 1; d /= 2) {
        for (i = d; i < L->length; i++) {
            if (L->data[i] < L->data[i - d]) {
                temp = L->data[i];
                for (j = i - d; j >= 0 && L->data[j] > temp; j -= d)
                    L->data[j + d] = L->data[j];
                L->data[j + d] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {3, 4, 6, 5, 19, 11, 69, 12, 36, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    SqList *L;
    InitList(L);
    CreateList(L, arr, n);
    printf("Origin List: ");
    DispList(L);

    ShellSort(L);

    printf("Sort List:   ");
    DispList(L);
    DestoryList(L);
}

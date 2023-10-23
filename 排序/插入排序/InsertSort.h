#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

//使用顺序表
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

void InitList(SqList *&L) {
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

void CreateList(SqList *&L, ElemType a[], int n) {
    int i = 0, k = 0;
    L = (SqList *)malloc(sizeof(SqList));
    while(i < n) {
        L->data[k] = a[i];
        k++;
        i++;
    }
    L->length = k;
}

void DestoryList(SqList *&L) {
    free(L);
}

void DispList(SqList *L) {
    for(int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

//直接插入排序
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

//折半插入
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

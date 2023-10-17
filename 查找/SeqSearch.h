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

//顺序查找
int SeqSearch(SqList *L, ElemType k) {
    int i;
    for (i = 0; i < L->length && L->data[i] != k; i++);
    if (i == L->length)
        return -1;
    else
        return i;
}

//加哨兵
int SeqSearch1(SqList *L, ElemType k) {
    L->data[L->length] = k;
    int i;
    for (i = 0; L->data[i] != k; i++);
    if (i == L->length)
        return -1;
    else
        return i;
}

//二分查找
int BinSearch(SqList *L, ElemType k) {
    int low = 0, high = L->length - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == k)
            return mid;
        if (k < L->data[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

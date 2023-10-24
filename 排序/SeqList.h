#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

//Ê¹ÓÃË³Ðò±í
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

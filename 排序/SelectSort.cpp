#include "SeqList.h"

//所有元素后移一位，保证二叉树性质
void move_back(SqList *&L) {
    for (int i = L->length + 1; i >= 0; i--) {
        L->data[i + 1] = L->data[i];
    }
    L->length++;
}

void move_front(SqList *&L) {
    for (int i = 0; i < L->length; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
}

//简单选择排序
void SelectSort(SqList *&L) {
    for (int i = 0; i < L->length - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < L->length; j++)
            if (L->data[j] < L->data[min_index])
                min_index = j;
        if (min_index != i) {
            int temp = L->data[i];
            L->data[i] = L->data[min_index];
            L->data[min_index] = temp;
        }
    }
}

void HeadAdjust(SqList *&L, int k, int len) {
    //保存根节点
    int temp = L->data[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        //判断左右子树中最大值
        if (i < len && L->data[i] < L->data[i + 1])
            i++;
        //i记录最大值索引，根节点是最大值则不需要交换
        if (temp >= L->data[i])
            break;
        //使最大值位于根节点
        else {
            L->data[k] = L->data[i];
            k = i;
        }
    }
    L->data[k] = temp;
}

void BuildHeap(SqList *&L, int len) {
    for (int i = len / 2; i > 0; i--)
        HeadAdjust(L, i, len);
}

void HeapSort(SqList *&L) {
    int len = L->length;
    move_back(L);
    BuildHeap(L, len);
    int temp;
    for (int i = len; i > 0; i--) {
        temp = L->data[i];
        L->data[i] = L->data[1];
        L->data[1] = temp;
        HeadAdjust(L, 1, i - 1);
    }
    move_front(L);
}

int main() {
    int arr[] = {3, 4, 6, 5, 19, 11, 14, 15, 2, 1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    SqList *L;
    InitList(L);
    CreateList(L, arr, n);
    printf("Origin List: ");
    DispList(L);

    HeapSort(L);

    printf("Sort List:   ");
    DispList(L);
    DestoryList(L);
}

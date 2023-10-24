#include "SeqList.h"

//冒泡排序
void BubbleSort(SqList *&L) {
    int temp;
    for(int i = L->length - 1; i > 0; i--) {
        bool flag = false;
        for(int j = 0; j < i; j++) {
            if (L->data[j] > L->data[j + 1]) {
                temp = L->data[j];
                L->data[j] = L->data[j + 1];
                L->data[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

//分区
int Partition(SqList *&L, int low, int high) {
    int mid = L->data[low];
    while (low < high) {
        for (high; L->data[high] >= mid && low < high; high--);
        L->data[low] = L->data[high];
        for (low; L->data[low] <= mid && low < high; low++);
        L->data[high] = L->data[low];
    }
    L->data[low] = mid;
    return low;
}

void QuickSort(SqList *&L, int low, int high){
    if (low < high){
        int mid_index = Partition(L,low,high);
        QuickSort(L,low,mid_index-1);
        QuickSort(L,mid_index+1,high);
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

    QuickSort(L,0,L->length-1);

    printf("Sort List:   ");
    DispList(L);
    DestoryList(L);
}

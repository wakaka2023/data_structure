#include "InsertSort.h"

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

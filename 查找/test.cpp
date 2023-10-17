#include "SeqSearch.h"

int main() {
    int arr[] = {3, 4, 6, 7, 9, 11};
    SqList *L;
    InitList(L);
    CreateList(L, arr, 6);
    printf("List: ");
    DispList(L);

    int key = 3;
    printf("Key is: %d\n", key);

    int loc = BinSearch(L,key);
    printf("Index is: %d",loc);

    DestoryList(L);
}

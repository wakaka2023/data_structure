#include "C:\Users\35317\Desktop\新建文件夹\顺序表\顺序表.h"

/*
课本p40
*/

//以第一个为基准，小的放在其左侧，大的放在其右侧
bool t1(SqList *&L) {
    int i = 0, j = L->length - 1;
    ElemType e = L->data[0], tmp;
    while (i < j) {
        //从右向左找到一个小于等于e的(大于e则继续找)
        while(j > i && L->data[j] > e)
            j--;
        //从左向右找到一个大于e的(小于等于e则继续找)
        while(i < j && L->data[i] <= e)
            i++;
        //交换两者值
        if (i < j) {
            tmp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = tmp;
        }
    }
    //i=j时停止，交换位置i和位置0的值
    tmp = L->data[0];
    L->data[0] = L->data[i];
    L->data[i] = tmp;
    return true;
}

//解法二，类似快速排序
bool t1_2(SqList *&L) {
    int i = 0, j = L->length - 1;
    ElemType e = L->data[0];
    while (i < j) {
        //从右向左找到一个小于等于e的(大于e则继续找)
        while(j > i && L->data[j] > e)
            j--;
        L->data[i] = L->data[j];
        //从左向右找到一个大于e的(小于等于e则继续找)
        while(i < j && L->data[i] <= e)
            i++;
        L->data[j] = L->data[i];
    }
    L->data[i] = e;
}

//将奇数放在偶数前方(类似t1解法一)
bool t2(SqList *&L) {
    int i = 0, j = L->length - 1;
    ElemType tmp;
    while (i < j) {
        while(i < j && L->data[i] % 2 == 1)
            i++;
        while(i < j && L->data[j] % 2 == 0)
            j--;
        if (i < j) {
            tmp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = tmp;
        }
    }
    return true;
}

bool t2_2(SqList *&L) {
    int i = -1, j;
    ElemType tmp;
    for (j = 0; j < L->length; j++) {
        if (L->data[j] % 2 == 1) {
            i++;
            if (i != j) {
                tmp = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = tmp;
            }
        }
    }
    return true;
}

int main() {
    int arr[] = {6, 3, 4, 7, 9, 11};
    SqList *L;
    InitList(L);
    CreateList(L, arr, 6);
    printf("Origin List: ");
    DispList(L);

    t2_2(L);

    printf("New List: ");
    DispList(L);

}

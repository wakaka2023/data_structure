#include "C:\Users\35317\Desktop\�½��ļ���\˳���\˳���.h"

/*
�α�p40
*/

//�Ե�һ��Ϊ��׼��С�ķ�������࣬��ķ������Ҳ�
bool t1(SqList *&L) {
    int i = 0, j = L->length - 1;
    ElemType e = L->data[0], tmp;
    while (i < j) {
        //���������ҵ�һ��С�ڵ���e��(����e�������)
        while(j > i && L->data[j] > e)
            j--;
        //���������ҵ�һ������e��(С�ڵ���e�������)
        while(i < j && L->data[i] <= e)
            i++;
        //��������ֵ
        if (i < j) {
            tmp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = tmp;
        }
    }
    //i=jʱֹͣ������λ��i��λ��0��ֵ
    tmp = L->data[0];
    L->data[0] = L->data[i];
    L->data[i] = tmp;
    return true;
}

//�ⷨ�������ƿ�������
bool t1_2(SqList *&L) {
    int i = 0, j = L->length - 1;
    ElemType e = L->data[0];
    while (i < j) {
        //���������ҵ�һ��С�ڵ���e��(����e�������)
        while(j > i && L->data[j] > e)
            j--;
        L->data[i] = L->data[j];
        //���������ҵ�һ������e��(С�ڵ���e�������)
        while(i < j && L->data[i] <= e)
            i++;
        L->data[j] = L->data[i];
    }
    L->data[i] = e;
}

//����������ż��ǰ��(����t1�ⷨһ)
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

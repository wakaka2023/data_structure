#include "C:\Users\35317\Desktop\�½��ļ���\˳���\˳���.h"

/*
����p017
*/


//ɾ����СֵԪ�أ��ճ���ֵ�����һ��Ԫ���
bool t1(SqList *&L, ElemType &e) {
    if(ListEmpty(L)) {
        printf("List is Null");
        return false;
    }
    int pos = 0;
    for(int i = 1; i < L->length; i++) {
        if(L->data[i] < L->data[pos])
            pos = i;
    }


    e = L->data[pos];
    L->data[pos] = L->data[L->length - 1];
    L->length--;
    return true;
}

//����
bool t2(SqList *&L) {
    if(ListEmpty(L)) {
        printf("List is Null");
        return false;
    }
    ElemType tmp = 0;
    for (int i = 0; i < int(L->length / 2); i++) {
        tmp = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = tmp;
    }
    return true;
}

//ɾ��ֵΪe��Ԫ��
bool t3(SqList *&L, ElemType e) {
    int j = 0;
    for (int i = 0; i < L->length; i++) {
        //���ȵ�ֵ����L(�൱���µı�)����ȵ�����(������)
        if (e != L->data[i]) {
            L->data[j] = L->data[i];
            j++;
        }

    }
    L->length = j;
    return true;
}

//ɾ��ֵΪe��Ԫ��
bool t3_2(SqList *&L, ElemType e) {
    int j = 0;
    for (int i = 0; i < L->length; i++) {
        //��¼��ȵ�����k��֮���Ԫ��Ǩ��k��
        if (L->data[i] == e)
            j++;
        else
            L->data[i - j] = L->data[i];
    }
    L->length -= j;
    return true;
}

//ɾ����Χֵ��Ԫ��
bool t4(SqList *&L, ElemType s, ElemType t) {
    if (L->length == 0 || s >= t)
        return false;
    int j = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] > s && L->data[i] < t)
            j++;
        else
            L->data[i - j] = L->data[i];
    }
    L->length -= j;
    return true;
}

//ɾ����Χֵ��Ԫ��
bool t5(SqList *&L, ElemType s, ElemType t) {
    if(L->length == 0 || s > t)
        return false;
    int j = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] >= s && L->data[i] <= t)
            j++;
        else
            L->data[i - j] = L->data[i];
    }
    L->length -= j;
    return true;
}

//ɾ�������ظ�ֵ
bool t6(SqList *&L) {
    int k = 0;

    for (int i = 0; i < L->length; i++) {
        //�ж����һ��ѭ��ֵ�Ƿ����
        k = 0;
        for (int j = i + 1; j < L->length; j++) {
            //��¼��ȵ�����k��֮���Ԫ��Ǩ��k��
            if (L->data[i] == L->data[j])
                k++;
            else
                L->data[j - k] = L->data[j];
        }
        L->length -= k;
    }
    return true;
}

//ɾ�������ظ�ֵ
bool t6_answer(SqList *&L) {
    int i, j;
    for (i = 0, j = 1; j < L->length; j++) {
        //�൱�ڽ����ظ���Ԫ���²���L
        if (L->data[i] != L->data[j])
            L->data[++i] = L->data[j];
    }
    L->length = i + 1;
    return true;
}

//���������ϲ�һ�������
bool t7(SqList *A, SqList *B, SqList *&C) {
    int i = 0, j = 0, k = 0;
    bool a_flag = true, b_flag = true;
    while (i < A->length or j < B->length) {
        if (A->data[i] <= B->data[j]) {
            if (a_flag)
                C->data[k++] = A->data[i++];
            if (b_flag)
                C->data[k++] = B->data[j++];
        }
        if (i >= A->length)
            a_flag = false;
        if (j >= B->length)
            b_flag = false;
    }
    C->length = k;
    return true;
}

//���������ϲ�һ�������
bool t7_answer(SqList *A, SqList *B, SqList *&C) {
    int i = 0, j = 0, k = 0;
    while (i < A->length and j < B->length) {
        if (A->data[i] <= B->data[j])
            C->data[k++] = A->data[i++];
        else
            C->data[k++] = B->data[j++];
    }
    while(i < A->length)
        C->data[k++] = A->data[i++];
    while(i < B->length)
        C->data[k++] = B->data[i++];
    C->length = k;
    return true;
}

void Reverse(SqList *&L, int left, int right) {
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++) {
        ElemType tmp = L->data[left + i];
        L->data[left + i] = L->data[right - i];
        L->data[right - i] = tmp;
    }
}

//����n��Ԫ�ط���ǰm��Ԫ�ص�ǰ��
bool t8(SqList *&L, int m, int n) {
    Reverse(L, 0, L->length - 1);
    Reverse(L, 0, n - 1);
    Reverse(L, n, L->length - 1);
    return true;
}

//��������ֵΪe��Ԫ��
//�ҵ����������Ԫ�ؽ������Ҳ�����������������
bool t9(SqList *&L, ElemType e) {
    //���ֲ���
    int low = 0, high = L->length - 1,mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == e)
            break;
        else if (L->data[mid] < e)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (L->data[mid] == e && mid != L->length - 1){
        ElemType tmp = L->data[mid];
        L->data[mid] = L->data[mid+1];
        L->data[mid+1] = tmp;
    }

    if (low > high){
        int i;
        for (i=L->length-1;i>high;i--)
            L->data[i+1] = L->data[i];
        L->data[i+1] = e;
        L->length++;
    }
    return true;
}

int main() {
    int arr[] = {1, 3, 4, 7, 9, 11};
    SqList *L;
    InitList(L);
    CreateList(L, arr, 6);
    printf("Origin List: ");
    DispList(L);

    t9(L, 2);

    printf("New List: ");
    DispList(L);
    return 0;

}

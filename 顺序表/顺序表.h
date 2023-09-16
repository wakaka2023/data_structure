#define MaxSize 50             //������󳤶�
#include <stdlib.h>            //����malloc
#include <stdio.h>             //����printf��io����

typedef int ElemType;         //����ElemTypeΪint

typedef struct{               //����ṹ��
    ElemType data[MaxSize];    //�洢����
    int length;                //����
}SqList;

/*
L��������ָ�����
a������
n:���鳤��
�������鴴��˳���
*/
void CreateList(SqList *&L,ElemType a[], int n){
    int i =0,k=0;
    L = (SqList *)malloc(sizeof(SqList));    //�����ڴ�
    while(i<n){
        L->data[k]=a[i];    //����Ԫ�ز���˳���
        k++;
        i++;
    }
    L->length = k;          //˳����ȵ������鳤��
}

/*��ʼ��˳���*/
void InitList(SqList *&L){
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

/*����˳���*/
void DestoryList(SqList *&L){
    free(L);    //�ͷ��ڴ�
}

/*�ж�˳����Ƿ�Ϊ��*/
bool ListEmpty(SqList *&L){
    return (L->length == 0);
}

/*��ȡ˳�����*/
int ListLength(SqList *&L){
    return (L->length);
}

/*��ӡ˳���*/
void DispList(SqList *L){
    for(int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

/*��λ����*/
bool GetElem(SqList *L, int i, ElemType &e){
    if(i<1 || i>L->length){
        return false;
    }
    e=L->data[i];
    return true;
}

/*��ֵ����*/
int LocateElem(SqList *L,ElemType e){
    int i = 0;
    while(i<L->length && L->data[i] != e){
        i++;
    }
    if (i > L->length){
        return 0;      //�Ҳ���������(i>˳�����˵���Ҳ���)
    }
    else
        return ++i;   //�����߼�λ��(�߼�λ�ô�1��ʼ������λ�ô�0��ʼ)
}

/*
L��������ָ�����
i�������߼�λ��
e������Ԫ��
˳������Ԫ��*/
bool ListInsert(SqList *&L,int i,ElemType e){
    int j;
    //�жϷǷ�����λ��
    if (i<1 || i>L->length+1 || L->length==MaxSize)
        return false;

    i--;                             //תΪ����λ��
    for(j=L->length;j>i;j--)         //�����������
        L->data[j]=L->data[j-1];     //����
    L->data[i]=e;                    //����Ԫ��
    L->length++;                     //���³���
    return true;
}

/*
L��������ָ�����
i��ɾ���߼�λ��
e������ɾ��Ԫ��(������)
˳���ɾ��Ԫ��*/
bool ListDelete(SqList *&L,int i,ElemType &e){
    int j;
    if(i<1 || i>L->length)
        return false;
    i--;
    e=L->data[i];   //����ɾ��Ԫ��
    for(j=i;j<L->length;j++)      //��������
        L->data[j]=L->data[j+1];  //ǰ��
    L->length--;
    return true;
}


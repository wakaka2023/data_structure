#define MaxSize 50             //定义最大长度
#include <stdlib.h>            //包含malloc
#include <stdio.h>             //包含printf等io操作

typedef int ElemType;         //定义ElemType为int

typedef struct{               //定义结构体
    ElemType data[MaxSize];    //存储数据
    int length;                //长度
}SqList;

/*
L：引用型指针变量
a：数组
n:数组长度
根据数组创建顺序表
*/
void CreateList(SqList *&L,ElemType a[], int n){
    int i =0,k=0;
    L = (SqList *)malloc(sizeof(SqList));    //申请内存
    while(i<n){
        L->data[k]=a[i];    //数组元素插入顺序表
        k++;
        i++;
    }
    L->length = k;          //顺序表长度等于数组长度
}

/*初始化顺序表*/
void InitList(SqList *&L){
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

/*销毁顺序表*/
void DestoryList(SqList *&L){
    free(L);    //释放内存
}

/*判断顺序表是否为空*/
bool ListEmpty(SqList *&L){
    return (L->length == 0);
}

/*获取顺序表长度*/
int ListLength(SqList *&L){
    return (L->length);
}

/*打印顺序表*/
void DispList(SqList *L){
    for(int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

/*按位查找*/
bool GetElem(SqList *L, int i, ElemType &e){
    if(i<1 || i>L->length){
        return false;
    }
    e=L->data[i];
    return true;
}

/*按值查找*/
int LocateElem(SqList *L,ElemType e){
    int i = 0;
    while(i<L->length && L->data[i] != e){
        i++;
    }
    if (i > L->length){
        return 0;      //找不到返回零(i>顺序表长度说明找不到)
    }
    else
        return ++i;   //返回逻辑位置(逻辑位置从1开始，物理位置从0开始)
}

/*
L：引用型指针变量
i：插入逻辑位置
e：插入元素
顺序表插入元素*/
bool ListInsert(SqList *&L,int i,ElemType e){
    int j;
    //判断非法插入位置
    if (i<1 || i>L->length+1 || L->length==MaxSize)
        return false;

    i--;                             //转为物理位置
    for(j=L->length;j>i;j--)         //从右往左操作
        L->data[j]=L->data[j-1];     //后移
    L->data[i]=e;                    //插入元素
    L->length++;                     //更新长度
    return true;
}

/*
L：引用型指针变量
i：删除逻辑位置
e：返回删除元素(引用型)
顺序表删除元素*/
bool ListDelete(SqList *&L,int i,ElemType &e){
    int j;
    if(i<1 || i>L->length)
        return false;
    i--;
    e=L->data[i];   //返回删除元素
    for(j=i;j<L->length;j++)      //从左往右
        L->data[j]=L->data[j+1];  //前移
    L->length--;
    return true;
}


#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode * next;
} LinkNode;

//初始化单链表
void InitList(LinkNode *&L) {
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

//初始化循环单链表
void InitListC(LinkNode *&L) {
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = L;
}

//销毁单链表
void DestroyList(LinkNode *&L) {
    LinkNode *pre = L, *p = L->next;
    while(p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

//销毁循环单链表
void DestroyListC(LinkNode *&L) {
    LinkNode *pre = L, *p = L->next;
    while(p != L) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

//判断是否为空
bool ListEmpty(LinkNode *L) {
    return (L->next == NULL);
}

//获取长度
int ListLength(LinkNode *L) {
    int length = 0;
    LinkNode *p = L;
    while(p->next != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

//输出单链表
void DispList(LinkNode *L) {
    LinkNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


//输出循环单链表
void DispListC(LinkNode *L) {
    LinkNode *p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//按位获取元素
bool GetElem(LinkNode *L, int i, ElemType &e) {
    int j = 0;
    LinkNode *p = L;
    if (i <= 0)
        return false;
    while (p != NULL && j < i) {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
        else {
            e = p->data;
            return true;
        }
}

//按值获取元素
int LocateElem(LinkNode *L, ElemType e) {
    int i = 1;
    LinkNode *p = L->next;
    while(p != NULL && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return 0;
    else
        return i;
}

//指定位置插入元素
bool ListInsert(LinkNode *&L, int i, ElemType e) {
    int j = 0;
    LinkNode *p = L, *s;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

//按位删除元素
bool ListDelete(LinkNode *&L, int i, ElemType &e) {
    int j = 0;
    LinkNode *p = L;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else {
        if (p->next == NULL)
            return false;
        e = p->next->data;
        p->next = p->next->next;
        free(p->next);
        return true;
    }
}

//头插法
void CreateListH(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s;
    InitList(L);
    for (int i = 0; i < n; i++) {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

//尾插法
void CreateListT(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;
    for (int i = 0; i < n; i++) {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

//循环单链表尾插
void CreateListTC(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;
    for (int i = 0; i < n; i++) {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = L;
}

void CreateListH_1(LinkNode *&L) {
    int x;
    LinkNode *p;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    scanf("%d",&x);

    while (x!=9999){
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = x;
        p->next = L->next;
        L->next=p;
        scanf("%d",&x);
    }
}

void CreateListT_1(LinkNode *&L){
    LinkNode *p,*r;
    int x;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r=L;
    scanf("%d",&x);
    while (x!=9999){
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data=x;
        r->next=p;
        r=p;
        scanf("%d",&x);
    }
    r->next=NULL;
}

bool Insert(LinkNode *&L,int i,ElemType e){
    if (i<=0)
        return false;
    int j=0;
    LinkNode *p;
    p=L;
    while (p!=NULL && j<i-1){
        j++;
        p=p->next;
    }

    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool Delete1(LinkNode *&L,int i){
    if (i<=0)
        return false;
    int j=0;
    LinkNode *p = L,*r;

    while(p!=NULL && j<i-1){
        p=p->next;
        j++;
    }

    r=p->next;
    p->next = r->next;
    free(r);
    return true;
}




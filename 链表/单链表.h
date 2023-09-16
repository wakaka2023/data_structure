#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode * next;
} LinkNode;

//��ʼ��������
void InitList(LinkNode *&L) {
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

//��ʼ��ѭ��������
void InitListC(LinkNode *&L) {
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = L;
}

//���ٵ�����
void DestroyList(LinkNode *&L) {
    LinkNode *pre = L, *p = L->next;
    while(p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

//����ѭ��������
void DestroyListC(LinkNode *&L) {
    LinkNode *pre = L, *p = L->next;
    while(p != L) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

//�ж��Ƿ�Ϊ��
bool ListEmpty(LinkNode *L) {
    return (L->next == NULL);
}

//��ȡ����
int ListLength(LinkNode *L) {
    int length = 0;
    LinkNode *p = L;
    while(p->next != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

//���������
void DispList(LinkNode *L) {
    LinkNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


//���ѭ��������
void DispListC(LinkNode *L) {
    LinkNode *p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//��λ��ȡԪ��
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

//��ֵ��ȡԪ��
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

//ָ��λ�ò���Ԫ��
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

//��λɾ��Ԫ��
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

//ͷ�巨
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

//β�巨
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

//ѭ��������β��
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




#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode;

void InitList(DLinkNode *&L) {
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->next = NULL;
    L->prior = NULL;
}

void DestroyList(DLinkNode *&L) {
    DLinkNode *pre = L, *p = L->next;
    while(p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

void DispList(DLinkNode *L) {
    DLinkNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void CreateListH(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->next = NULL;
    L->prior = NULL;

    for (int i; i < n; i++) {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;
        if (L->next != NULL)
            L->next->prior = s;
        s->prior = L;
        L->next = s;
    }
}

void CreateListT(DLinkNode *&L, ElemType a[], int n) {
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->next = NULL;
    L->prior = NULL;
    DLinkNode *s, *r = L;

    for (int i; i < n; i++) {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->prior = r;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

bool ListInsert(DLinkNode *&L, ElemType e, int i) {
    if (i <= 0)
        return false;

    int j = 0;
    DLinkNode *p = L, *s;

    while (p != NULL && j < i - 1) {
        j++;
        p = p->next;
    }

    if (p == NULL)
        return false;

    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s->data = e;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool ListDelete(DLinkNode *&L,int i,ElemType &e){
    if (i<=0)
        return false;

    int j;
    DLinkNode *p=L,*q;
    while (p!=NULL && j<i-1){
        j++;
        p=p->next;
    }

    if (p==NULL || p->next==NULL)
        return false;

    q = p->next;
    e = q->data;
    p->next = q->next;
    if (q->next!=NULL)
        q->next->prior = p;
    free(q);
    return true;
}

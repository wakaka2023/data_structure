#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct Snode {
    ElemType data;
    struct Snode *next;
} LinkStrNode;

void StrAssign(LinkStrNode *&S, char carr[]) {
    LinkStrNode *p, *r;
    S = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = S;
    for (int i = 0; carr[i] != '\0'; i++) {
        p = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        p->data = carr[i];
        r->next = p;
        r = p;
    }
    r->next =  NULL;
}

void DestoryStr(LinkStrNode *&S) {
    LinkStrNode *pre = S, *p = S->next;
    while(p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

void StrCopy(LinkStrNode *&S, LinkStrNode *s) {
    LinkStrNode *p = s->next, *q, *r;
    S = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = S;
    while (p != NULL) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
}

bool StrEqual(LinkStrNode *s, LinkStrNode *t) {
    LinkStrNode *p = s->next, *q = t->next;
    while(p != NULL && q != NULL && p->data == q->data) {
        p = p->next;
        q = q->next;
    }
    if (p == NULL && q == NULL)
        return true;
    else
        return false;
}

int StrLength(LinkStrNode *S) {
    int i = 0;
    LinkStrNode *p = S->next;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

LinkStrNode *Concat(LinkStrNode *s, LinkStrNode *t) {
    LinkStrNode *str, *p = s->next, *q, *r;
    int flag = 0;
    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = str;
    while(p != NULL && flag < 2) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
        if (p == NULL) {
            p = t->next;
            flag++;
        }
    }
    r->next = NULL;
    return str;
}

LinkStrNode *SubStr(LinkStrNode *S, int i, int j) {
    LinkStrNode *str, *p = S->next, *q, *r;
    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next = NULL;
    r = str;

    if (i <= 0 || i > StrLength(S) || j < 0 || i + j - 1 > StrLength(S))
        return str;

    int k = 1;
    for (k; k < i; k++)
        p = p->next;
    for (k; k < i+j; k++) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
    return str;
}

LinkStrNode *InsertStr(LinkStrNode *s, LinkStrNode *t, int i) {
    LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next = NULL;
    r = str;
    if (i <= 0 || i > StrLength(s) + 1)
        return str;
    for (int k = 1; k < i; k++) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    while (p1 != NULL) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    while (p != NULL) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
    return str;
}

LinkStrNode *DeleteStr(LinkStrNode *s, int i, int j) {
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next = NULL;
    r = str;
    if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s))
        return str;
    for (int k = 1; k < i; k++) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    for (int k = 0; k < j; k++)
        p = p->next;
    while (p != NULL) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
    return str;
}

LinkStrNode *ReplaceStr(LinkStrNode *s,int i,int j,LinkStrNode *t){
    LinkStrNode *str,*p=s->next,*p1=t->next,*q,*r;
    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next = NULL;
    r = str;
    if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s))
        return str;
    for (int k = 0; k < i-1; k++) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    while (p1!=NULL){
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
        p=p->next;
    }
    while (p!=NULL){
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

void DispStr(LinkStrNode *s){
    LinkStrNode *p=s->next;
    while (p!=NULL){
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}


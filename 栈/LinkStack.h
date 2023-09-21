#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkstNode;

void InitStack(LinkstNode *&S) {
    S = (LinkstNode *)malloc(sizeof(LinkstNode));
    S->next = NULL;
}

void DestoryStack(LinkstNode *&S) {
    LinkstNode *pre = S, *p = S->next;
    while (p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

bool StackEmpty(LinkstNode *S) {
    return (S->next == NULL);
}

void Push(LinkstNode *&S, ElemType e) {
    LinkstNode *s;
    s = (LinkstNode *)malloc(sizeof(LinkstNode));
    s->data  = e;
    s->next = S->next;
    S->next = s;
}

bool Pop(LinkstNode *&S, ElemType &e) {
    if (S->next == NULL)
        return false;
    LinkstNode *p = S->next;
    e = p->data;
    S->next = p->next;
    return true;
}

bool GetTop(LinkstNode *S, ElemType &e) {
    if (S->next == NULL)
        return false;
    e = S->next->data;
    return true;
}

void DispStack(LinkstNode *S) {
    if (StackEmpty(S))
        printf("SqStack is null");
    else {
        LinkstNode *p = S->next;
        while (p != NULL) {
            printf("%c ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

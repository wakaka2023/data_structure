#include "C:\Users\35317\Desktop\�½��ļ���\����\������.h"
/*
P53
*/

void t1(LinkNode *&L, LinkNode *&A, LinkNode *&B) {
    //Aβ�壬Bͷ��
    LinkNode *p = L->next, *r, *q; //p����L,rָ��A��β
    A = L;
    r = A;
    B = (LinkNode *)malloc(sizeof(LinkNode));
    B->next = NULL;
    while (p != NULL) {
        r->next = p;
        r = p;
        p = p->next;
        q = p->next;
        p->next = B->next;
        B->next = p;
        p = q;
        printf("*");
    }
    printf("2");
    r->next = NULL;
}

//ɾ���������Ԫ��
void t2(LinkNode *&L) {
    LinkNode *p = L->next, *pre = L, *maxpre = pre, *maxp = p;
    while (p != NULL) {
        if (maxp->data < p->data) {
            maxp = p;
            maxpre = pre;
        }
        pre = p;
        p = p->next;
    }
    maxpre->next = maxpre->next->next;
    free(maxp);
}

//��������
void t3(LinkNode *&L) {
    LinkNode *p, *pre, *q;
    p = L->next->next;
    L->next->next = NULL;
    while (p != NULL) {
        q = p->next;
        pre = L;
        while(pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p=q;
    }
}

int main() {
    LinkNode *L;
    int arr[] = {1, 2, 6, 4, 5};
    InitList(L);
    CreateListT(L, arr, 5);
    printf("Origin List: ");
    DispList(L);

    t3(L);

    printf("New List: ");
    DispList(L);
    DestroyList(L);
    return 0;
}

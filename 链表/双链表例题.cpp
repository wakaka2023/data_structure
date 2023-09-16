#include "C:\Users\35317\Desktop\新建文件夹\链表\双链表.h"
/*
P58
*/

//逆置
void t1(DLinkNode *&L) {
    DLinkNode *p = L->next, *q;
    L->next = NULL;

    while (p != NULL) {
        q = p->next;
        p->next = L->next;
        if(L->next != NULL)
            L->next->prior = p;
        p->prior = L;
        L->next = p;
        p = q;
    }
}

//递增排序
void t2(DLinkNode *&L) {
    DLinkNode *p, *q,*r;
    p = L->next->next;
    L->next->next = NULL;

    while (p != NULL) {
        q = p->next;
        r = L;
        while (r->next!= NULL && r->next->data<p->data)
            r=r->next;
        p->next = r->next;
        if (r->next!=NULL)
            r->next->prior = p;
        p->prior = r;
        r->next = p;
        p=q;
    }
}

int main() {
    DLinkNode *L;
    int arr[] = {1, 2, 6, 4, 5};
    InitList(L);
    CreateListT(L, arr, 5);
    printf("Origin List: ");
    DispList(L);

    t1(L);

    printf("New List: ");
    DispList(L);
    DestroyList(L);
    return 0;
}

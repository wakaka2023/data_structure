#include "双链表.h"

//删除第一个值为e的元素
bool t1(DLinkNode *&L, ElemType e) {
    DLinkNode *p = L->next;
    while (p != L && p->data != e)
        p = p->next;

    if (p == L)
        return false;

    p->next->prior = p->prior;
    p->prior->next = p->next;
    free(p);
}

//判断双链表是否对称
void t2(DLinkNode *&L) {
    bool same = true;
    DLinkNode *p = L->next, *q = L->prior;

    while (same) {
        printf("%d:%d\n",p->data,q->data);
        if (p->data != q->data)
            same = false;
        else{
            if (p==q || p==q->prior)
                break;
            q=q->prior;
            p=p->next;
        }
    }
    printf("Is symmetric:%d\n",same);
}

int main() {
    DLinkNode *L;
    int arr[] = {1, 2, 3, 1, 1};
    InitListC(L);
    CreateListTC(L, arr, 5);
    printf("Origin List: ");
    DispListC(L);

    t2(L);

    printf("New List: ");
    DispListC(L);
    DestroyListC(L);
    return 0;
}

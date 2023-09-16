#include "C:\Users\35317\Desktop\新建文件夹\链表\单链表.h"

//循环单链表，统计其值为e个数
void t1(LinkNode *&L,ElemType e){
    int sum=0;
    LinkNode *p = L->next;
    while (p!=L){
        if (p->data == e)
            sum++;
        p = p->next;
    }
    printf("Value is %d,quantity is %d\n",e,sum);
}

int main() {
    LinkNode *L;
    int arr[] = {1, 2, 6, 4, 5};
    InitList(L);
    CreateListTC(L, arr, 5);
    printf("Origin List: ");
    DispListC(L);

    t1(L,1);

    printf("New List: ");
    DispListC(L);
    DestroyListC(L);
    return 0;
}

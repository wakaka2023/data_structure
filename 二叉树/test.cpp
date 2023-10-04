#include "btree.h"

int Nodes(BTNode *b){
    if (b==NULL)
        return 0;
    else
        return Nodes(b->lchild)+Nodes(b->rchild)+1;
}

int main(){
    BTNode *b;
    CreateBTree(b,"A(B(D(,G)),C(E,F))");
    DispBTree(b);
    printf("\n���������");
    PreOrder(b);
    printf("\n���������");
    InOrder(b);
    printf("\n���������");
    PostOrder(b);
    printf("\n���߶ȣ�%d",BTHeight(b));
    printf("\n�ڵ�����%d",Nodes(b));
    DestoryBTree(b);
    return 0;
}

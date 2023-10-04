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
    printf("\n先序遍历：");
    PreOrder(b);
    printf("\n中序遍历：");
    InOrder(b);
    printf("\n后序遍历：");
    PostOrder(b);
    printf("\n树高度：%d",BTHeight(b));
    printf("\n节点数：%d",Nodes(b));
    DestoryBTree(b);
    return 0;
}

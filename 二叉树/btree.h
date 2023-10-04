#include <stdlib.h>
#include <stdio.h>
#define MaxSize 50

typedef char ElemType;
typedef struct node {
    ElemType data;
    struct node *lchild, *rchild;
} BTNode;

void CreateBTree(BTNode *&b, char *str) {
    BTNode *St[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];
    while (ch != '\0') {
        switch(ch) {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL) {
                b = p;
            } else {
                switch(k) {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

void DestoryBTree(BTNode *&b){
    if (b!=NULL){
        DestoryBTree(b->lchild);
        DestoryBTree(b->rchild);
        free(b);
    }
}
BTNode *FindNode(BTNode *b,ElemType x){
    BTNode *p;
    if (b=NULL)
        return NULL;
    else if (b->data ==x)
        return b;
    else{
        p=FindNode(b->lchild,x);
        if (p!=NULL)
            return p;
        else
            return FindNode(b->rchild,x);
    }
}

int BTHeight(BTNode *b){
    int lchild,rchild;
    if (b==NULL)
        return 0;
    else{
        lchild = BTHeight(b->lchild);
        rchild = BTHeight(b->rchild);
        return (lchild>rchild?(lchild+1):(rchild+1));
    }
}

void DispBTree(BTNode *b) {
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild);
            if(b->rchild != NULL)
                printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

void DispChild(BTNode *b){
    printf("R:%c  L:%c  R:%c",
           b->data,
           b->lchild==NULL?'^':b->lchild->data,
           b->rchild==NULL?'^':b->rchild->data);
}

void visit(BTNode *b){
    printf("%c",b->data);
}

//遍历
void PreOrder(BTNode *b){
    if (b!=NULL){
        visit(b);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void InOrder(BTNode *b){
    if (b!=NULL){
        InOrder(b->lchild);
        visit(b);
        InOrder(b->rchild);
    }
}

void PostOrder(BTNode *b){
    if (b!=NULL){
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        visit(b);
    }
}

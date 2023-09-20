#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} DataNode;

//头节点，尾节点
typedef struct {
    DataNode *front, *rear;
} LinkQuNode;

void InitQueue(LinkQuNode *&Q) {
    Q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
    Q->front = Q->rear = NULL;
}

void DestoryQueue(LinkQuNode *&Q) {
    DataNode *pre = Q->front, *p;
    if (pre != NULL) {
        p = pre->next;
        while (p != NULL) {
            free(pre);
            pre = p;
            p = p->next;
        }
        free(pre);
    }
    free(q);
}

bool QueueEmpty(LinkQuNode *Q) {
    return (Q->rear == NULL);
}

void enQueue(LinkQuNode *&Q,ElemType e){
    DataNode *s;
    s = (DataNode *)malloc(sizeof(DataNode));
    s->data = e;
    s->next = NULL;
    if (Q->rear ==NULL)
        Q->front=Q->rear=s;
    else{
        Q->rear->next = p;
        Q->rear = p;
    }
}

bool deQueue(LinkQuNode *&Q,ElemType &e){
    DataNode *p;
    if (Q->rear == NULL)
        return false;
    p = Q->front;
    if (Q->rear==Q->front)
        Q->front=Q->rear=NULL;
    else
        Q->front = Q->front->next;
    e = p->data;
    free(p);
    return true;
}

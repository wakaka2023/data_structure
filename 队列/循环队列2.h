#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, count;
} SqQueue;

void InitQueue(SqQueue *&Q) {
    Q = (SqQueue *)malloc(sizeof(SqQueue));
    Q->front = Q->count = 0;
}

void DestoryQueue(SqQueue *&Q) {
    free(Q);
}

bool QueueEmpty(SqQueue *Q) {
    return (Q->count == 0);
}

bool enQueue(SqQueue *&Q, ElemType e) {
    if (Q->count==MaxSize)
        return false;
    int rear;
    rear = (Q->front+Q->count)%MaxSize;
    rear = (rear+1)%MaxSize;
    Q->data[rear] = e;
    Q->count++;
    return true;
}

bool deQueue(SqQueue *&Q, ElemType &e) {
    if (Q->count == 0)
        return false;
    Q->front = (Q->front+1)%MaxSize;
    e = Q->data[Q->front];
    Q->count--;
    return true;
}

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *&Q) {
    Q = (SqQueue *)malloc(sizeof(SqQueue));
    Q->front = Q->rear = -1;
}

void DestoryQueue(SqQueue *&Q) {
    free(Q);
}

bool QueueEmpty(SqQueue *Q) {
    return (Q->front == Q->rear);
}

bool enQueue(SqQueue *&Q, ElemType e) {
    if (Q->rear == MaxSize - 1)
        return false;
    Q->data[++Q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&Q, ElemType &e) {
    if (Q->front == Q->rear)
        return false;
    e = Q->data[++Q->front];
    return true;
}

//循环队列
void InitQueueC(SqQueue *&Q) {
    Q = (SqQueue *)malloc(sizeof(SqQueue));
    Q->front = Q->rear = 0;
}

bool enQueueC(SqQueue *&Q, ElemType e) {
    if ((Q->rear + 1) % MaxSize == Q->front)
        return false;
    Q->rear = (Q->rear + 1) % MaxSize;
    Q->data[Q->rear] = e;
    return true;
}

bool deQueueC(SqQueue *&Q, ElemType &e) {
    if (Q->front == Q->rear)
        return false;
    Q->front = (Q->front + 1) % MaxSize;
    e = Q->data[++Q->front];
    return true;
}

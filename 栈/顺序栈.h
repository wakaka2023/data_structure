#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *&S) {
    S = (SqStack *)malloc(sizeof(SqStack));
    S->top = -1;    //指向栈顶下标
}

void DestoryStack(SqStack *&S) {
    free(S);
}

bool StackEmpty(SqStack *S) {
    return (S->top == -1);
}

bool Push(SqStack *&S, ElemType e) {
    if (S->top == MaxSize - 1)
        return false;
    S->top++;
    S->data[S->top] = e;
    return true;
}

bool Pop(SqStack *&S, ElemType &e) {
    if (S->top == -1)
        return false;
    e = S->data[S->top--];
    return true;
}

bool GetTop(SqStack *S, ElemType &e) {
    if (S->top == -1)
        return false;
    e = S->data[S->top];
    return true;
}

void DispStack(SqStack *S) {
    if (StackEmpty(S))
        printf("SqStack is null");
    else {
        for (int i = 0; i <= S->top; i++) {
            printf("%d ", S->data[i]);
        }
        printf("\n");
    }

}

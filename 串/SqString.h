#include <stdio.h>
#include <stdlib.h>
#define MaxSize 255

typedef char ElemType;
typedef struct {
    char data[MaxSize];
    int length;
} SqString;

void StrAssign(SqString &S, char cstr[]) {
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
        S.data[i] = cstr[i];
    S.length = i;
}

void StrCopy(SqString &S, SqString t) {
    for(int i = 0; i < t.length; i++)
        S.data[i] = t.data[i];
    S.length = t.length;
}

bool StrEqual(SqString s, SqString t) {
    bool same = true;
    if (s.length != t.length)
        same = false;
    else {
        for (int i = 0; i < s.length; i++) {
            if(s.data[i] != t.data[i]) {
                same = false;
                break;
            }
        }
    }
    return same;
}

//s和t拼接为S
void Concat(SqString s, SqString t, SqString &S) {
    S.length = s.length + t.length;
    for (int i = 0; i < s.length; i++)
        S.data[i] = s.data[i];
    for (int i = 0; i < t.length; i++)
        S.data[s.length + i] = t.data[i];
}

//start为逻辑位置
bool SubStr(SqString s, int start, int length, SqString &S) {
    if (start <= 0 || start > s.length || length < 0 || start + length - 1 > s.length)
        return false;
    for (int i = start - 1; i < start + length - 1; i++)
        S.data[i - start + 1] = s.data[i];
    S.length = length;
    return false;
}

//将t插入s的i（逻辑位置）位置，返回S
bool InsertStr(SqString &S,int i,SqString s,SqString t){
    if (i<=0 || i-1>s.length)
        return false;
    for (int j=0;j<i-1;j++)
        S.data[j] = s.data[j];
    for (int j=0;j<t.length;j++)
        S.data[i+j-1] = t.data[j];
    for (int j=i-1;j<s.length;j++)
        S.data[j+t.length] = s.data[j];
    S.length = s.length+t.length;
    return false;
}

//s中删除起始为i（逻辑位置），长度为j的字符，返回S
bool DeleteStr(SqString &S,SqString s,int i,int j){
    if (i<=0||i>s.length||i+j-1>s.length)
        return false;
    for (int k=0;k<i-1;k++)
        S.data[k] = s.data[k];
    for (int k = i+j-1;k<s.length;k++)
        S.data[k-j] = s.data[k];
    S.length = s.length-j;
    return true;
}

//将s中i（逻辑位置）开始，长度为j的子串替换为t，返回S
bool ReplaceStr(SqString &S,SqString s,SqString t,int i,int j){
    if (i<=0||i>s.length||i+j-1>s.length)
        return false;
    for (int k=0;k<i-1;k++)
        S.data[k]=s.data[k];
    for (int k=0;k<t.length;k++)
        S.data[i+k-1] = t.data[k];
    for (int k=i+j-1;k<s.length;k++)
        S.data[t.length+k-j] = s.data[k];
    S.length = s.length-j+t.length;
    return true;
}

void DispStr(SqString S){
    if (S.length>0){
        for (int i=0;i<S.length;i++)
            printf("%c",S.data[i]);
        printf("\n");
    }
}

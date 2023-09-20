#include "顺序栈.h"
#include <string.h>

//匹配括号
bool Match(char str[],int n){
    SqStack *st;
    InitStack(st);
    for (int i=0;i<n;i++){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(st,str[i]);
        else{
            if (StackEmpty(st))
                return false;
            char top;
            Pop(st,top);
            if (str[i] == ')' and top != '(')
                return false;
            if (str[i] == ']' and top != '[')
                return false;
            if (str[i] == '}' and top != '{')
                return false;
        }
    }
    return StackEmpty(st);
}

int main(){
    char str[] = "[][](";
    if (Match(str,strlen(str)))
        printf("yes");
    else
        printf("false");
    return 0;
}

#include "SqString.h"

//Brute-Force
int BF(SqString s,SqString t){
    int i=0,j=0;
    while (i<s.length&&j<t.length){
        if (s.data[i]==t.data[j]){
            i++;
            j++;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if (j>=t.length)
        //返回逻辑位置
        return (i-t.length+1);
    else
        return -1;
}

int main(){
    char arr[] = "Hello World!";
    char barr[] = "ello";
    SqString a,b,c;
    StrAssign(a,arr);
    StrAssign(b,barr);
    printf("Target string: ");
    DispStr(a);
    printf("Pattern string: ");
    DispStr(b);
    int result = BF(a,b);
    if (result == -1)
        printf("No match");
    else
        printf("Position is %d",result);
    return 0;
}

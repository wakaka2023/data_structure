#include "SqString.h"
#include <string.h>

void GetNext(SqString t, int next[]) {
    next[0] = -1;
    int i = 0, j = -1;
    while (i < t.length - 1) {
        if (j == -1 || t.data[i] == t.data[j]) {
            i++;
            j++;
            next[i] = j;
        } else
            j = next[j];
    }
}

void GetNextVal(SqString t, int nextval[]) {
    int i = 0, j = -1;
    nextval[0] = -1;
    while (i < t.length) {
        if (j == -1 || t.data[i] == t.data[j]) {
            i++;
            j++;
            if (t.data[i] != t.data[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else
            j = nextval[j];
    }
}

int KMP(SqString s, SqString t, int next[]) {
    int i = 0, j = 0;
    while (i < s.length && j < t.length) {
        if (j == -1 || s.data[i] == t.data[j]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (j >= t.length)
        return (i - t.length);
    else
        return -1;
}

void DispArr(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    char arr[] = "adbbbbbbbbadadadadadabaabcfgfbababababafafa";
    char barr[] = "abaabc";
    int next[strlen(barr)], nextval[strlen(barr)];

    SqString a, b;
    StrAssign(a, arr);
    StrAssign(b, barr);
    printf("Target string: ");
    DispStr(a);
    printf("Pattern string: ");
    DispStr(b);

    GetNext(b, next);
    GetNextVal(b, nextval);
    printf("Next Array: ");
    DispArr(next, strlen(barr));
    printf("Next Valid Array: ");
    DispArr(nextval, strlen(barr));

    int result1 = KMP(a, b, next);
    int result2 = KMP(a,b,nextval);
    printf("%d,%d\n",result1,result2);

    if (result1 == -1)
        printf("No match");
    else
        printf("Position is %d", result1);

    return 0;
}

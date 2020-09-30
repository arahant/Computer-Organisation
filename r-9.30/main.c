#include<stdio.h>
#include "util.c"

int read() {
    int a = 0;
    scanf("%d",&a);
    return a;
}

int main() {
    // function();
    scopes();
    pointers();
    int a = read();
    int b = read();
    printf("a=%d, b=%d\n",a,b);
    // swap(&a,&b);
    // printf("a=%d, b=%d\n",a,b);
    swap2(a,b);
    printf("a=%d, b=%d\n",a,b);
    return 0;
}

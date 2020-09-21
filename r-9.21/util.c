#ifndef UTIL_C_
#define UTIL_C_

#include <stdio.h>

void pointers(int n) {
    int *pn = &n;
    printf("n = %d\n", n);
    printf("pn = %p\n", (int*)pn);
}

void condition(int n) {
    if(n<0) {
        printf("1\n");
    }
    else if(n<=2 && n>=0) {
        printf("2\n");
    }
    else {
        printf("a large number\n");
    }
}

void loops(int n) {
    for(int i=0;i<n;i++) {
        printf("%d\n", i);
    }
    printf("loop ended\n");
}

void array(int n) {
    int arr[n];
    for(int i=0;i<n;i++) {
        arr[i] = i*2;
    }
    for(int i=0;i<n;i++) {
        printf("%d\n",arr[i]);
    }
}

#endif

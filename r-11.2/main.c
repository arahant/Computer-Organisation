#include<stdbool.h>

// gcc main.c
// objdump -d a.out

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int fib(int n) {
    if(n<=1)
        return n;

    return fib(n-1) + fib(n-2);
}

long compare(long x, long y) {
    long result;
    if (x > y)
        result = 1;
    else
        result = 0;
    return result;
}

bool boolean() {
    int a;
    int b;
    if(a==b)
        return true;
    else
        return false;
}

int loop(int n, int d, int g) {
    int i;
    int res;
    while(i<n) {
        i++;
        if(i == n)
            res = 1;
    }
    return res;
}

int main() {
    int a = 1;
    int b = 2;
    swap(&a, &b);
    compare(1,2);
    loop(5,8,7);
    fib(5);
    boolean();
    return 0;
}

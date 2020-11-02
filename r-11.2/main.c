#include<stdbool.h>

// gcc main.c
// objdump -d a.out

#define MAX 10
void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int fib(int n) {
    if(n<=1)
        return n;

    // return fib(n-1) + fib(n-2);
    int a = fib(n-1); //%rbp-12
    int b = fib(n-2);
    return a+b;
    // fib(n-1): %eax (n-1) -> %rbp-12 -> %ecx
    // fib(n-2): %eax
    // %ecx = %ecx + %eax

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

void array(int n) {
    int arr[MAX];
    for (int i=0;i<n;i++) {
        arr[i] = i;
    }
}

int main() {
    int a = 1;
    int b = 2;
    swap(&a, &b);
    compare(1,2);
    loop(5,8,7);
    fib(5);
    boolean();
    array(5);
    return 0;
}

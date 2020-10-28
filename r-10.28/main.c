void swap(int *a, int *b) {
    return;
    int c = *a;
    *a = *b;
    *b = c;
}

int fib(int n) {
    if(n==1)
        return 1;

    return fib(n-1) (%rbp -> %rax) + fib(n-2) (%rbp);
    // rbp, rax -> rbx
}

long compare(long x, long y) {
    long result;
    if (x > y)
        result = 1;
    else
        result = 0;
    return result;
}

void f1() {
    int a;
    int b;
    if(a==0)
        return;
    else
        return;
}

int loop(int n) {
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
    loop(5);
    fib(5);
    return 0;
}

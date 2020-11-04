#include "exercise.c"

// gcc main.c
// objdump -d a.out


void function1(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int function4(int n) {
    if(n<=1)
        return n;

    return function4(n-1) + function4(n-2);
    // int a = function4(n-1); //%rbp-12
    // int b = function4(n-2);
    // return a+b;
    // function4(n-1): %eax (n-1) -> %rbp-12 -> %ecx
    // function4(n-2): %eax
    // %ecx = %ecx + %eax

}

long function2(long x, long y) {
    long result;
    if (x > y)
        result = 1;
    else
        result = 0;
    return result;
}

int function3(int n, int d, int g) {
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
    function1(&a, &b);
    function2(1,2);
    function3(5,8,7);
    function4(5);
    function5();
    function6(5);
    return 0;
}

#include <stdio.h>

int main() {
    int n = 0, *pn;
    pn = &n;
    *pn = 33;
    printf("n = %d\n", n);
    printf("pn = %p\n", (int*)pn);
    return 0;
}

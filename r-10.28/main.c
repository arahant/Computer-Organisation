void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
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
    if(a>0)
        b=1;
    else
        b=-1;
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
    f1();
    return 0;
}

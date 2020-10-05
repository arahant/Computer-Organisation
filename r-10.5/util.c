#include<stdio.h>

// void function() {
//     int arr[] = {1,2,3,4,5};
//     int *ptr_arr[5];
//
//     // for(int i=0;i<5;i++)
//     ptr_arr = &arr;
//
//     for(int i=0;i<5;i++)
//         printf("%p %d\n",ptr_arr[i],*ptr_arr[i]);
// }

void scopes() {
    int a = 1;
    {
        int a;
        a += 5;
        printf("inner: %d\n",a);
    }
    printf("outer: %d\n",a);
}

void pointers() {
    char a = 1;
    char *x = &a;
    *x = 3;
    printf("x=%p, *x=%d\n",x, *x);
    char **xx = &x;
    **xx = 5;
    printf("x=%p, *x=%d\n",x, *x);
    printf("xx=%p *xx=%p **xx=%d\n", xx, *xx, **xx);
}

int read() {
    int a = 0;
    scanf("%d",&a);
    return a;
}

void swap(int *a, int *b) {
    int t = *a; //1,1,5
    *a = *b;    //1,5,5
    *b = t;     //1,5,1
}

void swap2(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

void util() {
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
}

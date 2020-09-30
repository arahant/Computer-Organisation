#include <stdio.h>

int read() {
    printf("--Reading\n");
    int n = 0;
    scanf("%d",&n);
    return n;
}

void pointers(int n) {
    printf("--Pointers\n");
    int* pn = &n;
    printf("n = %d\n", n);
    printf("pn = %p\n", (int*)pn);
}

void condition(int n) {
    printf("--Conditions\n");

    // switch case
    switch(n) {
        case 1:
            printf("1\n");
            break;
        case 2:
            printf("2\n");
            break;
        case 3: printf("3\n"); break;
        default: printf("nothing\n");
    }

    // if-then-else
    if(n<0) {
        printf("negative\n");
    }
    else if(n<=2 && n>=0) {
        printf("small number\n");
    }
    else {
        printf("large number\n");
    }
}

void loops(int n) {
    printf("--Loops\n");
    int i = 0;

    for(i=0;i<n;i++) {
        printf("%d\n", i);
    }
    printf("loop 1 ended\n");

    i = 0;
    while(i<n) {
        printf("%d\n", i);
        i++;
    }e
    printf("loop 2 ended\n");

    i=0;
    do {
        printf("%d\n", i);
        i++;
    } while(i<n);
    printf("loop 3 ended\n");
}

void array(int n) {
    printf("--Array\n");
    int arr[n];
    for(int i=0;i<n;i++) {
        arr[i] = i*2;
    }
    for(int i=0;i<n;i++) {
        printf("%d\n",arr[i]);
    }
}

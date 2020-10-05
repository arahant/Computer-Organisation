#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isprime(int n) {
    int c = 0;
    for(int i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            c += 1;
        }
    }
    if(c>2)
        return false;
    return true;
}

void prime(char **args) {
    int n = atoi(args[1]);
    bool v = isprime(n);
    if(v)
        printf("%d: prime\n",n);
    else
        printf("%d: not prime\n",n);
}

#include<stdio.h>
#include "util.c"
#include "prime.c"
#include "char_str.c"

int main(int n, char **args) {
    // util();
    prime(args);
    start(args);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void defunct() {
    printf("util.c");
    // printf("hello util");
}

void parse(char *name) {
    FILE *fp = fopen(name, "r");
    int MAX = 255;
    char buffer[MAX];
    // puts(name);
    while(fgets(buffer, MAX, fp)) {
        puts(buffer);
    }
    fclose(fp);
}

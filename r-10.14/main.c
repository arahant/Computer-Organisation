#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#include "diff.c"

struct diff* diff_list[MAX];

void compare(char buf1[MAX], char buf2[MAX]) {
    for(int i=0;i<MAX;i++) {
        char c1 = buf1[i];
        char c2 = buf2[i];
        // TODO: your code here
    }
}

void print() {
    for(int i=0;i<MAX;i++)
        print_diff(diff_list[i]);
}

int main(int n, char *args[]) {
    FILE *fp1 = fopen(args[1],"r");
    FILE *fp2 = fopen(args[2],"r");
    char buf1[MAX], buf2[MAX];
    bzero(buf1,MAX);
    bzero(buf2,MAX);
    while(fgets(buf1,MAX,fp1)!=NULL && fgets(buf2,MAX,fp2)!=NULL) {
        // puts(buf1);
        // puts(buf2);
        // compare(buf1,buf2);
    }
    // print();
    fclose(fp1);
    fclose(fp2);
    return 0;
}

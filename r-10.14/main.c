#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<stdbool.h>

#include "diff.c"

struct diff* diff_list[MAX];

int row = 0;
int col = 0;
int it = 0;

bool ignore_case  = false;
bool ignore_space = false;
bool ignore_blank = false;

int str_cmp(char *buf1, char *buf2) {
    int diff = 0;
    if(ignore_case)
        diff = strcasecmp(buf1,buf2);
    else
        diff = strcmp(buf1,buf2);
    return diff;
}

int str_cmp_2(char *buf1, char *buf2) {
    int diff = 0;
    int i1=0, i2=0;
    while(i1<MAX && i2<MAX) {
        int a1 = (int) buf1[i1];
        int a2 = (int) buf2[i2];
        if(a1==0 || a1==10 || a2==0 || a2==10)
            break;
        if(ignore_space) {
            if(a1==32 || a2==32)
                continue;
        }
        if(ignore_case) {
            if(a1>=97) a1 -= 32;
            if(a2>=97) a2 -= 32;
        }
        diff = a1-a2;
        i1++;
        i2++;
    }
    return diff;
}

int str_diff(char *buf1, char *buf2) {
    int i=0;
    for(int i=0;i<MAX;i++)
        if(buf1[i]!=buf2[i])
            break;
    return i;
}

void compare(char buf1[MAX], char buf2[MAX]) {
    for(int i=0;i<MAX;i++) {
        if(str_cmp(buf1,buf2)!=0) {
            struct diff *node = save_diff(col/1024,row/1024,buf1,buf2);
            diff_list[it++] = node;
            break;
        }
        row++;
        col = str_diff(buf1,buf2);
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
        compare(buf1,buf2);
    }
    print();
    fclose(fp1);
    fclose(fp2);
    return 0;
}

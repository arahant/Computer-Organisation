#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<stdbool.h>
#include<math.h>

#include "diff.c"

struct diff* diff_list[MAX];

int row = -1;
int col = 0;
int it = 0;

bool ignore_case  = true;
bool ignore_space = false;
bool ignore_blank = false;

int diff_col(char *buf1, char *buf2) {
    int i=0;
    while(i<MAX && buf1[i]==buf2[i])
        i++;
    return i;
}

int str_cmp_o(char *buf1, char *buf2) {
    int diff = 0;
    if(ignore_case)
        diff = strcasecmp(buf1,buf2);
    else
        diff = strcmp(buf1,buf2);
    return diff;
}

int str_cmp(char *buf1, char *buf2) {
    int diff = 0;
    int i1=0, i2=0;
    int len = strlen(buf1)-strlen(buf2);
    while(i1<MAX && i2<MAX) {
        int a1 = (int) buf1[i1];i1++;
        int a2 = (int) buf2[i2];i2++;
        if(ignore_space && (a1==32 || a2==32)) {
            if(a1==32)
                i1++;
            if(a2==32)
                i2++;
            continue;
        }
        if(ignore_case) {
            if(a1>=97 && a1<=122) a1 -= 32;
            if(a2>=97 && a2<=122) a2 -= 32;
        }
        diff = a1-a2;
        if(diff!=0) {
            col = i1;
            break;
        }
    }
    // if(len==0)
        // return 0;
    // if(len!=0)
    // printf("%d %d %d -%s-\n",row,diff,col,buf1);
    return diff;
}

void compare(char buf1[MAX], char buf2[MAX]) {
    if(str_cmp(buf1,buf2)!=0) {
        struct diff *node = save_diff(col,row,buf1,buf2);
        diff_list[it++] = node;
    }
}

void print() {
    for(int i=0;i<it;i++)
        print_diff(diff_list[i]);
}

int main(int n, char *args[]) {
    FILE *fp1 = fopen(args[1],"r");
    FILE *fp2 = fopen(args[2],"r");
    char buf1[MAX], buf2[MAX];
    bzero(buf1,MAX);
    bzero(buf2,MAX);
    while(fgets(buf1,MAX,fp1)!=NULL && fgets(buf2,MAX,fp2)!=NULL) {
        row++;
        col = diff_col(buf1,buf2);
        compare(buf1,buf2);
    }
    print();
    fclose(fp1);
    fclose(fp2);
    return 0;
}

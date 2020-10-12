#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#define MAX 1024

char *diff1, diff2;
int ctr = 0;
int diff_ctr = 0;

void print_words(char *words[MAX], int n) {
    for(int i=0;i<n;i++)
        puts(words[i]);
}

void extract_words(char buf[MAX]) {
    char *stop = strchr(buf, '\0');
    int id1 = (int) (stop - buf);
    char *nl = strchr(buf, '\n');
    int id2 = (int) (nl - buf);
    int max = id1<id2?id1:id2;

    char *words[MAX];
    int i = -1;
    int c = 0;
    int a = 0;
    int w = 0;

    while(++i<max) {
        a = (int) buf[i];
        if((a>=65 && a<=90) || (a>=97 && a<=122)) {
            c++;
        }
        else {
            if(c>0) {
                char *word = malloc(sizeof(char)*c);
                strncpy(word,buf+i-c,c);
                words[w++] = word;
                word = NULL;
                c=0;
            }
        }
    }
    if(w>0)
        print_words(words,w);
}

// void diff(char *buf1, char *buf2) {
//     int i=0;
//     while(i<MAX) {
//         char c1 = buf1[i];
//         char c2 = buf2[i];
//         if(c1!=c2) {
//             diff_ctr = ctr;
//             diff1[i] = c1;
//             diff2[i] = c2;
//         }
//         ctr++;
//     }
// }

int main(int n, char *args[]) {
    FILE *fp = fopen(args[1],"r");
    char buf[MAX];
    bzero(buf,MAX);
    while(fgets(buf,MAX,fp)!=NULL) {
        extract_words(buf);
    }
    fclose(fp);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define MAX 1024

char *diff1, diff2;
int ctr = 0;
int diff_ctr = 0;

char** parse_words(char *buf) {
    char c;
    char word[MAX];
    char ** words;
    int i = 0;
    int j = 0;
    int w = 0;

    while(i<MAX) {
        c=buf[i];
        if(c!=' ' || c!='\0') {
            word[j++] = c;
        }
        if(j>0) {
            word[j] = '\0';
            j=0;
            words+w = word;
            w++;
        }
        i++;
    }
    return words;
}

void print_words(char **words) {
    char *word;
    int i=0;
    while((word=words[i])!=NULL)
        puts(word);
}

void diff(char *buf1, char *buf2) {
    int i=0;
    while(i<MAX) {
        char c1 = buf1[i];
        char c2 = buf2[i];
        if(c1!=c2) {
            diff_ctr = ctr;
            diff1[i] = c1;
            diff2[i] = c2;
        }
        ctr++;
    }
}

int main(int n, char *args[]) {
    FILE *fp = fopen(args[1],"r");
    char buf[MAX];
    while(fgets(buf,MAX,fp)!=NULL) {
        puts(buf);
        // char **words = parse_words(buf);
        // print_words(words);
        // insert_inorder(words); // store words
    }
    fclose(fp);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#include "node1d.c"

#define MAX 2048
#define KEY 26

struct node1d *head = NULL;

void insert_words(char *words[MAX], int n) {
    for(int i=0;i<n;i++) {
        // puts(words[i]);
        head = insert_node1d(head,words[i],KEY);
    }
}

void insert_word(char *word) {
    head = insert_node1d(head,word,KEY);
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
        insert_words(words,w);
}

int main(int n, char *args[]) {
    // Reading lines from a file
    FILE *fp = fopen(args[1],"r");
    char buf[MAX];
    bzero(buf,MAX);
    while(fgets(buf,MAX,fp)!=NULL) {
        extract_words(buf);
    }
    fclose(fp);

    // Reading words from user
    // char word[20] = "abc";
    // while(word[0]) {
    //     gets(word);
    //     // puts(word);
    //     insert_word(word);
    // }

    print_words(head);

    int res = lookup_node1(head, args[2], KEY);
    if(res==1)
        puts("word found");
    else
        puts("word not found");
    return 0;
}

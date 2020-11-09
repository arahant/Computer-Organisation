#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#include "node2d.c"

#define MAX 2048
#define KEY 26

#define APPEND_REAR_2D "appendRear2D"
#define APPEND_AFTER_2D "appendAfter2D"
#define APPEND_REAR_1D "appendRear1D"
#define APPEND_AFTER_1D "appendAfter1D"
#define PRINT_ALL "printAll"
#define PRINT_1D "print1D"
#define FIND_1D "find1D"
#define FIND_2D "find2D"

// void ungetch(int c) {
//     if (bufp >= MAX)
//       printf("ungetch: too many chars\n");
//     else
//       buf[bufp++] = c;
// }

struct node2d *head = NULL;

// int getword(char *word, int lim) {
//     int c;
//     void ungetch(int);
//     char *w = word;
//     while (isspace(c = getchar())) ;
//     if (c != EOF)
//       *w++ = c;
//     if (!isalpha(c)) {
//       *w = '\0';
//       return c;
//     }
//     for ( ; --lim > 0; w++)
//       if (!isalnum(*w = getchar())) {
//         ungetch(*w);
//         break;
//       }
//     *w = '\0';
//     return word[0];
// }

void extract_words(char buf[MAX], char *words[MAX]) {
    char *stop = strchr(buf, '\0');
    int id1 = (int) (stop - buf);
    char *nl = strchr(buf, '\n');
    int id2 = (int) (nl - buf);
    int max = id1<id2?id1:id2;

    int i = -1;
    int c = 0;
    int a = 0;
    int w = 0;

    // \w [a-zA-Z0-9]
    // appendRear2D hello world

    while(++i<max) {
        a = (int) buf[i];
        if((a>=65 && a<=90) || (a>=97 && a<=122) || (a>=48 && a<=57)) {
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
}

int execute_command(char *words[MAX]) {
    char *command = words[0];
    int res = 0;
    if(strcmp(command, APPEND_REAR_2D)) {
        puts(command);
        res = append_node2d_rear(head, words[1]);
    }
    else if(strcmp(command, APPEND_AFTER_2D)) {
        puts(command);

        res = append_node2d_after(head, words[1], words[2]);
    }
    else if(strcmp(command, APPEND_REAR_1D)) {
        puts(command);
        res = append_node1d_rear(head, words[1], words[2]);
    }
    else if(strcmp(command, APPEND_AFTER_1D)) {
        puts(command);
        res = append_node1d_after(head, words[1], words[2]);
    }
    else if(strcmp(command, PRINT_ALL)) {
        res = print_all(head);
        puts(command);
    }
    else if(strcmp(command, PRINT_1D)) {
        res = print_2d(head, words[1]);
        puts(command);
    }
    else if(strcmp(command, FIND_2D)) {
        int res = lookup_node2d(head, words[1]);
        if (res==1) puts("found");
        else puts("not found");
        puts(command);
    }
    else if(strcmp(command, FIND_1D)) {
        int res = lookup_node2d_1d(head, words[1]);
        if (res==1) puts("found");
        else puts("not found");
        puts(command);
    }
    return res;
}

// abc -> cso1 -> sally -> NULL
// alice -> NULL
// r2d2 -> cso -> abc -> NULL

// appendAfter1D abc cso
// print1D r2d2
// find2D r2d
// find1D sally

int main(int n, char *args[]) {
    // char *w;
    // getword(w, MAX);
    // puts(w);

    // Reading the command from user
    char command[MAX] = "abc";
    while(1) {
        gets(command);
        if(!command[0])
            break;
        char *words[MAX];
        extract_words(command, words);
        int res = execute_command(words);
        if(res == 0)
            break;
    }
    return 0;
}

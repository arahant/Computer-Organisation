#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#define MAX 2048

struct diff {
    int col;
    int row;
    char line1[MAX];
    char line2[MAX];
};

struct diff* save_diff(int c, int r, char l1[MAX], char l2[MAX]) {
    struct diff *node = (struct diff*) malloc(sizeof(struct diff));
    node->col = c;
    node->row = r;
    strcpy(node->line1,l1);
    strcpy(node->line2,l2);
    return node;
}

void print_diff(struct diff *node) {
    printf("r%dc%d\n",node->row+1,node->col+1);
    printf("< %s",node->line1);
    printf("---\n");
    printf("> %s",node->line2);
}

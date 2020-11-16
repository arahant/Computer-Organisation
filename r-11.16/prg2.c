#include<stdlib.h>

typedef struct node {
    char c;
    char *name;
    long id;
    struct node *next;
} node;

node * head = NULL;

char *mystery(node *n, long id) {
    node * temp = head;
    node * t = (node*) malloc(sizeof(node));
    while (n) {
        if (n->id == id)
            return n->name;
        n= n->next;
    }
    return NULL;
}

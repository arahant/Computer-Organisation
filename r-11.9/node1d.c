#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct node1d {
    char *data;
    struct node1d *next;
};

// inserting into the beginning of the list
struct node1d* insert_node1d_head(struct node1d *head, char *word) {
    struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
    temp->data = word;
    if(head==NULL) {
        temp->next = NULL;
        head = temp;
    }
    else {
        temp->next = head->next;
        head->next = temp;
    }
    return head;
}

struct node1d* insert_node1d_tail(struct node1d *head, char *word) {
    if(head==NULL) {
        struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
        temp->data = word;
        temp->next = NULL;
        head = temp;
        return head;
    }
    else {
        struct node1d *node = head;
        while(node->next!=NULL) {
            node = node->next;
        }
        if(node->next==NULL) {
            struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
            temp->data = word;
            temp->next = NULL;
            node->next = temp;
        }
        return head;
    }
}

int lookup_node1d(struct node1d *head, char *word) {
    struct node1d *temp = head;
    while(temp!=NULL && strcmp(temp->data, word)!=0)
        temp = temp->next;
    if(temp==NULL)
        return 0;
    else if(strcmp(temp->data, word)==0)
        return 1;
    return 0;
}

void print_1d(struct node1d *head) {
    struct node1d *temp = head;
    while(temp!=NULL) {
        printf("%s,",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

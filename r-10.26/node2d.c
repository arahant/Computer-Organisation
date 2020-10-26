#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct node2d {
    char *data;
    struct node2d *next;
};

// inserting into the beginning of the list
struct node2d* insert_node2d_head(struct node2d *head, char *word) {
    struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
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

/*struct node2d* insert_node2d_tail(struct node2d *head, char *word) {
    if(head==NULL) {
        struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
        temp->data = word;
        temp->next = NULL;
        head = temp;
        return head;
    }
    else {
        struct node2d *node = head;
        while(node->next!=NULL) {

        }
        struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
        temp->data = word;
        if(head==NULL)
        temp->next = NULL;
        else
        temp->next = head->next;
        head = temp;
        return head;
    }
}*/

/*void delete(int val) {
    struct node2d *temp = head;
    if(temp==NULL)
        return;
    else if(temp->next==NULL && temp->data==val) {
        temp = NULL;
        return;
    }
    else {
        while(temp->next!=NULL && temp->next->data!=val)
            temp = temp->next;
        if(temp->next!=NULL)
            temp->next = temp->next->next;
        return;
    }
}*/

int lookup_node2(struct node2d *head, char *word) {
    struct node2d *temp = head;
    while(temp!=NULL && strcmp(temp->data, word)!=0)
        temp = temp->next;
    if(temp==NULL)
        return 0;
    else if(strcmp(temp->data, word)==0)
        return 1;
    return 0;
}

void print_list(struct node2d *head) {
    struct node2d *temp = head;
    while(temp!=NULL) {
        printf("%s,",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

#include<stdio.h>
#include<stdlib.h>

struct list {
    char *data;
    struct list *next;
};

// inserting into the beginning of the list
struct list* insert_list_head(struct list *head, char *word) {
    struct list *temp = (struct list*) malloc(sizeof(struct list));
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

/*struct list* insert_list_tail(struct list *head, char *word) {
    if(head==NULL) {
        struct list *temp = (struct list*) malloc(sizeof(struct list));
        temp->data = word;
        temp->next = NULL;
        head = temp;
        return head;
    }
    else {
        struct list *node = head;
        while(node->next!=NULL) {

        }
        struct list *temp = (struct list*) malloc(sizeof(struct list));
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
    struct list *temp = head;
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

void print_list(struct list *head) {
    struct list *temp = head;
    while(temp!=NULL) {
        printf("%s,",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

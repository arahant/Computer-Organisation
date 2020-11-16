#include<stdlib.h>
#include<stdbool.h>

struct node {
    struct node *next;
    int data;
};

bool create(struct node *head, int v) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = v;
    if(!head) {
        head = node;
        node->next = NULL;
        return true;
    }
    struct node *temp = head;
    while(temp->next!=NULL || temp->next->data!=v) {
        temp = temp->next;
    }
    if(temp->next==NULL) {
        temp->next = node;
        node->next = NULL;
        return true;
    }
    else if(temp->next->data==v) {
        return false;
    }
    return false;
}

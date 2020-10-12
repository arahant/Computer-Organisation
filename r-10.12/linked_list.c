#include<stdio.h>
#include<stdlib.h>

struct list {
    int data;
    struct list *next;
};
struct list *head = NULL;

struct list* insert_inorder(struct list *temp, int val) {
    if(temp==NULL) {
        temp = (struct list*) malloc(sizeof(struct list));
        head = temp;
        temp->data = val;
        temp->next = NULL;
        return temp;
    }
    else {
        struct list *temp2 = (struct list*) malloc(sizeof(struct list));
        temp2->data = val;
        temp2->next = NULL;
        temp->next = temp2;
        return temp2;
    }
}

struct list* insert_sorted(struct list *temp, int val) {
    // TODO: your code goes here...
    return temp;
}

void delete(int val) {
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
}
// 1 2 3 4 5

void print() {
    struct list *temp = head;
    while(temp!=NULL) {
        printf("%d-",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int n, char *args[]) {
    int n1 = atoi(args[1]);
    int n2 = atoi(args[2]);
    if(n2>=n1) {
        printf("n2 cannot be greater than n1");
    }
    else {
        struct list *temp = head;
        int v;
        for(int i=0;i<n1;i++) {
            scanf("%d",&v);
            temp = insert_inorder(temp,v);
        }
        print();
        delete(n2);
        print();
    }
    return 0;
}

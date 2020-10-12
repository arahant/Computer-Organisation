#include<stdio.h>
#include<stdlib.h>

#include "linked_list.c"

struct htable {
    int hash;
    struct htable *next;
    struct list *root;
};
struct htable *head = NULL;

// arr =    [1,2,11,14,23,46,9,8,29,54]
// n%10 =   [1,2,1,4,3,6,9,8,9,4]
// htable = [[1,11],[2],[23],[14,54],[46],[9,29],[8]]

void insert(int v, int key) {
    struct htable *node = head;
    int h = v%key;
    while(node->next!=NULL && node->hash!=h) {
        node = node->next;
    }
    if(node->next==NULL) {

    }
    else {

    }
}

void print() {

}

int main(int n, char *args) {
    int n1 = atoi(args[1]);
    int key = atoi(args[2])
    if(n1>0 && key>0) {
        int v;
        for(int i=0;i<n1;i++) {
            scanf("%d",&v);
            insert(v,key);
        }
    }
    return 0;
}

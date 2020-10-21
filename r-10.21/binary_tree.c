#include<stdio.h>
#include<stdlib.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *root = NULL;

void insert(struct tree *node, int val) {
    //TODO: Your code here
}

void traverse(struct tree *node, int type) {
    if(node==NULL) return;
    if(type==1) printf("%d\n",node->data);
    traverse(node->left,bit);
    if(type==2) printf("%d\n",node->data);
    traverse(node->right,bit);
    if(type==3) printf("%d\n",node->data);
}

int main(int n, char **args) {
    int n1 = atoi(args[1]);
    int bit = atoi(args[2]); //1 for pre order, 2 for in order, 3 for post order
    if(n1>0 && bit>0) {
        int v;
        for(int i=0;i<n1;i++) {
            scanf("%d",&v);
            insert(root,v);
        }
        traverse(root,bit);
    }
    return 0;
}

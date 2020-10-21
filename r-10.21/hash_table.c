#include<stdio.h>
#include<stdlib.h>

#include "linked_list.c"

struct htable {
    int hash;               // hash value
    int count;              // count of words
    struct htable *next;    // points to next htable node
    struct list *root;      // points to root of word list
};

struct htable* insert_htable(struct htable *head, char *word, int key) {
    // getting the ascii value of 1st char of word
    // for lower case, ascii = [97,122]
    // for upper case, ascii = [65,90]
    int ascii = (int) word[0];
    int diff = 65;
    if(ascii>=97) diff += 32;
    // v is now in the range [0,25]
    int v = ascii - diff;
    // calculating the hash value
    int h = v%key;

    if(head==NULL) {
        // if this condition then the hash doesn't exist, so insert a new hash table node
        struct htable *temp = (struct htable*) malloc(sizeof(struct htable));
        temp->hash = h;
        temp->count = 1;
        temp->next = NULL;
        head = temp;
        temp->root = insert_list_head(temp->root,word);
        // printf("1. Inserting '%s'\t\twith hash\t%d\n",word,h);
    }
    else {
        struct htable *node = head;
        while(node->next!=NULL && node->next->hash!=h) {
            node = node->next;
        }
        if(node->next==NULL) {
            // if this condition then the hash doesn't exist, so insert a new hash table node
            struct htable *temp = (struct htable*) malloc(sizeof(struct htable));
            temp->hash = h;
            temp->count = 1;
            temp->next = NULL;
            node->next = temp;
            temp->root = insert_list_head(temp->root,word);
            // printf("2. Inserting '%s'\t\twith hash\t%d\n",word,h);
        }
        else if(node->next->hash==h) {
            // if this condition then the hash does exist, so just insert into the existing list
            node->next->count += 1;
            node->next->root = insert_list_head(node->next->root,word);
            // printf("3. Inserting '%s'\t\twith hash\t%d\n",word,h);
        }
    }
    return head;
}

void print_htable(struct htable *head) {
    struct htable *temp = head;
    while(temp!=NULL) {
        printf("%d\t: %d ",temp->hash+1,temp->count);
        print_list(temp->root);
        temp = temp->next;
    }
}

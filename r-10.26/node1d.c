#include<stdio.h>
#include<stdlib.h>

#include "node2d.c"

struct node1d {
    int hash;               // hash value
    int count;              // count of words
    struct node1d *next;    // points to next node1d node
    struct node2d *root;      // points to root of word list
};

int get_hash(char *word, int key) {
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
    return h;
}

struct node1d* insert_node1d(struct node1d *head, char *word, int key) {
    int h = get_hash(word, key);
    if(head==NULL) {
        // if this condition then the hash doesn't exist, so insert a new hash table node
        struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
        temp->hash = h;
        temp->count = 1;
        temp->next = NULL;
        head = temp;
        temp->root = insert_node2d_head(temp->root,word);
        // printf("1. Inserting '%s'\t\twith hash\t%d\n",word,h);
    }
    else {
        struct node1d *node = head;
        while(node->next!=NULL && node->next->hash!=h) {
            node = node->next;
        }
        if(node->next==NULL) {
            // if this condition then the hash doesn't exist, so insert a new hash table node
            struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
            temp->hash = h;
            temp->count = 1;
            temp->next = NULL;
            node->next = temp;
            temp->root = insert_node2d_head(temp->root,word);
            // printf("2. Inserting '%s'\t\twith hash\t%d\n",word,h);
        }
        else if(node->next->hash==h) {
            // if this condition then the hash does exist, so just insert into the existing list
            node->next->count += 1;
            node->next->root = insert_node2d_head(node->next->root,word);
            // printf("3. Inserting '%s'\t\twith hash\t%d\n",word,h);
        }
    }
    return head;
}

int lookup_node1(struct node1d *head, char *word, int key) {
    int h = get_hash(word, key);
    struct node1d *temp = head;
    while(temp!=NULL && temp->hash!=h)
        temp = temp->next;
    if(temp==NULL)
        return 0;
    else if(temp->hash==h)
        return lookup_node2(temp->root, word);
    return 0;
}

void print_words(struct node1d *head) {
    struct node1d *temp = head;
    while(temp!=NULL) {
        printf("%d\t: %d ",temp->hash+1,temp->count);
        print_list(temp->root);
        temp = temp->next;
    }
}

#include<stdio.h>
#include<stdlib.h>

#include "node1d.c"

struct node2d {
    int hash;               // hash value
    int count;              // count of words
    char *word;             // word stored
    struct node2d *down;    // points to down node2d node
    struct node1d *first;   // points to first of word list
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

//
int append_node2d_rear(struct node2d *head, char *word) {
    if(head==NULL) {
        // if this condition then the hash doesn't exist, so insert a new hash table node
        struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
        temp->word = word;
        temp->down = NULL;
        head = temp;
        // temp->first = insert_node1d_head(temp->first,word);
        // printf("1. Inserting '%s'\t\twith hash\t%d\n",word,h);
        return 1;
    }
    else {
        struct node2d *node = head;
        while(node->down!=NULL) {
            node = node->down;
        }
        if(node->down==NULL) {
            // if this condition then the hash doesn't exist, so insert a new hash table node
            struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
            temp->word = word;
            temp->down = NULL;
            node->down = temp;
            // temp->first = insert_node1d_head(temp->first,word);
            return 1;
            // printf("2. Inserting '%s'\t\twith hash\t%d\n",word,h);
        }
        return 0;
    }
}

int append_node2d_after(struct node2d *head, char *word, char* key) {
    if(head==NULL) {
        // if this condition then the hash doesn't exist, so insert a new hash table node
        struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
        temp->word = word;
        temp->down = NULL;
        head = temp;
        // temp->first = insert_node1d_head(temp->first,word);
        return 1;
    }
    else {
        struct node2d *node = head;
        while(node->down!=NULL && node->down->word!=key) {
            node = node->down;
        }
        if(node->down==NULL) {
            // struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
            // temp->word = word;
            // temp->down = NULL;
            // node->down = temp;
            // temp->first = insert_node1d_head(temp->first,word);
            return 0;
        }
        else if(node->down->word==key) {
            struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
            temp->word = word;
            temp->down = node->down;
            node->down = temp;
            // temp->first = insert_node1d_head(temp->first,word);
            return 1;
        }
        return 0;
    }
}

int append_node1d_rear(struct node2d *head, char *word, char* key) {
    if(head==NULL) {
        return 0;
    }
    else {
        struct node2d *node = head;
        // world1 hello world
        // appendRead1d hola hello
        while(node->down!=NULL && node->down->word!=key) {
            node = node->down;
        }
        if(node->down==NULL) {
            return 0;
        }
        else if(node->down->word==key) {
            insert_node1d_tail(node->down->first, word);
            return 1;
        }
        return 0;
    }
}

int append_node1d_after(struct node2d *head, char *word, char* key) {
    if(head==NULL) {
        return 0;
    }
    else {
        struct node2d *node = head;
        while(node!=NULL) {
            int res = insert_node1d_after(node->first, word, key);
            if(res==1) return 1;
        }
        return 0;
    }
}

//
int lookup_node2d(struct node2d *head, char *key) {
    struct node2d *temp = head;
    while(temp!=NULL && temp->word!=key)
        temp = temp->down;
    if(temp==NULL)
        return 0;
    else if(temp->word==word)
        return 1;
    return 0;
}

int lookup_node2d_1d(struct node2d *head, char *key) {
    struct node2d *temp = head;
    while(temp!=NULL) {
        int res = lookup_node1d(temp->first, key);
        if(res==1) return 1;
        temp = temp->down;
    }
    return 0;
}
//
int print_all(struct node2d *head) {
    struct node2d *temp = head;
    while(temp!=NULL) {
        printf("%s -> ",temp->word);
        print_1d(temp->first);
        temp = temp->down;
    }
    return 1;
}

int print_2d(struct node2d *head, char *name2d) {
    struct node2d *temp = head;
    while(temp!=NULL) {
        if(strcmp(temp->word, name2d)) {
            print_1d(temp->first);
            break;
        }
        temp = temp->down;
    }
    return 1;
}

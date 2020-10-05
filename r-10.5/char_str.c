#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// 1. checks lower case
bool check_lower_case(char *s) {
    int n = strlen(s);
    bool legal = true;
    int i;
    for(i=0;i<n;i++) {
        int a = (int) s[i];
        if(!(a>=97 && a<=122)) {
            legal = false;
            break;
        }
    }
    return legal;
}

// 2.
int check_occurence(char *a, char *b) {
    return 0;
}

void start(char **args) {
    char * str = args[2];
    char * except = args[3];
    bool res = check_lower_case(str);
    if(res) {
        check_occurence(str, except);
    }
    else {
        printf("%s illegal\n",str);
    }
}

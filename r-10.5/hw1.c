#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Q 1.
int q1(char **argv) {
    char *s = argv[2];
    int i=0, count=0;
    char c = s[i];
    while(c!='\0') {
        if(c=='a' || c=='A' || c=='e' || c=='E' || c=='U' || c=='u') {
            count ++;
            s[i] = '@';
        }
        i++;
        c = s[i];
    }
    printf("%s\n",s);
    return count;
}

// Q 4.
void q4() {
    char c;
    while(true) {
        c = getchar();
        int ascii = (int) c;

        if(ascii>=48 && ascii<=57) {
            printf("DIGIT\n");
        }
        else if(ascii>=65 && ascii<=90) {
            c += 32;
            putchar(c);
            putchar('\n');
        }
        else if(ascii>=97 && ascii<=122) {
            c -= 32;
            putchar(c);
            putchar('\n');
        }
        else {
            printf("ERROR\n");
            break;
        }
        c = getchar();
    }
}

// Q 5.
bool isprime(int n) {
    int c = 0;
    for(int i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            c += 1;
        }
    }
    if(c>2)
        return false;
    return true;
}

void q5(char **args) {
    int n = atoi(args[1]);
    bool v = isprime(n);
    if(v)
        printf("%d: prime\n",n);
    else
        printf("%d: not prime\n",n);
}


// Q 6.
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

int check_occurence(char *a, char *b) {
    return 0;
}

void q6(char **args) {
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

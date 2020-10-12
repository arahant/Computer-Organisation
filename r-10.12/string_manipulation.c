#include<stdio.h>
#include<stdlib.h>

#define MAX 1024

char** parse_words(char *buf) {

}



int main(int n, char *args[]) {
    FILE *fp = fopen(args[1],"r");
    char buf[MAX];
    while(fgets(buf,MAX,fp)!=NULL) {
        // puts(buf);
        char **words = parse_words();
        store_words(words);
    }
    fclose(fp);
    return 0;
}

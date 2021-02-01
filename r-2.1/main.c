#include "util.c"

int main(int args, char* argv[]) {
    printf("hello world\n");
    if(args > 0)
        parse(argv[0]);
    return 0;
}

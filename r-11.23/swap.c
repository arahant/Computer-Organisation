

extern int buf[];
int *bufp0 =&buf[0];
static int*bufp1;
int a = 1;

void func();

void swap() {
    int temp;
    bufp1 = &buf[1];
    temp = *bufp0;
    *bufp0 =*bufp1;
    *bufp1 =temp;
}

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

char hex_symbol_to_int(char h)
{
   char r = -1;
   if (h >= '0' && h <= '9') {
       r = h - '0';
   } else if (h >= 'a' && h <= 'f') {
       r = h - 'a' + 10;
   } else if (h >= 'A' && h <= 'F') {
       r = h - 'A' + 10;
   }
   return r;
}

int hex_string_to_int(char *s)
{
   if(strlen(s)<8) return 0;
   int result = 0;
   while (*s) {
      char v = hex_symbol_to_int(*s);
      result = result*16 + v;
      s++;
   }
   return result;
}

int main(int n, char *args[]) {
    char *s = args[1];
    int x = hex_string_to_int(s);
    printf("%s = %d\n",s,x);
    return 0;
}

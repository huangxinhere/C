#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int (*p)(char c[]);
    int strengh(char c[]);
    char c[20]={'\0'};
    p=strengh;
    gets(c);
    printf("the length is %d.\n",(*p)(c));
    return 0;
}
int strengh(char c[])
{
    return strlen(c);
}

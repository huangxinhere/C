#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c1[4]="qaq",c2[6]="haoye";
    char c[400]={'\0'};
    int x;
    for(x=0;x<strlen(c1);x++)
        c[x]=c1[x];
    for(x=strlen(c1);x<strlen(c1)+strlen(c2);x++)
        c[x]=c2[x-strlen(c1)];
    puts(c);
    return 0;
}

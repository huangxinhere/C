#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[]="l love";
    char b[]=" China ";
    char c[100]={'\0'};
    int i,j=strlen(a);

    for(i=0;i<j;i++)
        c[i]=a[i];
    for(i=0;i<strlen(b);i++,j++)
        c[j]=b[i];
    puts(c);

    return 0;
}

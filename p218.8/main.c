#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[50]={0};
    func(a);
    return 0;
}

void func(char a[])
{
    char c;
    int i,j;

    for(i=0;(c=getchar())!='\n';i++)
        a[i]=c,a[i+1]=' ';
    for(j=0;j<=i;j++)
        printf("%c ",a[j]);
}

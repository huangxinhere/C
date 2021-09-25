#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    int *p1,*p2;
    p1=&a,p2=&b;
    scanf("%d,%d",p1,p2);
    printf("%d\n",max(p1,p2));
    return 0;
}

int max(int *p1,int *p2)
{
    return *p1>*p2?*p1:*p2;
}

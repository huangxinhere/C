#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,temp;
    scanf("%d,%d,%d",&a,&b,&c);
    if(a>b) temp=a,a=b,b=temp;
    if(a>c) temp=a,a=c,c=temp;
    if(b>c) temp=b,b=c,c=temp;
    printf("由大到小排列为%d,%d,%d\n",a,b,c);
    return 0;
}

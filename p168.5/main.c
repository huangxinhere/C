#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6]={1,2,8,4,5,6},temp,i,n;
    int total=6;
    for(n=total-1,i=0;i<=n/2;i++)
        temp=a[i],a[i]=a[n-i],a[n-i]=temp;
    for(i=0;i<total;i++)
        printf("%d ",a[i]);
    return 0;
}

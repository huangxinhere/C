#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n=1,a[10]={0},count;
    while(1)
    {
        for(count=0,i=n+1;count<10;i++,count++)
        {
            a[count]=i;
            if(ifSu(i))
            {
                n=i;
                break;
            }
        }
        if(count==10)
            break;
    }
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}

int ifSu(int n)
{
    int i;
    for(i=2;i<=n/2;i++)
        if(n%i==0)
            return 0;
    return 1;
}

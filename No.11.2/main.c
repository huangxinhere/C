#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m=12;
    printf("please input a number:\n");
    scanf("%d",&m);
    func(m);

    return 0;
}
void func(int m)
{
    int i,a[50]={0};
    for(i=0;;i++)
    {
        if(m>=8)
            a[i]=m%8,m=m/8;
        else
        {
            a[i]=m;
            break;
        }
    }
    for(;i>=0;i--)
        printf("%d ",a[i]);
}

#include <stdio.h>
#include <stdlib.h>
int count=-1;

int main()
{
    int a[25]={0},i,j;
    for(i=100;i<=200;i++)
    {
        if(su(i)) continue;
        else
        {
            count=-1;
            foo(i,a);
            print(i,a);
        }
        printf("\n");
    }

    return 0;
}

int foo(int n,int *a)
{
    if(n==1)
        return 1;
    else if(n%2==0)
    {
        count++;
        a[count]=2;
        return foo(n/2,a);
    }
    else if(n%3==0)
    {
        count++;
        a[count]=3;
        return foo(n/3,a);
    }
    else if(n%5==0)
    {
        count++;
        a[count]=5;
        return foo(n/5,a);
    }
    else if(n%7==0)
    {
        count++;
        a[count]=7;
        return foo(n/7,a);
    }
    else if(n%11==0)
    {
        count++;
        a[count]=11;
        return foo(n/11,a);
    }
    else if(n%13==0)
    {
        count++;
        a[count]=13;
        return foo(n/13,a);
    }
    else
    {
        count++;
        a[count]=n;
        return 1;
    }
}

void su(int n)
{
    int i;
    for(i=2;i<=n/2;i++)
        if(n%i==0)
            return 0;
    return 1;
}

void print(int i,int *a)
{
    int j;
    printf("%d=",i);
    for(j=0;j<=count;j++)
    {
        if(j==count)  printf("%d",a[j]);
        else printf("%d*",a[j]);
    }
}

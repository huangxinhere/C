#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[15]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int min=0,max=14,mid,n,flag=0;

    scanf("%d",&n);
    while(min<max){
        mid=(max+min)/2;
        if(mid==13) mid+=1;
        if(a[mid]==n){
           printf("No.%d\n",mid),flag=1;
           break;
        }
        else if(a[mid]<n)
            max=mid;
        else if(a[mid]>n)
            min=mid;
    }
    if(flag==0)printf("该数组无此数\n");

    return 0;
}

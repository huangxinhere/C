#include <stdio.h>
#include <stdlib.h>

int main()
{
    //能不能边输入15个数字边排序？
    int a[15]={1,2,3,4,5,6,7,99,9,10,11,12,13,14,15};
    int min=0,max=14,mid,n,flag=0;
    scanf("%d",&n);
    while(min<max-1){
        mid=(max+min)/2;
        if(a[mid]==n){
           printf("No.%d\n",mid),flag=1;
           break;
        }
        else if(a[mid]<n)
            min=mid;
        else if(a[mid]>n)
            max=mid;
    }
    if(flag==0)printf("该数组无此数\n");
    return 0;
}

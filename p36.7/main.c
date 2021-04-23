#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,max,min,temp;
    scanf("%d,%d",&a,&b);
    if(a>b) max=a,min=b;
    else max=b,min=a;
    temp=min;
    while(temp>0){
        if(max%temp==0&&min%temp==0){
            printf("%d是最大公约数",temp);
            break;
        }
        temp--;
    }
    return 0;
}

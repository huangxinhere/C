#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,num;
    scanf("%d,%d,%d",&a,&b,&c);
    num=max(max(a,b),c);
    printf("The max is%d\n",num);
    return 0;
}
int max(int x,int y){
    if(x>y) return x;
    else return y;
}

#include <stdio.h>
#include <stdlib.h>
int x[4][4];
int main()
{
    int a=2,y,d[5]={10*1,0};
    /*switch(a)
    {
        case 1:printf("1");
        case 2:printf("2");
        case 3:printf("3");
        case 4:printf("4");
        case 5:printf("5");break;
    }*/

    //printf("%d %d",++a,a++);//4,2而不是3,3
    //函数里面的多个参数是表达式的时候，C语言是先计算后面的表达式的

    /*for(x=30,y=0;x>=10,y<10;x--,y++)
        x/=2,y+=2;
    printf("%d %d",x,y);*/
    /*int k[4][4];
    printf("%d",x[0][3]);*/
    int n,i=0,j=0;
    scanf("%d",&n);
    while(n)
    {
        if(n>0) i++;
        else j++;
    }
    printf("%d %d\n",i,j);
    return 0;
}

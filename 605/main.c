#include <stdio.h>
#include <stdlib.h>
int count=0;

int main()
{
    printf("Hello world!\n");
    return 0;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){

}
void one(int a[],int pos,int count)
{
    if(a[pos+2]==0)
    {
        zero(a,pos+2,count);
    }else
    {
        one(a,pos+4,count);
    }
}
void zero(int a[],int pos,int count)
{
    count++;
    if(a[pos+1]==0)
    {
        zero(a,pos+1,count);
    }else
    {
        one(a,pos+1,count);
    }

}

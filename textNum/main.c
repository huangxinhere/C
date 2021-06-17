#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b;
    b=orchestraLayout(4,1,2);
    printf("%d\n",b);

    return 0;
}
int orchestraLayout(int num, int xPos, int yPos){
    int a[100][100]={0},i,j,k,count=0;
    for(k=0;k<(num+1)/2;k++)
    {
        for(i=k,j=k;j<=num-k-1;j++)
            count=give(a,count,i,j);

        for(j-=1,i+=1;i<=num-1-k;i++)
            count=give(a,count,i,j);

        for(i-=1,j-=1;j>=k;j--)
            count=give(a,count,i,j);

        for(j+=1,i-=1;i>k;i--)
            count=give(a,count,i,j);
    }
    return a[xPos][yPos];
}

int give(int a[100][100],int count,int x,int y)
{
    count++;
    if(count==10)
        count=1;
    a[x][y]=count;
    return count;
}

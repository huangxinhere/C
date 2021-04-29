#include <stdio.h>
#include <stdlib.h>
int a[30][30];
int m;
int current,flag=0;

int main()
{
    int n,i,j,c,d;
    scanf("%d",&n);
    for(i=0,j=n-1,c=i,d=j; ;i++,j--,c=i,d=j){
       right(c,d,i);//最小值最大值与当前固定列、行一致————假设是列表的最长
       down(c+1,d,j);//总是比向右少一个数，即前进一位
       left(c,d-1,j);//同理，比向下少一个数，最右边的位置减1
       up(c+1,d-1,i); //最后的向上受到向右、向左限制，各减一个数
       if(flag==2) break;
    }

    printf("最终结果：\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void right(int min,int max,int now){
    if(min==max) flag++;
    if(now == 0) current=1;
    else current=a[now][min-1]+1;
    for(m=min;m<=max;m++,current++){
        a[now][m] = current;
    }
}
void down(int min,int max,int now){
    if(min==max) flag++;
    current=a[min-1][now]+1;
    for(m=min;m<=max;m++,current++){
        a[m][now] = current;
    }
}
void left(int min,int max,int now){
    if(min==max) flag++;
    current=a[now][max+1]+1;
    for(m=max;m>=min;m--,current++){
        a[now][m] = current;
    }
}
void up(int min,int max,int now){
    if(min==max) flag++;
    current=a[max+1][now]+1;
    for(m=max;m>=min;m--,current++){
        a[m][now] = current;
    }
}
    /*right(0,4,0);
    down(1,4,4);
    left(0,3,4);
    up(1,3,0);

    right(1,3,1);
    down(2,3,3);
    left(1,2,3);
    up(2,2,1);
    right(2,2,2);*/

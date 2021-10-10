#include <stdio.h>

#define MaxSize 100 
#define M 10
#define N 10

//迷宫：0是通道，1是墙
int mg[M+1][N+1] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
    }; 

struct DFS
{
    int i;  //当前方块的行号
    int j;  //当前方块的列号
    int di; //下一个可走方位的方位号
}Stack[MaxSize];  //方块的集合
int top = -1;

void mgpath(){
    int i,j,di,find,k;

    //初始方块进栈
    top ++;
    Stack[top].i = 1, Stack[top].j = 1;
    Stack[top].di = -1;
    mg[1][1] = -1;
    
    //栈不空时循环
    while (top>-1)
    {
        i = Stack[top].i, j = Stack[top].j, di = Stack[top].di;

        //找到出口，输出路径
        if (i == M-2 && j == N-2)
        {
            printf("迷宫路径如下：\n");
            for (k = 0; k < top; k++)
            {
                printf("\t(%d,%d)",Stack[k].i, Stack[k].j );
                if ( (k+1)%5==0 )
                    printf("\n");        
            }
            printf("\n");
            return;
        }

        //不是出口
        find = 0;
        while (di < 4 && find == 0)
        {
            di++;
            switch (di)
            {
            case 0: i = Stack[top].i-1, j = Stack[top].j; //up
                break;
            case 1: i = Stack[top].i, j  = Stack[top].j+1;//right
                break;
            case 2: i = Stack[top].i+1, j  = Stack[top].j;//down
                break;
            case 3: i = Stack[top].i, j  = Stack[top].j-1;//left
                break;
            }
            if(mg[i][j] == 0) find = 1;
        }

        //找到下一个可走的方块
        if (find == 1)
        {
            Stack[top].di = di;                 //更新原top的di值
            top++;                              //进入新的方块
            Stack[top].i = i, Stack[top].j = j;
            Stack[top].di = -1;
            mg[i][j] = -1;                      //避免重复走到该方块
        }
        //没有路径可走，则退栈
        else
        {
            mg[Stack[top].i][Stack[top].j] = 0;
            top--;
        }
        
    }
    printf("没有可走的路径！！\n");
    
}

int main(){
    mgpath();

    return 0 ;
}
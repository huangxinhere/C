#include <stdio.h>
#define MaxSize 100
#define M 10
#define N 10

struct BFS
{
    int i,j;    //方块的位置
    int pre;    //本路径中上一方块在Qu中的下标
}Qu[MaxSize];

//队首指针和队尾指针(非循环队列)
int front = -1, rear = -1;

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
//此方法错误!!!
void print(int front)
{
    for (int i = 0; front > -1; i++)
    {
        printf("\t%d",Qu[front]);
        front = Qu[front].pre;
    }
    
}

void mgpath()
{
    int i,j,find = 0,di;

    //入队
    rear++;     
    Qu[rear].i = 1, Qu[rear].j = 1, Qu[rear].pre = -1;
    mg[1][1] = -1;

    //队列不为空且没找到
    while (front <= rear && !find)
    {
        //出队
        front++;
        i = Qu[front].i, j = Qu[front].j;

        //到达目的地
        if(i == M-2 && j == N-2)
        {
            find = 1;
            print(front);   //调用print函数从出口向入口逆向输出路径
        }

    //把每个可走的方块插入队列中
    for (di = 0; di < 4; di++)
    {
        switch (di)
        {
        case 0: i = Qu[front].i-1, j = Qu[front].j; //up
            break;
        case 1: i = Qu[front].i, j = Qu[front].j+1; //right
            break;
        case 2: i = Qu[front].i+1, j = Qu[front].j; //down
            break;
        case 3: i = Qu[front].i, j = Qu[front].j-1; //left
            break;
        }

        //通道可走,插入
        if (mg[i][j] == 0)
        {
            rear++;
            Qu[rear].i = i, Qu[rear].j = j;
            Qu[rear].pre = front;
            mg[i][j] = -1;
        }
        
    }
    }
    if (!find)
    {
        printf("不存在路径!\n");
    }

}

int main()
{
    mgpath();
    return 0;
}
//为什么栈和队会导致方法不同?
//1. 队可出. 把所有可能的情况都放入了队. 为了试验各个方向,把队头送了出去换个新的队头
//2. 栈不可出. 是把一条路走到黑了发现不行才从末尾倒退回去
//3. 所以队看头,栈看末尾
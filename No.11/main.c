#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    printf("input the number of diskes:\n");
    scanf("%d",&m);
    hanoi(m,'A','B','C');
    return 0;
}

void hanoi(int n, char one, char two, char three)
{
    if(n==1)
        move(one,three);
    else
    {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}

void move(char one,char three)
{
    printf("%c-->%c\n",one,three);
}

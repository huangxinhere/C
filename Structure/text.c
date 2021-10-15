#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 50
int count = -1;

struct
{
    char stack[20];
    int top;
}opp;

//存放运算符的栈
struct 
{
    char data[20];
    int num[20];
    int top ;
}stack;  


int main(){
    int a = 1;
    int b = 3;
    printf("%d%d",a,b);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 50
int count = -1;

//存放运算符的栈
struct
{
    char data[MaxSize];
    int num[MaxSize];
    int top ;
}stack;

//栈元素给新数组
void func(char exp[]){
    count++;
    exp[count] = stack.data[stack.top];
    stack.top--;
}

void trans(char str[], char exp[]){
    //算数表达式str转换成后缀表达式exp

    if (str == NULL)
        return;

    stack.top = -1;
    int i ,j;
    char ch = '1';

    for (i = 0; ch != '\0' ; i++)
    {
        ch = str[i];
        switch (ch)
        {
        /*对)处理*/
        case '(':{
            stack.data[++stack.top] = ch;
        }break;
        case ')': {
            for (; stack.data[stack.top] != '('; )//左括号以后的
            {
                func(exp);                      //弹出栈的元素给新数组
            }
            stack.top--;                       //弹出左括号,右括号不入栈

        }break;

        /*加减*/
        case '+':                               //没有break，如果是“+”继续往下执行
        case '-':{
            if(stack.top >= 0){
                for(;stack.top >= 0 && stack.data[stack.top] != '(';){         //使前面都出栈
                    func(exp);
                    }
            }
            stack.top++;                       //无论如何,从str读取的字符都入栈
            stack.data[stack.top] = ch;
        }break;

        case '*':
        case '/':{
            while (stack.data[stack.top] == '*' || stack.data[stack.top] == '/')
            {
                func(exp);
            }
            stack.top++;
            stack.data[stack.top] = ch;

        }break;

        /*字母或者是数字，直接进入exp*/
        default:
            {
                count++;
                exp[count] = ch;
            }
        }
    }

    /*取出栈内剩余的运算符*/
    count--;
    while (stack.top >= 0)
    {
        func(exp);
    }

    /*打印新的数组*/
    for ( j = 0; j <= count; j++)
    {
        printf("%c",exp[i]);
    }
    printf("\n");

}

void transBack(char exp[]){
    stack.top = -1;
    int temp = 0,i;
    float res = 0;
    char ch;
    ch = '1';

    for ( i = 0; ch != '\0'; i++)
    {
        ch = exp[i];

        //化为整型,数字入栈
        if(ch <= '9' && ch >= '0'){
            temp = (ch-48) + temp*10;
            continue;
        }
        else if(ch == '#'){
            stack.top++;
            stack.num[stack.top] = temp;
            temp = 0;
        }
        //运算符运算
        else
        {
            switch (ch)
            {
            case '+':{
                res = stack.num[stack.top] + stack.num[--stack.top];
                stack.num[stack.top] = res;
            }break;
            case '-':{
                res = fabs(stack.num[stack.top] - stack.num[--stack.top]);
                stack.num[stack.top] = res;
            }break;
            case '*':{
                res = stack.num[stack.top] * stack.num[--stack.top];
                stack.num[stack.top] = res;
            }break;
            case '/':{
                if(stack.num[stack.top] > stack.num[--stack.top])
                    res = stack.num[stack.top] / (float)stack.num[--stack.top];
                else
                    res = stack.num[--stack.top] / (float)stack.num[stack.top];
                stack.num[stack.top] = res;
            }break;
            }
        }
    }
    //读取完毕,得出结果
    printf("The result is %f\n",res);
}


int main(){
    char str[] = "(5#-2#)+7#*5#/2#";
    char res[50] = {'\0'};
    trans(str,res);
    transBack(res);
    return 0;
}

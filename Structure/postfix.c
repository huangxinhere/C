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
}op;  

void trans(char str[], char exp[]){
    //算数表达式str转换成后缀表达式exp

    if (str == NULL)
        return;

    op.top = -1;
    
    int i ;
    char ch = '1';

    for (i = 0; ch != '\0' ; i++)
    {
        ch = str[i];
        switch (ch)
        {
        /*对)处理*/
        case ')': {
            for (; op.data[op.top] != '('; )//左括号以后的
            {
                func(str,exp);                  //弹出栈的元素
            }
            op.top--;                       //弹出左括号,右括号不入栈
            
        }break;

        /*加减*/
        case '+':                           //没有break，如果是“+”继续往下执行
        case '-':{
            if(op.top >= 0){
                for(;op.top >= 0;){         //使前面都出栈
                    func(str,exp);
                    }
            }
            op.top++;                       //无论如何,从str读取的字符都入栈
            op.data[op.top] = ch;
        }break;

        case '*':
        case '/':{
            while (op.data[op.top] == '*' || op.data[op.top] == '/')
            {
                func(str,exp);
            }
            op.top++;
            op.data[op.top] = ch;
            
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
    while (op.top >= 0)
    {
        count--;
        func(str,exp);
    }

    /*打印新的数组*/
    for (int i = 0; i <= count; i++)
    {
        printf("%c",exp[i]);
    }
    
}

void func(char str[], char exp[]){
    count++;
    exp[count] = op.data[op.top];
    op.top--;
}

void transBack(char exp[]){
    op.top = -1;
    int temp = 0;
    float res = 0;
    char ch;
    ch = '1';

    for (int i = 0; ch != '/0'; i++)
    {
        ch = exp[i];

        //化为整型,数字入栈
        if(ch <= '9' && ch >= '0'){
            temp = atoi(ch) + temp*10;
            op.top++;
            op.num[op.top] = temp;
            continue;
        }
        //运算符运算
        else 
        {
            switch (ch)
            {
            case '+':{
                res = op.num[op.top] + op.num[op.top--];  //top已经减1?
                op.num[op.top] = res;
            }break;
            case '-':{
                res = fabs(op.num[op.top] - op.num[op.top--]);
                op.num[op.top] = res;
            }break;
            case '*':{
                res = op.num[op.top] * op.num[op.top--];
                op.num[op.top] = res;
            }break;
            case '/':{
                res = op.num[op.top] / op.num[op.top--];
                op.num[op.top] = res;
            }break;
            }
        }   
    }
    //读取完毕,得出结果
    printf("The result is %f\n",res);
    
}

int main(){
    char str[] = "20#+2#*1#-2#";
    char res[50] = {'\0'};
    trans(str,res);
    transBack(res);
    return 0;
}
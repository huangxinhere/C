#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 50
int count = -1;

//����������ջ
struct
{
    char data[MaxSize];
    int num[MaxSize];
    int top ;
}stack;

//ջԪ�ظ�������
void func(char exp[]){
    count++;
    exp[count] = stack.data[stack.top];
    stack.top--;
}

void trans(char str[], char exp[]){
    //�������ʽstrת���ɺ�׺���ʽexp

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
        /*��)����*/
        case '(':{
            stack.data[++stack.top] = ch;
        }break;
        case ')': {
            for (; stack.data[stack.top] != '('; )//�������Ժ��
            {
                func(exp);                      //����ջ��Ԫ�ظ�������
            }
            stack.top--;                       //����������,�����Ų���ջ

        }break;

        /*�Ӽ�*/
        case '+':                               //û��break������ǡ�+����������ִ��
        case '-':{
            if(stack.top >= 0){
                for(;stack.top >= 0 && stack.data[stack.top] != '(';){         //ʹǰ�涼��ջ
                    func(exp);
                    }
            }
            stack.top++;                       //�������,��str��ȡ���ַ�����ջ
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

        /*��ĸ���������֣�ֱ�ӽ���exp*/
        default:
            {
                count++;
                exp[count] = ch;
            }
        }
    }

    /*ȡ��ջ��ʣ��������*/
    count--;
    while (stack.top >= 0)
    {
        func(exp);
    }

    /*��ӡ�µ�����*/
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

        //��Ϊ����,������ջ
        if(ch <= '9' && ch >= '0'){
            temp = (ch-48) + temp*10;
            continue;
        }
        else if(ch == '#'){
            stack.top++;
            stack.num[stack.top] = temp;
            temp = 0;
        }
        //���������
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
    //��ȡ���,�ó����
    printf("The result is %f\n",res);
}


int main(){
    char str[] = "(5#-2#)+7#*5#/2#";
    char res[50] = {'\0'};
    trans(str,res);
    transBack(res);
    return 0;
}

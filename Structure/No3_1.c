#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10  /*存储空间初始分配量*/
#define STACKINCREMENT 5  /*存储空间分配增量*/
typedef  int ElemType; /*定义元素的类型*/

/*-----关于栈的练习：用栈顶和栈底的指针-----*/

typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;     /*当前已分配的存储空间*/
}SqStack;

int InitStack(SqStack *S);   /*构造空栈*/
int push(SqStack *S,ElemType e); /*入栈*/
int Pop(SqStack *S,ElemType *e);  /*出栈*/
int CreateStack(SqStack *S);     /*创建栈*/
void PrintStack(SqStack *S);   /*出栈并输出栈中元素*/

int InitStack(SqStack *S){
    S->base=(ElemType *)malloc(STACK_INT_SIZE *sizeof(ElemType));
    if(!S->base) return ERROR;
    S->top=S->base;
    S->stacksize=STACK_INT_SIZE;
    return OK;
}/*InitStack*/

int Push(SqStack *S,ElemType e){
    int m = (S->top-S->base)/sizeof(ElemType);
    while((m+1)>=S->stacksize) //溢出栈,延长长度
    {
        S->stacksize += STACKINCREMENT;
        m = (S->top-S->base)/sizeof(ElemType);
        //return ERROR;
    }
    S->top += sizeof(ElemType);
    *(S->top) = e;
    return OK;

}/*Push*/

int Pop(SqStack *S,ElemType *e){
   int m = (S->top-S->base)/sizeof(ElemType);
    if(m<=0||m>=S->stacksize){
        return ERROR;
    }
    else{
        *e=*(S->top);
        S->top-=sizeof(ElemType);
        return OK;
    }
}/*Pop*/

int CreateStack(SqStack *S){
    int e;
    if(InitStack(S))
        printf("Init Success!\n");
    else{
        printf("Init Fail!\n");
        return ERROR;
    }
    printf("input data:(Terminated by inputing a character)\n");
    while(scanf("%d",&e))
        Push(S,e);
    return OK;
}/*CreateStack*/

void PrintStack(SqStack *S){
    ElemType e;
    while(Pop(S,&e))
        printf("%3d",e);
}/*Pop_and_Print*/

//进制转换
void func(int num, int n, SqStack *S){
    while(num){
        Push(S,num%n);
        num/=n;
    }

    printf("the second SqList is :\n");
    PrintStack(S);
}


int main(){
    SqStack ss,s;
    int num;
    printf("Please input a num:\n");
    scanf("%d",&num);

    printf("\n1-createStack\n");
    CreateStack(&ss);
    printf("\n2-Pop&Print\n");
    PrintStack(&ss);
    printf("\n");

    InitStack(&s);
    func(num,2,&s);

    return 0;
}


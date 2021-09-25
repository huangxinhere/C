#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
typedef  int ElemType; /*定义表元素的类型*/

typedef struct LNode{  /*线性表的单链表存储*/
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;       //?还有为什么不能用p.next  *LinkList可能是指针变量，存储地址，所以以后使用中，直接p=L（对main函数中L的访问很方便）---节点即地址？maybe结构体的原因

LinkList CreateList(int n); /*---创建链表---*/
void PrintList(LinkList L); /*输出带头结点单链表的所有元素*/
int GetElem(LinkList L,int i,ElemType *e); /*---获取i位置上的数据---*/

//尾插法
LinkList CreateList(int n){
    LNode *p,*q,*head;
    int i;
    head=(LinkList)malloc(sizeof(LNode));        head->next=NULL;
    p=head;
    for(i=0;i<n;i++){
       q=(LinkList)malloc(sizeof(LNode));       printf("input data %i:",i+1);
       scanf("%d",&q->data);            /*输入元素值*/
       q->next=NULL;                    /*结点指针域置空（这个很可能被我忽略掉——————如果不置空呢）*/
       p->next=q;                       /*新结点连在表末尾*/
       p=q;
    }
    return head;                //返回的是头指针，说明头指针代表一个链表
}/*CreateList*/

void PrintList(LinkList L){
    LNode *p;
    p=L->next;  /*p指向单链表的第1个元素*/
    while(p!=NULL){
        printf("%5d",p->data);
        p=p->next;
    }
}/*PrintList*/

int GetElem(LinkList L,int i,ElemType *e){
    LNode *p;int j=1;           //是不是只有头插法才会用到LinkList，单个结点用LNode???????__都要用指针————
    p=L->next;
    while(p&&j<i){
        p=p->next;j++;
    }
    if(!p||j>i)                 //找不到的情况有p为空（不存在）或者已经超出范围了（找不到）返回0
        return ERROR;
*e=p->data;                     //当前的p(指针？——为了改变e的值，值传递)
return OK;
}/*GetElem*/

int DeleteElem(LinkList L,int i,ElemType *e)
{
    LNode *p,*q; int j = 1;
    p=L,q=L->next;
    while(q->next&&j<i)     //要么达到i位置，要么提前q为空（越界）<——默认链表结尾以后为空（不会乱指一个地方，本create函数也确保了这点）
        p=q,q=q->next,j++;
    if(j==i)                //达到i
    {
        if(q->next==NULL)   //末尾
        {
            *e=q->data;
            free(q);
            p->next=NULL;
            return OK;
        }else{              //中间
            *e=q->data;
            p->next=q->next;
            free(q);
            return OK;
        }
    }else{                  //越界
        return ERROR;
    }

}

int InsertElem(LinkList L,int i,int n)          //链表不考虑长度限制
{
    LNode *p;//(LNode)malloc(sizeof(LNode)); //*s=NULL?—————LNode不能代表开辟的存储空间的地址，null也是。指针变量本身有存储空间，但也需要结构体的域的空间
    LinkList s;
    p=L;
    int j=1;
    while(p->next&&j<i)
    {
        p=p->next,j++;
    }
    if(j==i)
    {
        s= (LinkList *) malloc (sizeof(LNode));
        s->data=n;//无法访问？？？
        s->next=p->next;
        p->next=s;
        return OK;
    }else {
        return ERROR;
    }
}
int main(){
    int n,i,j;ElemType e;
    LinkList L=NULL;            /*定义指向单链表的指针*/
    printf("please input n:");  /*输入单链表的元素个数*/
    scanf("%d",&n);
    if(n>0){
    //创建并打印
        printf("\n1-Create LinkList:\n");
        L=CreateList(n);
        printf("\n2-Print LinkList:\n");
        PrintList(L);
    //获取数据
        printf("\n3-GetElem from LinkList:\n");
        printf("input i=");
        scanf("%d",&i);
        if(GetElem(L,i,&e))
            printf("No%i is %d",i,e);
        else
            printf("not exists");
    //删除数据
        printf("\n4-DeleteElem from LinkList(location):\n");
        scanf("%d",&i);
        if(DeleteElem(L,i,&e))
            PrintList(L);
        else
            printf("not exists");
    //插入数据
        printf("\n5-InsertElem from LinkList(location,data):\n");
        scanf("%d,%d",&i,&j);
        if(InsertElem(L,i,j))
            PrintList(L);
        else
            printf("location is error!");
    }else
        printf("ERROR");
    return 0;
}

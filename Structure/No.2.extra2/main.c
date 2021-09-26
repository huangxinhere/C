#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
int i,j;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList CreateList(int n)
{
    LNode *p,*q,*head;
    head=(LinkList) malloc(sizeof(LNode)),head->data=NULL;
    p=head;
    for(i=1;i<=n;i++)
    {
        q=(LinkList)malloc(sizeof(LNode));
        printf("The NO.%d data is: ",i);
        scanf("%d",&q->data);
        q->next=NULL;
        p->next=q;
        p=q;
    }
    return head;
}

int func(LinkList L)
{
    int c=1,c2;
    LNode *q,*p;
    p=L->next;
    for(;p!=NULL;p=p->next,c++)
    {
        for(q=p,c2=1;q->next!=NULL;)    //由于delete会删除当前位置i的值，i-1指向的值不变，i失效，所以不能表示当前值，用了i-1->next做检测
        {                               //若p都进一位，无论判断p或者p->next都会在最后一位删除时，报错
            if(q->next->data==p->data)  //所以解决根本是不同再进位（举例2,2,2时才发现）不一样了，才进位啊啊啊
            {
                Delete(L,c+c2);
            }else{
                q=q->next;
                c2++;
            }
        }
    }
    return OK;
}

int Delete(LinkList L,int k)    //传地址就说明可以更改链表了吧
{
    LNode *p,*q;
    p=L->next;
    //到达k-1位置
    for(i=1;i<k-1;i++)
    {
        p=p->next;
    }
    //删除操作
    q=p->next;
    p->next=q->next;
    free(q);
    return OK;
}

int PrintList(LinkList L)
{
    LNode *q;
    q=L->next;
    for(;q!=NULL;q=q->next)
        printf("%d ",q->data);
    return OK;
}

int main()
{
    LinkList L=NULL;
    int n;
    printf("Please input n:\n");
    scanf("%d",&n);
    L=CreateList(n);
    func(L);
    PrintList(L);
    return 0;
}

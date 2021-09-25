#include <stdio.h>
#include <stdlib.h>
#define OK 1
int i,j;
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList CreateList(int n){
    LNode *head,*p,*q;                       //为什么不用LinkList head？后者可能只是指针，前者是指向结构的指针？
    head = (LinkList) malloc(sizeof(LNode)); //返回头指针可以省去值传递的误解
    p=head;
    for(i=1;i<=n;i++){                       //为什么不用一个指针连续赋值呢？q=q->next,q->data=m;先指后赋值
        q=(LinkList) malloc(sizeof(LNode));
        scanf("%d",&q->data);                //便解决不了两问题：一，对新的节点要分配新空间；二、对新结点的后一个置空
        p->next=q;                           //所以出现了三个同时处理的节点，起码要用两个变量
        p=q;                                 //所以先处理好新变量，再进行联系
    }
    q->next=head->next;
    return head->next;                       //返回单循环链表
}

LinkList func(int k,LinkList L){
    LNode *cur,*q;
    cur=L;
    while(cur->next!=cur){
        //从当前点开始算
        q=cur;
        //到达第k-1位
        for(i=1;i<k-1;i++){
            q=q->next;
        }
        //执行删除
        cur=q->next;
        q->next=cur->next;
        free(cur);
        cur=q->next;
    }
    return cur;
}

int OutList(LinkList L){
    i=1,j=0;
    LNode *p;
    p=L;
    //循环输出两次，确保数据无误

    while(j!=2){
        printf("%d ",p->data);
        p=p->next;
        if(p->next==p) j++;
    }
    return OK;
}

int main()
{
    LinkList L=NULL;
    int n;
    printf("Please input n:\n");
    scanf("%d",&n);
    L=CreateList(n);
    L=func(3,L);
    OutList(L);
    return 0;
}

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
    LNode *head,*p,*q;                       //Ϊʲô����LinkList head�����߿���ֻ��ָ�룬ǰ����ָ��ṹ��ָ�룿
    head = (LinkList) malloc(sizeof(LNode)); //����ͷָ�����ʡȥֵ���ݵ����
    p=head;
    for(i=1;i<=n;i++){                       //Ϊʲô����һ��ָ��������ֵ�أ�q=q->next,q->data=m;��ָ��ֵ
        q=(LinkList) malloc(sizeof(LNode));
        scanf("%d",&q->data);                //�������������⣺һ�����µĽڵ�Ҫ�����¿ռ䣻�������½��ĺ�һ���ÿ�
        p->next=q;                           //���Գ���������ͬʱ����Ľڵ㣬����Ҫ����������
        p=q;                                 //�����ȴ�����±������ٽ�����ϵ
    }
    q->next=head->next;
    return head->next;                       //���ص�ѭ������
}

LinkList func(int k,LinkList L){
    LNode *cur,*q;
    cur=L;
    while(cur->next!=cur){
        //�ӵ�ǰ�㿪ʼ��
        q=cur;
        //�����k-1λ
        for(i=1;i<k-1;i++){
            q=q->next;
        }
        //ִ��ɾ��
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
    //ѭ��������Σ�ȷ����������

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

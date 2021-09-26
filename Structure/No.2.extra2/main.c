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
        for(q=p,c2=1;q->next!=NULL;)    //����delete��ɾ����ǰλ��i��ֵ��i-1ָ���ֵ���䣬iʧЧ�����Բ��ܱ�ʾ��ǰֵ������i-1->next�����
        {                               //��p����һλ�������ж�p����p->next���������һλɾ��ʱ������
            if(q->next->data==p->data)  //���Խ�������ǲ�ͬ�ٽ�λ������2,2,2ʱ�ŷ��֣���һ���ˣ��Ž�λ������
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

int Delete(LinkList L,int k)    //����ַ��˵�����Ը��������˰�
{
    LNode *p,*q;
    p=L->next;
    //����k-1λ��
    for(i=1;i<k-1;i++)
    {
        p=p->next;
    }
    //ɾ������
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

#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
typedef  int ElemType; /*�����Ԫ�ص�����*/

typedef struct LNode{  /*���Ա�ĵ�����洢*/
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;       //?����Ϊʲô������p.next  *LinkList������ָ��������洢��ַ�������Ժ�ʹ���У�ֱ��p=L����main������L�ķ��ʺܷ��㣩---�ڵ㼴��ַ��maybe�ṹ���ԭ��

LinkList CreateList(int n); /*---��������---*/
void PrintList(LinkList L); /*�����ͷ��㵥���������Ԫ��*/
int GetElem(LinkList L,int i,ElemType *e); /*---��ȡiλ���ϵ�����---*/

//β�巨
LinkList CreateList(int n){
    LNode *p,*q,*head;
    int i;
    head=(LinkList)malloc(sizeof(LNode));        head->next=NULL;
    p=head;
    for(i=0;i<n;i++){
       q=(LinkList)malloc(sizeof(LNode));       printf("input data %i:",i+1);
       scanf("%d",&q->data);            /*����Ԫ��ֵ*/
       q->next=NULL;                    /*���ָ�����ÿգ�����ܿ��ܱ��Һ��Ե�������������������ÿ��أ�*/
       p->next=q;                       /*�½�����ڱ�ĩβ*/
       p=q;
    }
    return head;                //���ص���ͷָ�룬˵��ͷָ�����һ������
}/*CreateList*/

void PrintList(LinkList L){
    LNode *p;
    p=L->next;  /*pָ������ĵ�1��Ԫ��*/
    while(p!=NULL){
        printf("%5d",p->data);
        p=p->next;
    }
}/*PrintList*/

int GetElem(LinkList L,int i,ElemType *e){
    LNode *p;int j=1;           //�ǲ���ֻ��ͷ�巨�Ż��õ�LinkList�����������LNode???????__��Ҫ��ָ�롪������
    p=L->next;
    while(p&&j<i){
        p=p->next;j++;
    }
    if(!p||j>i)                 //�Ҳ����������pΪ�գ������ڣ������Ѿ�������Χ�ˣ��Ҳ���������0
        return ERROR;
*e=p->data;                     //��ǰ��p(ָ�룿����Ϊ�˸ı�e��ֵ��ֵ����)
return OK;
}/*GetElem*/

int DeleteElem(LinkList L,int i,ElemType *e)
{
    LNode *p,*q; int j = 1;
    p=L,q=L->next;
    while(q->next&&j<i)     //Ҫô�ﵽiλ�ã�Ҫô��ǰqΪ�գ�Խ�磩<����Ĭ�������β�Ժ�Ϊ�գ�������ָһ���ط�����create����Ҳȷ������㣩
        p=q,q=q->next,j++;
    if(j==i)                //�ﵽi
    {
        if(q->next==NULL)   //ĩβ
        {
            *e=q->data;
            free(q);
            p->next=NULL;
            return OK;
        }else{              //�м�
            *e=q->data;
            p->next=q->next;
            free(q);
            return OK;
        }
    }else{                  //Խ��
        return ERROR;
    }

}

int InsertElem(LinkList L,int i,int n)          //�������ǳ�������
{
    LNode *p;//(LNode)malloc(sizeof(LNode)); //*s=NULL?����������LNode���ܴ����ٵĴ洢�ռ�ĵ�ַ��nullҲ�ǡ�ָ����������д洢�ռ䣬��Ҳ��Ҫ�ṹ�����Ŀռ�
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
        s->data=n;//�޷����ʣ�����
        s->next=p->next;
        p->next=s;
        return OK;
    }else {
        return ERROR;
    }
}
int main(){
    int n,i,j;ElemType e;
    LinkList L=NULL;            /*����ָ�������ָ��*/
    printf("please input n:");  /*���뵥�����Ԫ�ظ���*/
    scanf("%d",&n);
    if(n>0){
    //��������ӡ
        printf("\n1-Create LinkList:\n");
        L=CreateList(n);
        printf("\n2-Print LinkList:\n");
        PrintList(L);
    //��ȡ����
        printf("\n3-GetElem from LinkList:\n");
        printf("input i=");
        scanf("%d",&i);
        if(GetElem(L,i,&e))
            printf("No%i is %d",i,e);
        else
            printf("not exists");
    //ɾ������
        printf("\n4-DeleteElem from LinkList(location):\n");
        scanf("%d",&i);
        if(DeleteElem(L,i,&e))
            PrintList(L);
        else
            printf("not exists");
    //��������
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

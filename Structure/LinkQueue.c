#include <stdio.h>
#include <malloc.h>
typedef int ElemType;

/*仅带尾指针的单循环链表队列*/

//节点
typedef struct LNode
{
    struct LNode *next; //不要忘了标明struct
    ElemType data;
}LNode,*LinkList;

//带尾节点的队列
typedef struct 
{
    LNode *rear;
}*Qu,Queue;

LinkList  head = NULL;
Qu queue = NULL;

void InitList();
void CreateList(int n);
void InList(ElemType e);
void OutList();
void EmptyList();
void PrintList();

void InitList(){
    head = (LinkList) malloc(sizeof(LNode));
    queue = (Qu) malloc(sizeof(Queue));1
    (head)->next = head;
    (queue)->rear = head;
}

void CreateList(int n){
    LNode *p;
    int flag = 0;

//链表
    for (int i = 0; i < n; i++)
    {
        //新节点
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = NULL;
        //尾指针指向第一个加入的节点
        if(flag == i)
            queue->rear = p;
        //插入
        p->next = (head)->next;
        (head)->next = p;

    }

    printf("\nThe Link is created!!-----");
    PrintList();
}

void InList(ElemType e){
    LNode *s;
    s = (LinkList) malloc(sizeof(LNode));
    s->data = e;
    queue->rear->next = s;
    //
    queue->rear = s;
    queue->rear->next = head;

    printf("\nThe list is inserted!!----");
    PrintList();
}

void OutList(){
    LNode *p;
    p = head->next;
    if(p != head){
        head->next = p->next;
        free(p);
    }

    printf("\nThe list is delete!!----");
    PrintList();
}

void EmptyList(){
    LNode *p;
    p = head->next;
    while(p != head){
        head->next = p->next;
        free(p);
        p = head->next;
    }
    if(head->next == head)
        printf("\nAlready empty!!");
}

void PrintList(){
    LNode *p;
    p = (head)->next;
    while (p != head)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    
}

int main(){
  
    InitList();
    CreateList(5);
    InList(4);
    OutList();
    EmptyList();

    return 0;
}
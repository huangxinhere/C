#include<stdio.h>
#include<malloc.h>

#define ElemType int
#define OK 1
#define ERROR 0

typedef struct qnode{
	ElemType data;
	struct qnode *next;
}QNode;

int InitQueue(QNode *p){   // 初始化空队列 
	p = (QNode*)malloc(sizeof(QNode));
	if(p == NULL)
		return ERROR;
	p->next = p;
	return OK;
}

int EnQueue(QNode *p, ElemType e){   // 入队列 
	QNode *q;
	q = p->next;
	p->next = (QNode*)malloc(sizeof(QNode));
	if(p->next == NULL)
		return ERROR;
	p = p->next;
	p->data = e;
	p->next = q;
	return OK;
}

int DeQueue(QNode *p, ElemType *e){   // 出队列 
	QNode *q;
	if(p->next == p)
		return ERROR;
	q = p->next->next;
	*e = q->data;
	p->next->next = q->next;
	free(q);
	return OK;
}

void ClearQueue(QNode *p){   // 置空队列 
	ElemType e;
	while(p->next != p){
		DeQueue(p, &e);
		printf("%3d", e);
	}
}

int main(){
	ElemType e;
	QNode *p;
	
	if(InitQueue(p))
		printf("初始化完成\n");
	printf("输入队列数据：\n");
	while(scanf("%d", &e))
		EnQueue(p, e);
	printf("输出队列数据：\n");
	ClearQueue(p);
	return 0;
}

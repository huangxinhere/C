#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1

#define INIT_SIZE 5     /*��ʼ�����˳�����*/
#define INCREM 5        /*���ʱ��˳����ȵ�����*/

typedef  int ElemType;  /*�����Ԫ�ص�����*/

typedef struct Sqlist{
	ElemType *slist;      /*�洢�ռ�Ļ���ַ*/
	int length;           /*˳���ĵ�ǰ����*/
	int listsize;         /*��ǰ����Ĵ洢�ռ�*/
}Sqlist;

int InitList_sq(Sqlist *L); /* ---��ʼ��˳���---*/
int CreateList_sq(Sqlist *L,int n); /*  ---����һ���������ݵ�˳���--- */
int ListInsert_sq(Sqlist *L,int i,ElemType e);/*  ---��˳����в����µ�Ԫ��--- */
int PrintList_sq(Sqlist *L);  /*���˳����Ԫ��*/
int ListDelete_sq(Sqlist *L,int i); /*ɾ����i��Ԫ��*/
int ListLocate(Sqlist *L,ElemType e); /*����ֵΪe��Ԫ��*/

int InitList_sq(Sqlist *L){
    L->slist=(ElemType*)malloc(INIT_SIZE*sizeof(ElemType));
    if(!L->slist) return ERROR;
    L->length=0;
    L->listsize=INIT_SIZE;
    return OK;
}/*InitList*/

int CreateList_sq(Sqlist *L,int n){
    ElemType e;
    int i;
    for(i=0;i<n;i++){
        printf("input data %d",i+1);
        scanf("%d",&e);
        if(!ListInsert_sq(L,i+1,e))
            return ERROR;
    }
    return OK;
}/*CreateList*/

/*���˳����е�Ԫ��*/
int PrintList_sq(Sqlist *L){
    int i;
    for(i=1;i<=L->length;i++)
        printf("%5d",L->slist[i-1]);
    return OK;
}/*PrintList*/

int ListInsert_sq(Sqlist *L,int i,ElemType e){
    int k;
    //i=0��i�ӵ�һ����ʼ���򳬳�����---���Ϸ�
    if(i<1||i>L->length+1)
        return ERROR;

    //L�ĳ��ȱ�����޶Ȼ������������һ��
    if(L->length>=L->listsize){
        L->slist=(ElemType*)realloc(L->slist,     //�ѳ��������ٳ�ʼ�����µ�˳���
            (INIT_SIZE+INCREM)*sizeof(ElemType));
        if(!L->slist)                             //�����ʼ����ֵ������������
            return ERROR;

    L->listsize+=INCREM;                          //���³���
    }

    for(k=L->length-1;k>=i-1;k--){                //ԭ�����ֵ��len-1��Ȼ����һ��k+1����һλ
        L->slist[k+1]= L->slist[k];               //��i-1��ʼ������
    }
    L->slist[i-1]=e;
    L->length++;                                  //��ֵ�ճ�������
    return OK;
}/*ListInsert*/

/*��˳�����ɾ����i��Ԫ��*/
int ListDelete_sq(Sqlist *L,int i){
    int m;
    //
    if(i<1||i>L->length+1)
        return ERROR;

    for(m=i;m<L->length;m++)                    //��ǰһλ����
    {
        L->slist[m-1] = L->slist[m];
    }
    L->length--;
    return OK;
}
/*��˳����в���ָ��ֵԪ�أ����������*/
int ListLocate(Sqlist *L,ElemType e){
    int j;

    for(j=0;j<L->length;j++)
    {
        if(L->slist[j]==e)
        {
            return j;
        }
    }
    return ERROR;

}

int main(){
    Sqlist sl;
    int n,m,k;
    printf("please input n:");  /*����˳����Ԫ�ظ���*/
    scanf("%d",&n);
    if(n>0){
        printf("\n1-Create Sqlist:\n");
        InitList_sq(&sl);
        CreateList_sq(&sl,n);
        //���
        printf("\n2-Print Sqlist:\n");
        PrintList_sq(&sl);
        //����
        printf("\nplease input insert location and data:(location,data)\n");
	    scanf("%d,%d",&m,&k);
	    ListInsert_sq(&sl,m,k);
	    printf("\n3-Print Sqlist:\n");
	    PrintList_sq(&sl);
	    printf("\n");
	    //ɾ��
	    printf("\nDelete the location of data:(location)\n");
	    scanf("%d",&m);
	    ListDelete_sq(&sl,m);
	    printf("\n4-Print Sqlist:\n");
	    PrintList_sq(&sl);
	    printf("\n");
	    //����
	    printf("\nYou want to find(data) :\n");
	    scanf("%d",&k);
	    printf("It is on the location:%d\n",ListLocate(&sl,k));
        }
    else
        printf("ERROR");
    return 0;
}

#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1

#define INIT_SIZE 5     /*初始分配的顺序表长度*/
#define INCREM 5        /*溢出时，顺序表长度的增量*/

typedef  int ElemType;  /*定义表元素的类型*/

typedef struct Sqlist{
	ElemType *slist;      /*存储空间的基地址*/
	int length;           /*顺序表的当前长度*/
	int listsize;         /*当前分配的存储空间*/
}Sqlist;

int InitList_sq(Sqlist *L); /* ---初始化顺序表---*/
int CreateList_sq(Sqlist *L,int n); /*  ---创建一个有新内容的顺序表--- */
int ListInsert_sq(Sqlist *L,int i,ElemType e);/*  ---在顺序表中插入新的元素--- */
int PrintList_sq(Sqlist *L);  /*输出顺序表的元素*/
int ListDelete_sq(Sqlist *L,int i); /*删除第i个元素*/
int ListLocate(Sqlist *L,ElemType e); /*查找值为e的元素*/

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

/*输出顺序表中的元素*/
int PrintList_sq(Sqlist *L){
    int i;
    for(i=1;i<=L->length;i++)
        printf("%5d",L->slist[i-1]);
    return OK;
}/*PrintList*/

int ListInsert_sq(Sqlist *L,int i,ElemType e){
    int k;
    //i=0（i从第一个开始）或超出长度---不合法
    if(i<1||i>L->length+1)
        return ERROR;

    //L的长度比最大限度还长（插入最后一个
    if(L->length>=L->listsize){
        L->slist=(ElemType*)realloc(L->slist,     //把长度增加再初始化，新的顺序表
            (INIT_SIZE+INCREM)*sizeof(ElemType));
        if(!L->slist)                             //如果初始就有值（？），报错
            return ERROR;

    L->listsize+=INCREM;                          //更新长度
    }

    for(k=L->length-1;k>=i-1;k--){                //原本最大值是len-1，然后下一行k+1是增一位
        L->slist[k+1]= L->slist[k];               //从i-1开始往后移
    }
    L->slist[i-1]=e;
    L->length++;                                  //赋值空出来的数
    return OK;
}/*ListInsert*/

/*在顺序表中删除第i个元素*/
int ListDelete_sq(Sqlist *L,int i){
    int m;
    //
    if(i<1||i>L->length+1)
        return ERROR;

    for(m=i;m<L->length;m++)                    //往前一位覆盖
    {
        L->slist[m-1] = L->slist[m];
    }
    L->length--;
    return OK;
}
/*在顺序表中查找指定值元素，返回其序号*/
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
    printf("please input n:");  /*输入顺序表的元素个数*/
    scanf("%d",&n);
    if(n>0){
        printf("\n1-Create Sqlist:\n");
        InitList_sq(&sl);
        CreateList_sq(&sl,n);
        //输出
        printf("\n2-Print Sqlist:\n");
        PrintList_sq(&sl);
        //插入
        printf("\nplease input insert location and data:(location,data)\n");
	    scanf("%d,%d",&m,&k);
	    ListInsert_sq(&sl,m,k);
	    printf("\n3-Print Sqlist:\n");
	    PrintList_sq(&sl);
	    printf("\n");
	    //删除
	    printf("\nDelete the location of data:(location)\n");
	    scanf("%d",&m);
	    ListDelete_sq(&sl,m);
	    printf("\n4-Print Sqlist:\n");
	    PrintList_sq(&sl);
	    printf("\n");
	    //查找
	    printf("\nYou want to find(data) :\n");
	    scanf("%d",&k);
	    printf("It is on the location:%d\n",ListLocate(&sl,k));
        }
    else
        printf("ERROR");
    return 0;
}

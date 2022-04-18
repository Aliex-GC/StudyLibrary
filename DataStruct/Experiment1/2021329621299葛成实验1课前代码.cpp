#include <cstdio>
#include <cstdlib>
typedef char ElemType;
#define error -1
typedef struct _LinkNode 
{	ElemType data;
	struct _LinkNode * next;
}LinkNode, *PLinkNode;
typedef struct _LinkList
 {	LinkNode * head;
 	LinkNode * tail;
}*LinkList;
LinkList Makelist()                                         //初始化 
{
	LinkList L=(LinkList)malloc(sizeof(struct _LinkList));
	L->head=L->tail=NULL;
	return L;
} 
LinkNode* nsetup()                                             //初始化节点 
{
    PLinkNode p = (PLinkNode)malloc(sizeof(struct _LinkNode));
    p->data = -1;
    p->next = NULL;
    return p;
}
void insert(LinkList L,ElemType e,int n)                           //插入;
{
	if(L->head == NULL)
	{
		if(n != 1)
		{
			printf("ERROR!\n");
			return;
		}else{
			L->head=(PLinkNode)malloc(sizeof(struct _LinkNode));
			L->head->data = e;
			L->head->next= NULL;
			L->tail= L->head;
			return;
		}
	}
	PLinkNode p = L->head;
	PLinkNode temp;
	int i=1;
	if(n==1)
	{
		temp = (PLinkNode)malloc(sizeof(struct _LinkNode));
		temp->data=e;
		temp->next=p;
		L->head=temp;
	}
	else
	{
	while(p&&i<n-1)
	{
		p=p->next;
		++i;
	}
	if(!p||i>n-1)
		return;
	temp = (PLinkNode)malloc(sizeof(struct _LinkNode));
	temp->data=e;
	temp->next=p->next;
	p->next=temp;
	}

}
void Delete(LinkList L,ElemType *e,int i)             //指定位置i删除 ,并将值放在*e中 
{
	int j=1;
	PLinkNode p,q;
	p=L->head; 
	if(i==1)
	{
		q=L->head;
		L->head=L->head->next;
		free(q);
		return;
	}
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)
	{
		printf("delete error!\n");
		return;
	}
	q=p->next;
	p->next=q->next;
	q->data=*e;
	free(q);
}
ElemType Getdate(LinkList L,int i)     //取值 
{
	PLinkNode p;
	p=L->head; 
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)
	return 0;
	
	return p->data;
}
void Clearlist(LinkList L)                    //销毁链表 
{
	PLinkNode p,q;
	p=L->head;
	if(!p)
	{
        printf("error!\n");
        return;
    }
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->tail=NULL;
	return ;
}
void bianli(LinkList L)                         //遍历链表并输出值 
{
	PLinkNode p;
	p=L->head;
	if(p==NULL)
	{
		printf("空链表！\n"); 
	 } 
	 while(p)
	 {
	 	printf("%c ",p->data);
	 	p=p->next;
	 }
	 printf("\n");
 } 
void  reverse(LinkList L)                              //函数反转 
{ 
    PLinkNode p,q;
    LinkNode *cur = L->head;
    p=NULL;
    while (cur->next != NULL) { 
        q= cur->next;
        cur->next = p;
        p= cur;
        cur = q;
    }
    cur->next=p;
    L->head=cur;
}
bool huiwen(LinkList L)
{
	int count=1; 
    PLinkNode p=L->head;
    while(p->next)
    {
    	count ++;
    	p=p->next;
	}
	int i=1;
	while(i=count)
	{
		if(Getdate(L,i)!=Getdate(L,count-i+1))
		return false;
		else
		{
			i++;
		}
	}
	return true;
}
int main(void)
{
	ElemType e,Q, a,e2;
	LinkList L = Makelist();
	insert(L,'a',1);
	bianli(L);
	insert(L,'b',1);
	bianli(L);
	insert(L,'c',1);
	bianli(L);
	printf("%c\n",Getdate(L,3)); 
	Delete(L,&Q,2);
	bianli(L);
	reverse(L);
	bianli(L);
	if(huiwen(L))
	{
		printf("T\n");
	}
	else
	{
		printf("F\n");
	}
	bianli(L);
	Clearlist(L);
	return 0;
}

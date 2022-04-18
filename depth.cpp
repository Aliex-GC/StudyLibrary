
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree Create();/* 细节在此不表 */



int Depth(BiTree T)
{
	if(T==NULL)
	{
		return 1;
	}
	else
	{
		int d1=Depth(T->lchild);
        int d2=Depth(T->rchild);
        if(d1>d2) 
		return d1+1;
        else 
		return d2+1;
	}
}

int main()
{
    BiTree T = Create();

    printf("%d\n", Depth(T));
    return 0;
}
/* 你的代码将被嵌在这里 */


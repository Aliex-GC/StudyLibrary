#include <cstdio> 
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

#define ERROR 0;
#define OK 1;

typedef int ElemType;

typedef struct BinaryTree
{
  ElemType data;
  struct BinaryTree *l;
  struct BinaryTree *r;
}*BiTree,BiNode;

BiNode * createNode()
{
  BiTree temp = (BiNode *)malloc(sizeof(BiNode));
  return temp;
}

void CreateSubTree(BiTree& T, ElemType *all ,int i)//i为为顺序存储结构all的第i个结点元素
{
  if ((all[i]==0)||i>16)//这个根据节点个数及节点值用什么表示空修改，这里用0表示空节点
    {
      T=NULL;
      return;
    }
  T = createNode ();
  if(T == NULL){
    printf("ERROR");
     return;
  }
  T->data=all[i];
  CreateSubTree(T->l,all,2*i);
  CreateSubTree(T->r,all,2*i+1);
  return;
}

void CreateBiTree1(BiTree& T)
{
  ElemType all[16]={0,8,3,19,1,6,14,0,0,0,4,7,13,0,0,0};
  CreateSubTree(T,all,1);
}

void  printelem(ElemType d)
{
  printf("%d ",d);
}

void PreOrderTraverse(BiTree T,void (*Visit)(ElemType d))
{
  	if(T==NULL)
		return;
    Visit(T->data);
    PreOrderTraverse(T->l,Visit);
	PreOrderTraverse(T->r,Visit); 
}

int InOrderTraverse(BiTree T,void (*Visit)(ElemType d))
{
  	if(T==NULL)
		return ERROR;
    InOrderTraverse(T->l,Visit);
	Visit(T->data);
	InOrderTraverse(T->r,Visit); 
	return OK;
}

int PostOrderTraverse(BiTree T,void (*Visit)(ElemType d))     //求树的高度
{
  	if(T==NULL)
		return ERROR;
    PostOrderTraverse(T->l,Visit);
	PostOrderTraverse(T->r,Visit);
	Visit(T->data);
	return OK;
}
void  LevelOrder(BiTree T,void (*Visit)(ElemType d))
{
    if(T==NULL)
    return;
    vector<BiTree> q;
    BiNode*p=NULL;
    q.push_back(T);
    while(!q.empty())
    {
      Visit(q.front()->data);
      if(q.front()->l != NULL)
      {
		  	q.push_back(q.front()->l);
		  }
      if(q.front()->r != NULL)
      {
		  	q.push_back(q.front()->r);
		  }
      for(int i=0;i<q.size();i++)
        q[i]=q[i+1];
        q.pop_back();
    }
    return;
}
int Depth(BiTree T)
{
	if(T==NULL)
	{
		return 0;
	}
	else if(T->l == NULL && T->r == NULL){
        return 1;
    }
    else
	{
		int d1=Depth(T->l);
        int d2=Depth(T->r);
        if(d1>d2)
		return d1+1;
        else 
		return d2+1;
	}
}

typedef struct sxNode
{
  ElemType * data;
  ElemType n;
}sx;


void SxLevelOutput(sx s){
	printf("%d\n",s.n);
	for(int i = 1; i < s.n+1; i ++)
		printf("%d ",s.data[i]);
    printf("\n");
}

void InitSx(sx& r, BiTree T, int loc){
	if(T)
	{
		r.data[loc] = T->data;
		InitSx(r,T->l,loc*2);
		InitSx(r,T->r,loc*2+1);
	}
}
sx ToSxTree(BiTree root){
	sx r;
	r.n = (int)pow(2,Depth(root))-1;
	r.data = (ElemType*)malloc(sizeof(ElemType)*(r.n+1));
	for(int i = 0; i <= r.n; i ++)
		r.data[i] = 0;
 	InitSx(r,root,1);
 	return r;
}
void SxPreOutput(sx s,int i,void (*Visit)(ElemType e))
{
    if(i > s.n)
        return;
    Visit(s.data[i]);
    SxPreOutput(s,2*i,Visit);
    SxPreOutput(s,2*i+1,Visit);
}
void SxInOutput(sx s,int i,void (*Visit)(ElemType e))
{
    if(i > s.n)
        return;
    SxInOutput(s,2*i,Visit);
    Visit(s.data[i]);
    SxInOutput(s,2*i+1,Visit);
    
}
void SxPostOutput(sx s,int i,void (*Visit)(ElemType e))
{
    if(i > s.n)
        return;
    SxPostOutput(s,2*i,Visit);
    SxPostOutput(s,2*i+1,Visit);
    Visit(s.data[i]);
}
typedef struct ExpressionTree
{
    bool isOperator;
    union
    {
        int num;
        char Opr;
    };
    ExpressionTree* l;
    ExpressionTree* r;
}* ExNode;

void BuildExpressionTree(struct ExpressionTree * en,const char str[])
{
    if(str[0] == '\0')
        return;
    int j = 0;
    for(int i = 0; i < strlen(str); i ++){
        if(str[i] == '(')
            j ++;
        else if(str[i] == ')')
            j --;
        if(j == 0 && (str[i] == '+' || str[i] == '-')){
            en->isOperator = 1;
            en->Opr = str[i];
            en->l = new ExpressionTree;
            char* str1 = new char[sizeof(struct ExpressionTree)];
            strcpy(str1,str);
            str1[i] = '\0';
            BuildExpressionTree(en->l,str1);
            en->r = new ExpressionTree;
            BuildExpressionTree(en->l,str+i+1);
            return;
        }
    }
    if(j != 0){
        printf("ERROR!");
        exit(0);
    }
    
    for(int i = 0; i < strlen(str); i ++){
        if(str[i] == '(')
            j ++;
        else if(str[i] == ')')
            j --;
        if(j == 0 && (str[i] == '*' || str[i] == '/')){
            en->isOperator = 1;
            en->Opr = str[i];
            en->l = new ExpressionTree;
            char* str1 = new char[sizeof(struct ExpressionTree)];
            strcpy(str1,str);
            str1[i] = '\0';
            BuildExpressionTree(en->l,str1);
            en->r = new ExpressionTree;
            BuildExpressionTree(en->l,str+i+1);
            return;
        }
    }
    if(str[0] == '('){
        char* str1 = new char[sizeof(struct ExpressionTree)];
        strcpy(str1,str);
        str1[strlen(str)-1]='\0';
        str1 ++;
        BuildExpressionTree(en,str1);
        return;
    }
    else{
        en->isOperator = 0;
        en->num = atoi(str);
        en->l = en->r = NULL;
    }
}

void InorderExpressionTree(struct ExpressionTree * en)
{
    if(en->isOperator == true)
    {
        if((en->Opr=='+'||en->Opr=='-')&&(en->l->isOperator==0||en->r->isOperator==0))
    
        InorderExpressionTree(en->l);
        printf("%d",en->Opr);
        InorderExpressionTree(en->r);
        if((en->Opr=='+'||en->Opr=='-')&&(en->l->isOperator==0||en->r->isOperator==0))
        printf(")");
    }
    else
    printf("%d",en->num);
}

int CulculateExpressionTree(struct ExpressionTree *en)
{
    int result;
    if(en->isOperator == 1)
    {
        if(en->Opr=='+')
            result=CulculateExpressionTree(en->l)+CulculateExpressionTree(en->r);
        if(en->Opr=='-')
            result=CulculateExpressionTree(en->l)-CulculateExpressionTree(en->r);
        if(en->Opr=='*')
            result=CulculateExpressionTree(en->l)*CulculateExpressionTree(en->r);
        if(en->Opr=='/')
            result=CulculateExpressionTree(en->l)/CulculateExpressionTree(en->r);
    }
    else
        result=en->num;
        return result;
}
#if 0
int main()
{
  BiTree root;
  CreateBiTree1(root);
  PreOrderTraverse(root,printelem);
  printf("\n");
  InOrderTraverse(root,printelem);
  printf("\n");
  PostOrderTraverse(root,printelem);
  printf("\n");
  LevelOrder(root,printelem);
  printf("\n");
  printf("树的高度为%d\n", Depth(root));
  sx p=ToSxTree(root);
  SxLevelOutput(p);
  SxPreOutput(p,1,printelem);
  SxInOutput(p,1,printelem);
  SxPostOutput(p,1,printelem);
  return 0;
}
#elif 1

int main()
{
    string str;
    scanf("%s",&str);
    ExNode en = (ExNode)malloc(sizeof(struct ExpressionTree));
    BuildExpressionTree(en,str.data());
    InorderExpressionTree(en);
    int result = CulculateExpressionTree(en);
    printf("%d\n",result);
    return 0;
}
#endif


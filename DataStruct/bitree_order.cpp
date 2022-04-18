#include<iostream>
using namespace std;
typedef struct BiNode{
    char data;
    struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T);//根据输入的字符串，创建二叉树。 
void PreOrder(BiTree T);//先序遍历二叉树 
void InOrder(BiTree T);//中序遍历二叉树 
void PostOrder(BiTree T);//后序遍历二叉树 
void LevelOrder(BiTree T);//层次遍历二叉树  

int main(){
 BiTree T;
 CreateBiTree(T);
 cout<<"PreOrder:"; 
 PreOrder(T);
 cout<<endl<<"InOrder:";
 InOrder(T);
 cout<<endl<<"PostOrder:";
 PostOrder(T);
 cout<<endl<<"LevelOrder:";
 LevelOrder(T);
 return 0;
} 
/* 请在这里填写答案 */

void CreateBiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch=='#')
	{
		T=NULL;
		return;
	}
	else{
		T=new BiNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	
}
void PreOrder(BiTree T)
{
	if(T==NULL)
		return;
	cout << T->data;
	PreOrder(T->lchild);
	PreOrder(T->rchild);
	
}
void InOrder(BiTree T)
{
	if(T==NULL)
		return;
	InOrder(T->lchild);
	cout << T->data;
	InOrder(T->rchild);
 } 
void PostOrder(BiTree T)
{
	if(T==NULL)
		return;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	cout << T->data;
}
#include <vector>
void LevelOrder(BiTree T)
{
	if(T==NULL)
		return;
	vector<BiNode*> q;
	BiNode* p = NULL;
	q.push_back(T);
	while(!q.empty()){
		cout << q.front()->data;
		if(q.front()->lchild != NULL){
			q.push_back(q.front()->lchild);
		}
		if(q.front()->rchild != NULL){
			q.push_back(q.front()->rchild);
		}
		for(int i = 0; i < q.size(); i ++)
            q[i] = q[i+1];
        q.pop_back();
	}
	return;
}

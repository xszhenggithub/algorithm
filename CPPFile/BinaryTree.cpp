#include<iostream>
using namespace std;

struct BTNode
{
	char data;
	BTNode *lchild,*rchild;
};

void createTree(BTNode* &root)
{
	char ch;
	cin>>ch;
	if(ch=='0') root=NULL;
	else
	{
		root = new BTNode;
		root->data=ch;
		createTree(root->lchild);
		createTree(root->rchild);
	}
}

void postOrder(BTNode* root)
{
	if(root)
	{
		postOrder(root->lchild);
		postOrder(root->rchild);
		cout<<root->data<<" ";
	}
}

void preOrder(BTNode* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}


void inOrder(BTNode* root)
{
	if(root)
	{
		inOrder(root->lchild);
		cout<<root->data<<" ";
		inOrder(root->rchild);
	}
}

int main()
{
	//freopen("e:\\1.txt","r",stdin);

	BTNode* root;
	char ch;

	createTree(root);

	inOrder(root);
	cout<<endl;

	return 0;
}

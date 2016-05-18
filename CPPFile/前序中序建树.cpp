#include<iostream>
#include<string>
using namespace std;

struct BTNode
{
	char ch;
	BTNode *lchild,*rchild;
};

bool createTree(string prestr,string instr,BTNode* &p)
{
	if(prestr.length()==0)
	{
		p=NULL;
		return true;
	}
	char ch=prestr[0];
	int index=instr.find(ch);
	p=new BTNode;
	p->ch=ch;
	createTree(prestr.substr(1,index), //左子树前序遍历序列 
				instr.substr(0,index), //左子树中序遍历序列
				p->lchild); 
	
	createTree(prestr.substr(index+1,prestr.length()-index-1),//右子树前序遍历序列 
				instr.substr(index+1,prestr.length()-index-1),//右子树中序遍历序列 
				p->rchild);
	return true;
}

void postOrderTravese(BTNode* root)
{
	if(root==NULL) return; //空树 
	if(root->lchild) postOrderTravese(root->lchild); //后序遍历左子树 
	if(root->rchild) postOrderTravese(root->rchild); //后序遍历右子树 
	cout<<root->ch; //根节点 
}

int main()
{
	string prestr,instr;
	cin>>prestr>>instr;
	
	BTNode* root;
	createTree(prestr,instr,root);
	
	postOrderTravese(root);
	cout<<endl;
	
	return 0;
}

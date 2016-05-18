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
	createTree(prestr.substr(1,index), //������ǰ��������� 
				instr.substr(0,index), //�����������������
				p->lchild); 
	
	createTree(prestr.substr(index+1,prestr.length()-index-1),//������ǰ��������� 
				instr.substr(index+1,prestr.length()-index-1),//����������������� 
				p->rchild);
	return true;
}

void postOrderTravese(BTNode* root)
{
	if(root==NULL) return; //���� 
	if(root->lchild) postOrderTravese(root->lchild); //������������� 
	if(root->rchild) postOrderTravese(root->rchild); //������������� 
	cout<<root->ch; //���ڵ� 
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

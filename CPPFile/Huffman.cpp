#include<iostream>
#include<stack>
#include<queue> 
using namespace std;

#define MAXLEN 200
stack<char> stk;

struct HuffmanNode
{
	char ch;
	int lchild,rchild,parent,weight;
};


void PrintHuffmanCode(HuffmanNode h[],int child)
{
	while(h[child].parent>0) //递归的深度 
	{
		if(h[h[child].parent].lchild==child) stk.push('0');
		else if(h[h[child].parent].rchild==child) stk.push('1');
		child=h[child].parent;
	}
	while(!stk.empty())
	{
		putchar(stk.top());
		stk.pop();
	}
}
	

int main()
{
	HuffmanNode h[MAXLEN];
	priority_queue<int,vector<int>,greater<int> > pque;
	int n;
	
	while(!cin.eof())
	{
		//输入
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>h[i].ch>>h[i].weight;
			h[i].lchild=-1; //叶子节点 
			h[i].rchild=-1;
			h[i].parent=-1;
			pque.push((h[i].weight<<16)+(int(h[i].ch)<<8)+i);
		}
		
		//建Huffman树
		for(int i=1;i<n;i++) //n-1次合并
		{
			//找权值最小的两个
			int min1,min2;
			min1=min2=0;
			min1=pque.top()&0xff;pque.pop();
			min2=pque.top()&0xff;pque.pop();
			
			//生成新节点
			int parent=n+i;
			if(h[min1].ch>h[min2].ch) swap(min1,min2);
			h[parent].weight=h[min1].weight+h[min2].weight;
			h[parent].ch = h[min1].ch;
			h[parent].lchild=min1;
			h[parent].rchild=min2;
			h[parent].parent=-1;
			h[min1].parent=h[min2].parent=parent;
			pque.push((h[parent].weight<<16)+(int(h[parent].ch)<<8)+parent);
		}
		
		//编码并输出
		for(int i=1;i<=n;i++)
		{
			cout<<h[i].ch<<":";
			PrintHuffmanCode(h,i);
			cout<<endl;
		}
	} 
	
    return 0;
}


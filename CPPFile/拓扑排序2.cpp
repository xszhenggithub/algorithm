#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<queue> 
using namespace std;

#define MAXVN 10
#define MAXINT 0x7fffffff

queue<int> rque;

struct ArcNode
{
	int adjvex;
	ArcNode* next;
	
	ArcNode(int vn)
	{
		adjvex = vn;
		next = NULL;
	}
};

struct VexNode
{
	ArcNode *firstadj,*lastadj; 
	int degin;
};

class Graph
{
	int vn;
	VexNode g[MAXVN];
	
public:
	void insert(int s,int e); //���뻡
	void toposort(); //��������
	void toposort(int vi);
	Graph()//���캯��
	{
		vn=0;
		memset(g,0,sizeof(g));
	}
};

int main()
{
	ifstream fin("e:\\1.txt");
	
	Graph gr;
	
	char line[128];
	while(!fin.eof())
	{
		fin.getline(line,128);//����һ�� 
		
		int i=0;
		while(!isdigit(line[i])) i++;
		int s=atoi(&line[i]); //ǰ�� 
		
		while(line[i] != '(') i++;
		while(true)
		{
			while(i<strlen(line)&&!isdigit(line[i])) i++;
			if(i>=strlen(line)) break;
			int e =  atoi(&line[i]); //���
			gr.insert(s,e);
			while(isdigit(line[i])) i++;
		}
	}
	//������������ 
	gr.toposort();
	
	fin.close();
	return 0;
}

void Graph::insert(int s,int e)
{ 
	g[e].degin += 1;
	
	//��¼���ڵ��� 
	if(s>vn) vn=s;
	if(e>vn) vn=e;
	
	//���뻡
	ArcNode* p = new ArcNode(e);
	if(g[s].firstadj==NULL)//û���κγ���
	{
		g[s].firstadj = p;
		g[s].lastadj = p;
	}
	else//�Ѿ��г���
	{
		g[s].lastadj->next = p;
		g[s].lastadj = p;
	}
}

void Graph::toposort()
{
	queue<int> que;
	for(int i=0;i<=vn;i++)//Ѱ�����Ϊ0�Ľڵ�
	{
		if(g[i].degin==0) que.push(i);
	}
	
	while(!que.empty())//�Ը�����ͼ������������ 
	{
		int vi = que.front();
		toposort(vi);
		que.pop();
	}
	
	//������
	if(rque.size()!=vn+1) cout<<"have circle"<<endl;
	else
	{
		while(rque.empty()==false)
		{
			cout<<"Task"<<rque.front()<<" ";
			rque.pop();
		}
	}
}

void Graph::toposort(int vi)
{
	if(g[vi].degin != 0) return;
	
	rque.push(vi);//���Ϊ0
	ArcNode* p = g[vi].firstadj;
	while(p)
	{
		g[p->adjvex].degin-=1;
		toposort(p->adjvex);
		p=p->next;
	}
}

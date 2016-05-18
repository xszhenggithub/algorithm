#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

#define MAXLEN 10

struct ArcNode
{
	int adjvex;
	int cost;
	ArcNode* nextadj;
	
	ArcNode(int vi,int c)
	{
		adjvex = vi;
		cost = c;
		nextadj = NULL;
	}
};

struct VexNode
{
	ArcNode* firstadj;
	int lvn;//上一节点编号
	
	VexNode()
	{
		firstadj=NULL;
		lvn = 0;
	}
};

struct Graph
{
	int vn;
	VexNode v[MAXLEN];
	
	void insert(int s,int t,int c);//插入弧
	void dijstral(int s,int t);//求指定节点间的最短路径
};

int main()
{
	freopen("e:\\1.txt","r",stdin);
	
	Graph g;
	int m,n,s,t;
	cin>>m>>n>>s>>t;
	g.vn = m;
	
	//输入所有的弧
	for(int i=0;i<n;i++)
	{
		int as,ae,ac;
		cin>>as>>ae>>ac;
		g.insert(as,ae,ac);
	}
	
	//求最短路径
	g.dijstral(s,t);
	
    return 0;
}

void Graph::insert(int s,int t,int c)
{
	//增加s到t的弧
	ArcNode* p = new ArcNode(t,c);
	p->nextadj = v[s].firstadj;
	v[s].firstadj = p;
}

void Graph::dijstral(int s,int t)
{
	int dis[MAXLEN];
	bool in[MAXLEN];
	bool find = true;
	memset(dis,0x7f,sizeof(dis));
	memset(in,0x7f,sizeof(in));
	int last=s;
	dis[s]=0;
	
	while(last!=t)//未找到t
	{
		in[last] = true; 
		ArcNode* p = v[last].firstadj;
		
		while(p)//跟新从last出发可以到达的节点的长度 
		{
			if(dis[last]+p->cost < dis[p->adjvex])
			{
				dis[p->adjvex] = dis[last] + p->cost;
				v[p->adjvex].lvn = last; //保存路径前一节点 
			}
			p = p->nextadj;
		}
		
		//找最小长度
		int min=0;
		for(int i=1;i<=vn;i++)
		{
			if(in[i]==false && dis[i] < dis[min]) min = i;
		}
		
		if(min == 0)
		{
			find = false;
			break;
		}
		
		last = min;
	}
	
	if(find) //找到了路径 
	{
		cout<<dis[t]<<endl;
		stack<int> stk;

		last = t;
		stk.push(last);
		
		while(last!=s)
		{
			last = v[last].lvn;
			stk.push(last);
		}
		
		while(!stk.empty())
		{
			cout<<stk.top()<<" ";
			stk.pop();
		}
		cout<<endl;
	}
	else
	{
		cout<<"error"<<endl;
	}
}

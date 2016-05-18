#include<iostream>
#include<cstring>
using namespace std;

#define MAXN 11

struct ArcNode
{
	int vn1,vn2,cost;
};

class Graph
{
	ArcNode a[MAXN];
	int vn,an;
	
public:
	void CreateGraph();
	bool Plim(int &mc);
};

int main()
{
	freopen("e:\\1.txt","r",stdin);
	
	Graph g;
	
	g.CreateGraph();
	
	int mc;
	if(g.Plim(mc))
	{
		cout<<mc<<endl;
	}
	else cout<<"Error"<<endl;
	
    return 0;
}

void Graph::CreateGraph()
{
	cin>>vn>>an;
	
	for(int i=1;i<=an;i++)
	{
		cin>>a[i].vn1>>a[i].vn2>>a[i].cost;
	}
}

bool Graph::Plim(int &mc)
{
	mc=0;
	
	bool in[MAXN];
	bool find = true;
	memset(in,0,sizeof(in));
	in[1]=true;
	a[0].cost=0x7fffffff;
	
	for(int i=1;i<vn;i++)//Ñ¡Ôñvn-1Ìõ±ß
	{
		int mini=0;
		for(int j=1;j<=an;j++)
		{
			if(in[a[j].vn1]!=in[a[j].vn2] && a[j].cost < a[mini].cost) mini = j;
		}
		
		if(mini != 0)
		{
			mc += a[mini].cost;
			in[a[mini].vn1] = true;
			in[a[mini].vn2] = true;
		}
		else
		{
			find = false;
		}
	}
	
	return find;
}

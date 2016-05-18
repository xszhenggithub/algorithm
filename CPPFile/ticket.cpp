#include<iostream>
#include<memory.h>
using namespace std;

//===¹º³µÆ±========= 
//#define X 500

//int main()
//{
//	freopen("e:\\1.txt","r",stdin);
//	
//	int i,n,m,a,b,c,u,d[X];
//	memset(d,0,sizeof(d));
//	
//	cin>>n>>m;
//	while(n--)
//	{
//		cin>>a>>b>>c;
//		u=m-c;
//		for(i=a;i<=b;i++)
//			if(d[i]>u) break;
//		if(i<=b) cout<<0<<endl;
//		else
//		{
//			cout<<1<<endl;
//			for(i=a;i<=b;i++) d[i]+=c;
//		}
//	}
//	return 0;
//}

struct ArcNode
{
	int adjvex,length;
	ArcNode* nextadj;
};


int main()
{
	int n,m,s,t,a,b,c;
	ArcNode* nodes[1000];
	memset(nodes,0,sizeof(nodes));
	
	cin>>n>>m>>s>>t;
	while(m--) //½¨Í¼ 
	{
		cin>>a>>b>>c;
		
		ArcNode* p=new ArcNode;
		p->length=c;
		p->adjvex=a;
		p->nextadj=nodes[b];
		nodes[b]=p;
		
		p = new ArcNode;
		p->length=c;
		p->adjvex=b;
		p->nextadj=nodes[a];
		nodes[a]=p;
	}
	
	int d[1000],f[1000],k=1,tl=0;
	f[0]=s;
	
	memset(d,0x7f,sizeof(d));
	ArcNode* p=nodes[s];
	while(p)
	{
		d[p->adjvex]=p->length;]
		p=p->nextadj;
	}
	
	for(int i=1;i<n;i++)
	{
		
	}
	
	return 0;
}

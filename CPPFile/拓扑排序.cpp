#include<iostream>
#include<memory.h>
using namespace std;

int vn,en,s,d=0;
int idegree[10];
bool a[10][10],vis[10];

void TPSort()
{
	int i;
	
	for(i=1;i<=vn;i++) if(vis[i]==false) break;
	if(i==vn+1) s++;
	
	for(i=1;i<=vn;i++)
	{
		if(vis[i]==false&&idegree[i]==0)//未排序且入度为0 
		{
			vis[i]=true;
			for(int j=1;j<=vn;j++) //将该节点排序
			{
				if(a[i][j]) idegree[j]--;
			}
			
			TPSort();
			
			vis[i]=false;//恢复
			for(int j=1;j<=vn;j++)
			{
				if(a[i][j]) idegree[j]++;
			}
			
		}
	}
}

int main()
{
	freopen("e:\\1.txt","r",stdin);
	
	s=0;
	memset(idegree,0,sizeof(idegree));
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	
	cin>>vn>>en;
	for(int i=0;i<en;i++)
	{
		int s,e;
		char ch;
		cin>>s>>ch>>ch>>e;
		a[s][e]=1;
		idegree[e]+=1;
	}
	
	TPSort();
	
	cout<<s<<endl;
	
	return 0;
}

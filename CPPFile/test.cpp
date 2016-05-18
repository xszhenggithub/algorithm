#include<iostream>
#include<memory.h>
using namespace std;

typedef int Matric[10][10];

void getPath(Matric b,int p,int q)
{
	if(b[p][q]>0)
	{
		getPath(b,p,b[p][q]);
		getPath(b,b[p][q],q);
	}
	else
	{
		cout<<"->"<<q;
	}
}

int main()
{
	freopen("e:\\1.txt","r",stdin);
	
	Matric a,b;
	int vn;
	
	//ÊäÈë
	int t;
	cin>>vn;
	for(int r=0;r<vn;r++)
		for(int c=0;c<vn;c++)
		{
			cin>>t;
			if(t==0) a[r][c]=0xffff;
			else a[r][c]=t;
		}
	
	memset(b,0xff,sizeof(b));
	
	for(int k=0;k<vn;k++)
		for(int i=0;i<vn;i++)
			for(int j=0;j<vn;j++)
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j] = a[i][k]+a[k][j];
					b[i][j] = k;
				}

	int n=5,s,e;
	while(n--)
	{
		cin>>s>>e;
		cout<<s<<" to "<<e<<":";
		s--,e--;
		if(a[s][e]<100)
		{
			cout<<a[s][e]<<endl;
			cout<<s;
			getPath(b,s,e);
			cout<<endl;
		}
	}
		
		
	return 0;
}

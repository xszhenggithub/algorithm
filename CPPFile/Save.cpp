#include<iostream>
#include<cstring>
using namespace std;

int a[100][100];

int count(int m,int n)
{
	int s=0;//ˮ�ظ���
	for(int i=1;i<=m;i++)
	   for(int j=1;j<=n;j++)
	   	  if(a[i][j]==1)
	   	  {
	   	  	if(a[i][j-1]==0&&a[i-1][j]==0) s++;
	   	  	else if(a[i][j-1]==1&&a[i-1][j]==1&&a[i-1][j-1]==0) s--;
	   	  }
	
	return s;
}

int main()
{
	int times,m,n,s;
	cin>>times;
	while(times--)
	{
		cin>>m>>n;
		
		for(int i=0;i<=n;i++) a[0][i]=0;//��ʼ���߽�
		for(int i=1;i<=m;i++) //m ��
		{
			a[i][0] = 0;
			for(int j=1;j<=n;j++)//n �� 
			    cin>>a[i][j];
		}
		
		cout<<count(m,n)<<endl;
	}
	return 0;
}

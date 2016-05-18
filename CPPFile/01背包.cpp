#include<iostream>
using namespace std;

int main()
{
	int n,a[200][200];
	while(!cin.eof())
	{
		cin>>n;
		if(n<1||n>199) continue; 
		
		//输入每堆的石头数 
		for(int i=0;i<n;i++) cin>>a[i][i];
		
		//当前最后一次移动的代价
		for(int r=1;r<n;r++)//斜对角线数
			for(int i=0;i<n-r;i++) //每条对角线上的数目 
			{
				int j=i+r;
				a[i][j]=a[i][j-1]+a[j][j];
			}
		
		//初试每堆移动代价为0
		for(int i=0;i<n;i++) a[i][i]=0;
		
		//当前最小总代价 
		for(int r=2;r<n;r++)
			for(int i=0;i<n-r;i++)
			{
				int s=0x7fffffff,t,j=i+r;
				
				for(int k=1;k<=j-i;k++)//寻找前面的最小代价 
				{
					t=a[i][j-k]+a[j-k+1][j];
					if(t<s) s=t;
				}
				a[i][j] += s;
			}
		
		cout<<a[0][n-1]<<endl;
	}
	return 0;
}

#include<iostream>
#include<memory.h>
using namespace std;

#define MAXW 100001

int main()
{
	int n,sum,a[20];
	bool b[MAXW];
	
	while(!cin.eof())
	{
		cin>>n;
		
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		
		memset(b,0,sizeof(b));
		
		int halfsum=sum/2;
		for(int i=0;i<n;i++)
		{
			for(int j=halfsum-a[i];j>0;j--)
			{
				if(b[j]&&j+a[i]<=halfsum) b[j+a[i]]=true;
			}
			b[a[i]]=true;
		}
		
		while(b[halfsum]==false) halfsum--;
		
		cout<<sum-2*halfsum<<endl;
	}
	
	return 0;
}

#include<iostream>
#include<memory.h>
using namespace std;

int main()
{
	int t,n,s,r[100000],w[20];
	while(!cin.eof())
	{
		s=0;
		
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>w[i];
			s+=w[i];
		}
		
		memset(r,0,sizeof(r));
		for(int i=0;i<n;i++)
		{
			for(int j=s/2;j>=w[i];j--)
			{
				t=r[j-w[i]]+w[i];
				if(r[j]<t) r[j]=t;
			}
		}
		cout<<s-2*r[s/2]<<endl;
	}
	return 0;
}

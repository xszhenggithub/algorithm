#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n=0,sum;
	
	cin>>n;
	sum=n*(n+1)/2;
	
	int a[100];
	memset(a,0,sizeof(a));
	a[1]=1;
	
	int max=1;
	for(int i=2;i<n;i++)
	{
		for(int j=max;j>0;j--)
		{
			if(a[j]>0)
			{
				if(j+i<=sum/2) a[j+i]+=a[j];
			}
		}
		a[i]+=1;
		max+=i;
	}
	cout<<a[sum/2]<<endl;
	
    return 0;
}


#include<iostream>
#include<cmath>
using namespace std;

bool prime(int n)
{
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	int a[78500];
	int s=0;
	
	for(int i=2;i<1000000;i++)
	{
		if(prime(i)) a[s++]=i;
	}
	
	int b[78500],k=0;
	b[0]=0;
	for(int i=1;i<78500;i++)
	{
		if(a[i]-a[i-1]<=2) ++k;
		b[i]=k;
	}
	
	int n,times;
	cin>>times;
	while(times--)
	{
		cin>>n;
		
		if(n<2) cout<<0<<endl;
		else
		{
			k=0;
			while(a[k]<=n) k++;
			cout<<b[k-1]<<endl;
		}
	}
	
	return 0;
}















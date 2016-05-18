#include<iostream>
using namespace std;

bool perfect(int n)
{
	int sum=1,upbound=n;
	for(int i=2;i<upbound;i++)
	{
		if(n%i==0)
		{
			upbound = n/i;
			sum+=i+upbound;
			if(i==upbound) sum-=i;
		}
	}
	if(sum==n) return true;
	return false;
}

int main()
{
	int n;
	for(int i=1;i<10000;i++)
	{
		if(perfect(i)) cout<<i<<endl;
	}
    return 0;
}


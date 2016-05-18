#include<iostream>
using namespace std;

int fact[13]; //±£´æn!

int c(int n,int a)
{
	return fact[n]/fact[a]/fact[n-a];
}

int main()
{
	fact[0]=1;
	for(int i=1;i<13;i++) fact[i]=fact[i-1]*i;
	
	int x,y,z,k,t;
	cin>>x>>y>>z;
	
	int sum=0;
	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<=y;j++)
		{
			k=8-i-j;
			if(k<=z)
			{
				t=c(x,i)*c(y,j)*c(z,k);
				cout<<i<<" "<<j<<" "<<k<<" "<<t<<endl;
				sum+=t;
			}
		}
	}
	
	cout<<sum<<endl;
	
	return 0;
}










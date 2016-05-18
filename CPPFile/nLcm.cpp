#include<iostream>
#include<memory.h>
using namespace std;

int main()
{
	int a[101]={0,1,2,3};
	
	for(int i=4;i<=100;i++)
	{
		int k=i;
		for(int j=2;j<i;j++)
		{
			if(k%a[j]==0) k/=a[j];
		}
		a[i]=k;
	}
	
	for(int i=3;i<=20;i++) a[i]*=a[i-1]; //20以内不超过int类型范围
	
	int b[80][10];
	memset(b,0,sizeof(b));
	
	int n;
	while(!cin.eof())
	{
		cin>>n;
		if(n<=20) cout<<a[n]<<endl;
	}
	
    return 0;
}


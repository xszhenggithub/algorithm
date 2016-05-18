#include<iostream>
using namespace std;

#define MAXLEN 1000001

int main()
{
	int a[MAXLEN],b[MAXLEN];
	int s,n,times;
	cin>>times;
	while(times--)
	{
		a[0] = 0x7fffffff; //a[0]为最小的整数 
		b[0] = -1;
		s=0; //结果
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			
			int j=i-1;
			while(a[j]<a[i]) j--;//找前面最近的一个比自己大的数
			b[i]=b[j]+1;//算重复
			while(a[j]<=a[i]) j--;
			s+=b[j]+1;//不算重复
		}
		
		cout<<s<<endl;
	}
	return 0;
}

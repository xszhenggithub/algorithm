#include<iostream>
using namespace std;

int main()
{
	int a[100],s,n,m;
	cin>>n>>s>>m;
	
	for(int i=0;i<n;i++) a[i]=i+1; //����һ��ѭ���� 
	a[n]=1;
	
	int last=s-1,k=m;
	m=s-1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<k;j++) m=a[m]; //��m-1��
		last=m;
		m=a[m];
		cout<<m<<" ";
		a[last]=a[m];
	}
	cout<<endl;
}

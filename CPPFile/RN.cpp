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
		a[0] = 0x7fffffff; //a[0]Ϊ��С������ 
		b[0] = -1;
		s=0; //���
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			
			int j=i-1;
			while(a[j]<a[i]) j--;//��ǰ�������һ�����Լ������
			b[i]=b[j]+1;//���ظ�
			while(a[j]<=a[i]) j--;
			s+=b[j]+1;//�����ظ�
		}
		
		cout<<s<<endl;
	}
	return 0;
}

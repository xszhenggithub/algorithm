#include<iostream>
using namespace std;

int main()
{
	int n,a[200][200];
	while(!cin.eof())
	{
		cin>>n;
		if(n<1||n>199) continue; 
		
		//����ÿ�ѵ�ʯͷ�� 
		for(int i=0;i<n;i++) cin>>a[i][i];
		
		//��ǰ���һ���ƶ��Ĵ���
		for(int r=1;r<n;r++)//б�Խ�����
			for(int i=0;i<n-r;i++) //ÿ���Խ����ϵ���Ŀ 
			{
				int j=i+r;
				a[i][j]=a[i][j-1]+a[j][j];
			}
		
		//����ÿ���ƶ�����Ϊ0
		for(int i=0;i<n;i++) a[i][i]=0;
		
		//��ǰ��С�ܴ��� 
		for(int r=2;r<n;r++)
			for(int i=0;i<n-r;i++)
			{
				int s=0x7fffffff,t,j=i+r;
				
				for(int k=1;k<=j-i;k++)//Ѱ��ǰ�����С���� 
				{
					t=a[i][j-k]+a[j-k+1][j];
					if(t<s) s=t;
				}
				a[i][j] += s;
			}
		
		cout<<a[0][n-1]<<endl;
	}
	return 0;
}

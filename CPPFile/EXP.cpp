#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define M 100000000

//��b��d�η���b,d��Ϊ�������� 
int main()
{
	int a[4],b,d;
	
	while(!cin.eof())
	{
		a[1]=a[2]=a[3]=0;
		
		cin>>b>>d;
		
		if(d==0) cout<<1<<endl;
		else
		{
			a[0]=b;
			for(int i=1;i<d;i++) //d-1�γ˷� 
			{
				int j=0;
				int c=0;//��λ
				while(a[j]>0)
				{
					a[j]=a[j]*b+c;
					c= a[j]/M;
					a[j++]%=M;
				}
			}
		}
		int i=3;
		while(a[i]==0) i--;
		cout<<a[i--];
		while(i>=0) cout<<setw(8)<<setfill('0')<<a[i--];
	}
	
	return 0;
}

#include<iostream>
#include<memory.h>
#include<iomanip>
using namespace std;

#define BN 1000000
#define BW 6

int main()
{
	int vv=10;
	printf("%'0'9d\n",vv);
	
	int times;
	cin>>times;
	while(times--)
	{
		int n,c,s[10];
		cin>>n;
		
		memset(s,0,sizeof(s));
		s[0]=1;
		
		for(int i=1;i<n;i++)
		{
			int j=0;
			c=1;
			while(s[j]>0||c>0)
			{
				s[j]=(s[j]<<2)+c;
				c=s[j]/BN;  //½øÎ» 
				if(c>0) s[j] %=BN;
				j++;
			}
		}
		
		//Êä³ö 
		int l=9;
		while(s[l]==0) l--;
		cout<<(s[l--]);
		while(l>=0)	cout<<setw(6)<<setfill('0')<<s[l--];
		cout<<endl;
	}
	return 0;
}

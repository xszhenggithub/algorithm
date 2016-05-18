#include<iostream>
#include<string>
using namespace std;

void reverse(string& a,int m)
{
	int last_index=a.length()-1;
	for(int i=0;i<a.length()/2;i++)
	{
		swap(a[i],a[last_index-i]);
	}
	for(int i=0;i<a.length();i++) a[i]+=m;
}
int main()
{
	string a,b;
	int t=0,times;
	cin>>times;
	while(t++ <times)
	{
		cin>>a>>b;
		cout<<"Case "<<t<<":"<<endl;
		cout<<a<<" + "<<b<<" = ";
		
		if(a.length()>b.length()) swap(a,b);
		
		reverse(a,-48);
		reverse(b,-48);
		
		int i,c=0;
		for(i=0;i<a.length()&&i<b.length();i++)
		{
			b[i] += a[i]+c;
			c=(b[i])/10; //进位
			b[i] %= 10;
		}
		
		while(c!=0 || i<b.length())
		{
			b[i]+=c;
			c=(b[i])/10; //进位
			b[i] %= 10;
			i++;
		}
		b[i]=0;
		
		for(--i;i>=0;i--) cout<<(char)(b[i]+48);
		cout<<endl;
	}
	
	return 0;
}

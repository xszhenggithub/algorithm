#include<iostream>
#include<cstring>
using namespace std;

void reverse(char a[],int s,int e)
{
	int l=e-s+1;
	for(int i=0;i<l/2;i++)
	{
		swap(a[s+i],a[e-i]);
	}
}

void reverse(char s[],int length)
{
	reverse(s,0,length-1);
	
	int low;
	for(int i=0;i<length-1;i++)
	{
		low=i;
		while(s[i]!='_') i++;
		reverse(s,low,i-1);
	}
}

int main()
{
	//how_are_you
	char s[128];
	cin>>s;
	reverse(s,strlen(s));
	cout<<s;
    return 0;
}


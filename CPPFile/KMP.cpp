#include<iostream>
using namespace std;

#define MAXLEN 10

void set_next(string str,int next[])
{
	next[0]=-1;
	int i=0,j=-1;
	while(i<str.length())
	{
		if(j==-1 || str[i]==str[j]) ++i,++j,next[i]=j; //j==-1表示无匹配 
		else j=next[j];
	}
}

int main()
{
	string str,str1;
	int next[MAXLEN];
	
	cin>>str>>str1;
	set_next(str,next);
	
	for(int i=0;i<str.length();i++) cout<<next[i]<<" ";
	cout<<endl;
	
	int i=0,j=0;
	while(i<str1.length()) //搜索所有匹配
	{
		if(j==str.length()) cout<<"Find"<<endl,j=0;
		
		if(str1[i]==str[j] || j==-1) i++,j++;
		else j=next[j];
	}
	
	return 0;
}

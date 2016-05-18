#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;

int cal(int b,char op,int a)
{
	switch(op)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}

int compute()
{
	char ch;
	cin>>ch;
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
	{
		return cal(compute(),ch,compute());
	}
	else
	{
		return ch-'0';
	}
}

int main()
{
	freopen("e:\\1.txt","r",stdin);
	
	cout<<compute();
	
    return 0;
}


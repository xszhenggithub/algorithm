#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

#define MAXL 10001

struct BigInteger //大整数 
{
	char a[MAXL];//最高位表示符号位 
	
	//构造函数 
	BigInteger()
	{
		memset(a,0,sizeof(a));
	}
	BigInteger(string str)
	{
		setValue(str);
	}
	
	void setValue(string str)
	{//赋值
		memset(a,0,sizeof(a));
		int i=0,j=0;
		if(str[0]=='-'||str[0]=='+') i=1; //过滤正负号 
		for(;i<str.length();i++,j++) 
		{
			a[j]=str[i]-'0';
		}
		for(i=0;i<j/2;i++) swap(a[i],a[j-i-1]);//逆转 
		
		if(str[0]=='-') this->complement(); //负数转换成补码表示 
	}
	
	void getValue()
	{//输出值
		bool neg=false;
		int i=MAXL-1;
		if(a[i]==9)//负数
		{
			neg=true;
			cout<<'-';
			this->complement(); //求补码 
		}
		
		while(i>=0&&a[i]==0) i--; 
		if(i<0) cout<<0;
		else for(;i>=0;i--) cout<<(int)a[i];
		cout<<endl;
		
		if(neg) this->complement();//恢复负数的补码表示 
	}
	
	BigInteger operator +(BigInteger b) //加法 
	{
		BigInteger d;
		int c=0;//进位
		for(int i=0;i<MAXL;i++)//从低位到高位逐位相加 
		{
			d.a[i]=a[i]+b.a[i]+c;
			if(d.a[i]>9) d.a[i]-=10,c=1;//有进位
			else c=0;
		}
		return d;
	}
	
	BigInteger operator -(BigInteger b) //加法 
	{
		BigInteger d;
		b.complement();//求-b;
		d=(*this)+b;   //a+(-b)
		b.complement();//恢复成b
		return d;
	}
	
	//求补码
	void complement()
	{
		int c=0;//借位
		for(int i=0;i<MAXL;i++)
		{
			a[i]=-a[i]-c;
			if(a[i]<0) a[i]+=10,c=1;//有借位
			else c=0;
		}
	}
	
	BigInteger operator *(BigInteger b)
	{//乘法 
		char nega,negb;
		nega=a[MAXL-1];
		negb=b.a[MAXL-1];
		if(nega) this->complement();
		if(negb) b.complement();
		
		BigInteger d;
		for(int i=0;i<MAXL/2;i++)//无符号乘法
		{
			for(int j=0;j<MAXL/2;j++)
			{
				d.a[i+j]+=a[i]*b.a[j];
				if(d.a[i+j]>9)//可以进位
				{
					d.a[i+j+1]+=d.a[i+j]/10;
					d.a[i+j]%=10;
				}
			}
		}
		
		if(nega!=negb) d.complement();//异号，乘积为负数
		if(nega) this->complement();
		if(negb) b.complement();
		return d;
	}
};

int main()
{
	int times;
	cin>>times;
	while(times--)
	{
		string str1,str2;
		cin>>str1;
		BigInteger i1(str1);
		cin>>str2;
		BigInteger i2(str2);
		cout<<str1<<" + "<<str2<<" = ";
		(i1+i2).getValue();
	}
	return 0;
}

#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

#define MAXL 10001

struct BigInteger //������ 
{
	char a[MAXL];//���λ��ʾ����λ 
	
	//���캯�� 
	BigInteger()
	{
		memset(a,0,sizeof(a));
	}
	BigInteger(string str)
	{
		setValue(str);
	}
	
	void setValue(string str)
	{//��ֵ
		memset(a,0,sizeof(a));
		int i=0,j=0;
		if(str[0]=='-'||str[0]=='+') i=1; //���������� 
		for(;i<str.length();i++,j++) 
		{
			a[j]=str[i]-'0';
		}
		for(i=0;i<j/2;i++) swap(a[i],a[j-i-1]);//��ת 
		
		if(str[0]=='-') this->complement(); //����ת���ɲ����ʾ 
	}
	
	void getValue()
	{//���ֵ
		bool neg=false;
		int i=MAXL-1;
		if(a[i]==9)//����
		{
			neg=true;
			cout<<'-';
			this->complement(); //���� 
		}
		
		while(i>=0&&a[i]==0) i--; 
		if(i<0) cout<<0;
		else for(;i>=0;i--) cout<<(int)a[i];
		cout<<endl;
		
		if(neg) this->complement();//�ָ������Ĳ����ʾ 
	}
	
	BigInteger operator +(BigInteger b) //�ӷ� 
	{
		BigInteger d;
		int c=0;//��λ
		for(int i=0;i<MAXL;i++)//�ӵ�λ����λ��λ��� 
		{
			d.a[i]=a[i]+b.a[i]+c;
			if(d.a[i]>9) d.a[i]-=10,c=1;//�н�λ
			else c=0;
		}
		return d;
	}
	
	BigInteger operator -(BigInteger b) //�ӷ� 
	{
		BigInteger d;
		b.complement();//��-b;
		d=(*this)+b;   //a+(-b)
		b.complement();//�ָ���b
		return d;
	}
	
	//����
	void complement()
	{
		int c=0;//��λ
		for(int i=0;i<MAXL;i++)
		{
			a[i]=-a[i]-c;
			if(a[i]<0) a[i]+=10,c=1;//�н�λ
			else c=0;
		}
	}
	
	BigInteger operator *(BigInteger b)
	{//�˷� 
		char nega,negb;
		nega=a[MAXL-1];
		negb=b.a[MAXL-1];
		if(nega) this->complement();
		if(negb) b.complement();
		
		BigInteger d;
		for(int i=0;i<MAXL/2;i++)//�޷��ų˷�
		{
			for(int j=0;j<MAXL/2;j++)
			{
				d.a[i+j]+=a[i]*b.a[j];
				if(d.a[i+j]>9)//���Խ�λ
				{
					d.a[i+j+1]+=d.a[i+j]/10;
					d.a[i+j]%=10;
				}
			}
		}
		
		if(nega!=negb) d.complement();//��ţ��˻�Ϊ����
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

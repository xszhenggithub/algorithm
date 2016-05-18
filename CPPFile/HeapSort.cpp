#include<iostream>
#include<cstdlib>
using namespace std;

#define LEN 100 

void movedown(int a[],int s,int e)
{
	int t=a[e+1];
	a[e+1]=0;//�߽紦��
	
	int li,ri;
	while(s<=e/2)
	{
		li=s<<1; //s*2 �������� 
		ri=li+1; //�Һ������� 
		li=a[li]>a[ri]?li:ri; //��������
		if(a[s]<a[li]) //����߾���
		{
			swap(a[s],a[li]);
			s=li;
		}
		else break;
	}
	
	a[e+1]=t;
}

void psort(int a[],int length)
{
	//��ʼ�������
	for(int i=length/2;i>0;i--)//�����һ����Ҷ��㿪ʼ����Ϊ����� 
	{
		movedown(a,i,length);
	}
	
	//����
	for(int i=length-1;i>0;i--)
	{
		swap(a[1],a[i+1]); //ȡ�����Ԫ��
		movedown(a,1,i); //���Ѷ�Ԫ�����µ���
	}
}

int main()
{
	int a[102];
	
	FILE* f;
	f= fopen("e:\\1.txt","r");
	
	for(int i=1;i<=LEN;i++) //��1��ʼ 
	{
		a[i]=rand()&0xff;
	}
	
	psort(a,LEN);
	
	for(int i=1;i<=LEN;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
    return 0;
}


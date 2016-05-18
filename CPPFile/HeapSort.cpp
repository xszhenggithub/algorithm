#include<iostream>
#include<cstdlib>
using namespace std;

#define LEN 100 

void movedown(int a[],int s,int e)
{
	int t=a[e+1];
	a[e+1]=0;//边界处理
	
	int li,ri;
	while(s<=e/2)
	{
		li=s<<1; //s*2 左孩子索引 
		ri=li+1; //右孩子索引 
		li=a[li]>a[ri]?li:ri; //大孩子索引
		if(a[s]<a[li]) //最大者居上
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
	//初始化大根堆
	for(int i=length/2;i>0;i--)//从最后一个非叶结点开始调整为大根堆 
	{
		movedown(a,i,length);
	}
	
	//排序
	for(int i=length-1;i>0;i--)
	{
		swap(a[1],a[i+1]); //取出最大元素
		movedown(a,1,i); //将堆顶元素向下调整
	}
}

int main()
{
	int a[102];
	
	FILE* f;
	f= fopen("e:\\1.txt","r");
	
	for(int i=1;i<=LEN;i++) //从1开始 
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


#include<iostream>
#include<cstdlib>
#include<iterator>
using namespace std;

int partition(int a[],int low,int high)
{
	int key=a[low];
	while(low<high)
	{
		while(a[high]>=key&&low<high) high--;
		a[low]=a[high];
		while(a[low]<=key&&low<high) low++;
		a[high]=a[low];
	}
	a[low]=key;
	return low;
}

void qsort(int a[],int s,int e)
{
	if(s>=e) return;
	int mid = partition(a,s,e);
	qsort(a,s,mid-1);
	qsort(a,mid+1,e);
}

int main()
{
	int a[10];
	
	for(int i=0;i<10;i++)
	{
		a[i]=rand()&0xff;
	}
	copy(a,a+10,ostream_iterator<int>(cout," "));
	cout<<endl;
	
	qsort(a,0,9);
	
	copy(a,a+10,ostream_iterator<int>(cout," "));
	cout<<endl;
	
    return 0;
}


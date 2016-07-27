#include<iostream>
using namespace std;

int partition(int *a,int left,int right){
	int pval=a[left];
	while(left<right){
		while(left<right && a[right]>=pval) right--;
		a[left]=a[right];
		while(left<right && a[left]<=pval) left++;
		a[right]=a[left];
	}
	a[left]=pval;
	return left;
}

// a[left,right] 注意右闭，否则partition处越界
void quickSort(int *a,int left,int right){
	if(left>=right) return;
	int mid=partition(a,left,right);
	quickSort(a,left,mid-1);
	quickSort(a,mid+1,right);
}

void quickSort(int a[],int n){
	quickSort(a,0,n-1);
}

int main(){
	int v[20];
	for(auto &e:v) e=rand()&0xff;

	for(auto e:v) cout<<e<<' ';
	cout<<endl;
	
	quickSort(v,20);

	for(auto e:v) cout<<e<<' ';
	cout<<endl;

	return 0;
}

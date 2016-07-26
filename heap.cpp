#include<iostream>
#include<vector>
using namespace std;

void heapDown(int *a,int n,int k){
	while(true){
		int mchild=k;
		int lchild=k*2+1;
		int rchild=k*2+2;
		mchild=(lchild<n && a[mchild]<a[lchild])?lchild:mchild;
		mchild=(rchild<n && a[mchild]<a[rchild])?rchild:mchild;
		if(mchild==k) break;
		swap(a[k],a[mchild]);
		k=mchild;
	}
}

void heapify(int *a,int n){
	for(int i=(n-1)/2;i>=0;i--){
		heapDown(a,n,i);
	}
}

void heapSort(int *a,int n){
	heapify(a,n);
	
	for(int i=n-1;i>0;i--){
		swap(a[i],a[0]);
		heapDown(a,i,0);
	}
}

int main(){
	int v[10];
	for(auto &e:v) e=rand()&0xff;

	heapSort(v,10);

	for(auto e:v) cout<<e<<' ';
	cout<<endl;

	return 0;
}

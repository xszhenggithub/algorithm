#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int bsearch(vector<int> a,int target){
	int i=0;
	int j=int(a.size())-1;

	while(i<=j){
		int mid=i+(j-i)/2;
		if(a[mid]==target) return mid;
		else if(a[mid]<target) i=mid+1;
		else j=mid-1;
	}

	return -1;
}

int main(){
	vector<int> a(0,0);
	for(auto &e:a) e=rand()&0xff;
	sort(a.begin(),a.end());
	for(auto e:a) cout<<e<<' '; cout<<endl;

	int target;
	while(cin>>target)	cout<<bsearch(a,target)<<endl;
	return 0;
}

#include<iostream>
#include<map>
#include<vector>
#include<limits.h>
using namespace std;

//O(n*n) DP
int longestNotDecreaseSequence1(vector<int> nums){
	if(nums.empty()) return 0;

	int global=1;
	vector<int> len(nums.size(),1);

	for(int i=1;i<nums.size();i++){
		for(int j=0;j<i;j++){
			if(nums[i]>=nums[j]) len[i]=max(len[i],len[j]+1);
		}
		global=max(global,len[i]);
	}

	return global;
}

//O(nlgn) DP+BST
int longestNotDecreaseSequence2(vector<int> nums){
	if(nums.empty()) return 0;

	int global=0;
	map<int,int> map;
	map[INT_MIN]=0;
	map[INT_MAX]=0;

	for(auto e:nums){
		auto it=map.lower_bound(e);
		if(it->first==e){
			it->second++;
		}
		else{
			it--;
			map[e]=it->second+1;
		}
		global=max(global,map[e]);
	}

	return global;
}

int main(){
	vector<int> vct{
		1,2,3,4
	};
	cout<<longestNotDecreaseSequence1(vct)<<endl;
	cout<<longestNotDecreaseSequence2(vct)<<endl;
}

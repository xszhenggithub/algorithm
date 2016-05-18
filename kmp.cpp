#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNext(string &p){
	vector<int> next(p.size(),0);

	int k=0;
	for(int i=1;i<p.size();i++){
		while(k>0 && p[i]!=p[k]) k=next[k-1];
		if(p[i]==p[k]) k++;
		next[i]=k;
	}

	return next;
}

int search(const string &s,const string &p,const vector<int> &next){
	int count=0;
	int k=0;
	for(int i=0;i<s.size();i++){
		while(k>0 && s[i]!=p[k]) k=next[k-1];
		if(s[i]==p[k]) k++;
		if(k==p.size()) count++,k=next[k-1];
	}

	return count;
}

int main(){
	int count;
	cin>>count;

	while(count--){
		string s,p;
		cin>>p>>s;
		if(p.empty()||s.empty()) cout<<0<<endl;
		else{
			auto next=getNext(p);
			cout<<search(s,p,next)<<endl;
		}
	}
}

#include<iostream>
#include<map>
using namespace std;

int main(){

	int N,M;
	int need,value;
	int global=0;
	cin>>N>>M;

	map<int,int> mp;//<need,value>
	mp[0]=0;
	while(N--){
		cin>>need>>value;
		if(need>M) continue;
		for(auto rit=mp.rbegin();rit!=mp.rend();rit++){
			if(rit->first+need<=M && mp[rit->first+need]<rit->second+value){
				mp[rit->first+need]=rit->second+value;
				global=max(global,rit->second+value);
			}
		}
	}

	cout<<global<<endl;
	return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;

int main(){
int N,M;
int need,value;
cin>>N>>M;

int mi=0;
int v[100001]{0};
while(N--){
cin>>need>>value;
if(need>M) continue;
for(int i=mi;i>0;i--){
if(v[i] && i+need<=M && v[i]+value>v[i+need]) v[i+need]=v[i]+value;
}
if(need<=M && v[need]<value) v[need]=value;
if(mi+need<=M) mi+=need;
//cout<<mi<<' '<<v[mi]<<endl;
}

cout<<v[mi]<<endl;
}
 */

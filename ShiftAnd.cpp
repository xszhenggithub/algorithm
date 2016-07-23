#include<iostream>
using namespace std;

/* Shift-And Algorithm
 * @p the length of p must be small than 32
 * ret : return the index
 */
int shiftAnd(string s,string p){
	unsigned int bset[128]={0};
	for(int i=0;i<p.size();i++) bset[p[i]] |= (1<<i);

	unsigned int d=0;
	unsigned int flag=1<<(p.size()-1);
	for(int i=0;i<s.size();i++){
		d = ((d<<1)|1) & bset[s[i]];
		if(d&flag) return i-p.size()+1;
	}

	return -1;
}

int main(){
	cout<<shiftAnd("cbcbcbaef","cbcba")<<endl;
	cout<<shiftAnd("bcbcbaef","cbcba")<<endl;
	cout<<shiftAnd("cbcbaef","cbcba")<<endl;
	cout<<shiftAnd("xbcbaef","cbcba")<<endl;
	return 0;
}

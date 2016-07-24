#include<iostream>
#include<algorithm>
using namespace std;

#define N 100

struct Edge{
	int dist;//the distance between n1,n2
	int n1,n2;
}ve[N];

bool cmp(Edge &a,Edge &b){
	return a.dist<b.dist;
}

//union-find set
int father[N];

void setInit(int len){
	for(int i=0;i<len;i++) father[i]=i;
}

int root(int x){
	//find the root
	int r=x;
	while(father[r]!=r) r=father[r];

	//path compress
	while(x!=r){
		int y=x;
		x=father[x];
		father[y]=r;
	}

	return r;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ve[i].n1>>ve[i].n2>>ve[i].dist;
	}
	
	sort(ve,ve+n,cmp);

	setInit(m);
	cout<<"the result is:"<<endl;
	for(int i=0,j=1;j<m;i++){
		int r1=root(ve[i].n1);
		int r2=root(ve[i].n2);
		if(r1==r2) continue; // n1,n2 in the same set
		father[r2]=r1;        // if not in the same set,then union them
		j++;
		cout<<ve[i].n1<<' '<<ve[i].n2<<' '<<ve[i].dist<<endl;
	}

	return 0;
}

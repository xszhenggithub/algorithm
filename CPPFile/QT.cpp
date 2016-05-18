#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct rect
{
	int l,w;
};

bool comp(rect a,rect b)
{
	return a.w<b.w || a.w==b.w&&a.l<b.l;
}

int main()
{
	freopen("e:\\1.txt","r",stdin);
	
	int times;
	cin>>times;
	while(times--)
	{
		vector<rect> vect;
		int n,a,b;
		cin>>n;
		while(n--)
		{
			cin>>a>>b;
			if(a>b) swap(a,b);
			rect r;
			r.l=b;
			r.w=a;
			vect.push_back(r);
		}
		
		sort(vect.begin(),vect.end(),comp);
		
		int k=0,s=1;
		for(int i=1;i<vect.size();i++)
		{
			//cout<<vect[i].w<<" "<<vect[i].l<<endl;
			
			if(vect[i].l>vect[k].l&&vect[i].w>vect[k].w)
			{
				s++;
				k=i;
			}
		}
		vect.clear();
		
		cout<<s<<endl;
	}
	return 0;
}

#include<iostream>
#include<set>
using namespace std;

int main()
{
	int i=1,r,t,n;
	set<int> st;
	while(!cin.eof())
	{
		r=0;
		
		cin>>n;
		while(n--)
		{
			cin>>t;
			if(t>0)	st.insert(t);
		}
		
		cout<<"Case "<<i++<<": "<<st.size()<<endl;
		st.clear();
	}
}

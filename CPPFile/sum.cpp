#include<stdio.h>

int main()
{
	int ls,s,t,times,n;
	
	scanf("%d",&times);
	if(times<=0) return 0;
	while(times--)
	{
		ls=-100;
		s=0;
		
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&t);
			s+=t;
			if(s>ls) ls=s; //最大和
			if(s<0) s=0;
		}
		
		printf("%d\n",ls);
	}
	return 0;
}

/*
总结：
做题之前要思考好，考虑多种情况
在这题中，刚开始为考虑到全为负的情况
*/ 

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
			if(s>ls) ls=s; //����
			if(s<0) s=0;
		}
		
		printf("%d\n",ls);
	}
	return 0;
}

/*
�ܽ᣺
����֮ǰҪ˼���ã����Ƕ������
�������У��տ�ʼΪ���ǵ�ȫΪ�������
*/ 

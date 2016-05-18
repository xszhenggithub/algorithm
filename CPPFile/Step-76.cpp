#include<stdio.h>

int main()
{
	int times,n;
	
	scanf("%d",&times);
	if(times<=0) return 0;
	while(times--)
	{
		int t,a=0,b=1;
		scanf("%d",&n);
		if(n==1)
		{
			printf("%d\n",a);
			continue;
		}
		while(--n)
		{
			t=b;
			b+=a;
			a=t;
		}
		printf("%d\n",b);
	}
	return 0;
}

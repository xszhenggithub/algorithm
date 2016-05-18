#include<stdio.h>

int main()
{
	int a=0,b=1;
	
	int n;
	scanf("%d",&n);
	while(n--)
	{
		printf("%d ",b);
		int t=a;
		a = b;
		b +=t;
	}
	
    return 0;
}

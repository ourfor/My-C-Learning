#include<stdio.h>

int main()
{
	int i,j;
	j=9;
	for(i=1;i<=j;i++)
	{
		for(int t=1;t<=i;t++)
		{
			printf("%dx%d=%d ",t,i,t * i);
		}
		printf("\n");
	}
	return 0;
}
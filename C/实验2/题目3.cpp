#include<stdio.h>

int main()
{
	int i;
	int x,y,z,sum;
	printf("水仙花数有：\n");
	for(i=100;i<=999;i++)
	{
		x=(int)i / 100;
		y=(int)(i - 100 * x)/10;
		z=(int)(i - 100 * x -10 * y);
		sum=x * x * x + y * y * y + z * z * z;
		if(sum==i) printf("%d\n",i);
		
	}
	return 0;
}
//using pointer and pritice
#include<stdio.h>
int main()
{
	int a,* p_test;
	a=7;
	p_test=&a;
	printf("a is %d",a);
	printf("\n");
	printf("%d\n",p_test);
	a=9;
	* p_test=20;
	printf("%d",a);
	getchar();
	return 0;
}
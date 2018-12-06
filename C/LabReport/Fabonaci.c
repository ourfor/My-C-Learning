#include <stdio.h>
#include <stdlib.h>
long Fabonaci(int n);
int main()
{
    /****************Begin*************/
	printf("Input n:");
    int n=0;
    scanf("%d",&n);
    printf("\n");
    int printNum=Fabonaci(n);
    if(n<1) printf("Input error!\n");
    else printf("fabnaci[%d] = %d\n",n,printNum);
    /****************End***************/
    return 0;
}

//此函数求斐波那契数列的第n项的值。当返回是-1时，表明输入的n有误。
long Fabonaci(int n)
{
     /****************Begin*************/
    if(n<1) return -1;
	if(n==1||n==2) return 1;
    else return Fabonaci(n-1)+Fabonaci(n-2);
    /****************End***************/
}
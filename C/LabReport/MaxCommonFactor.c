#include <stdio.h>
#include <stdlib.h>
int MaxCommonFactor(int a, int b);

int main()
{
    /****************Begin*************/
	printf("Input two positive integers,a,b:\n");
    int a,b;
    scanf("%d,%d",&a,&b);
    if(a<1||b<1) printf("Input error!\n");
    else printf("MaxCommonFactor = %d\n",MaxCommonFactor(a,b));
    /****************End***************/
    return 0;
}

//函数功能： 计算两个正整数的最大公约数，-1表示没有最大公约数
//要求使用递归实现
int MaxCommonFactor(int a, int b)
{
    /****************Begin*************/
	if(a>b) return MaxCommonFactor(a-b,b);
    else if(a<b) return MaxCommonFactor(b-a,a);
    else return a;
    /****************End***************/
}
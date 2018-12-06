#include <stdio.h>
#include <stdlib.h>
void TransformToR(int n,int r);
void PrintNumber(int n);
int main()
{
    /****************Begin*************/
	printf("Input n,r(r=2,8,16):\n");
    int n,r;
    scanf("%d,%d",&n,&r);
    TransformToR(n,r);
    printf("\n");
    /****************End***************/
    return 0;
}

//此函数实现将整数n转换为对应的r进制数进行输出
void TransformToR(int n,int r)
{
    /****************Begin*************/
	if(n>=r){
        TransformToR(n/r,r);
        PrintNumber(n%r);
    }
    else PrintNumber(n);
    /****************End***************/
}

//此函数用于打印一个字符，主要用于十六进制的字符"A"~"F"形式的输出
void PrintNumber(int n)
{
     /****************Begin*************/
	if(n==10) printf("A");
    else if(n==11) printf("B");
    else if(n==12) printf("C");
    else if(n==13) printf("D");
    else if(n==14) printf("E");
    else if(n==15) printf("F");
    else printf("%d",n);
    /****************End***************/
}

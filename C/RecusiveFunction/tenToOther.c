/*
 *author: ourfor
 *date: 20181203
 *description: 利用栈的特性，将一个十进制数转化为小于16进制的数，更改进制上限
 */

#include <stdio.h>
#include <stdlib.h>

void TransformToR(int n,int r);
void PrintNumber(int n);
int main()
{
    printf("Input n,r(r=2,8,16):\n");
    int n,r;
    scanf("%d,%d",&n,&r);
    TransformToR(n,r);
    printf("\n");
    return 0;
}

//此函数实现将整数n转换为对应的r进制数进行输出
void TransformToR(int n,int r){
    if(n>=r){
        TransformToR(n/r,r);    //交换位置试试？利用栈的特性
        PrintNumber(n%r);
    }
    else PrintNumber(n);
}

//此函数用于打印一个字符，主要用于十六进制的字符"A"~"F"形式的输出
void PrintNumber(int n){
    if(n>=10) printf("%c",65+n-10);
  else printf("%d",n);
}

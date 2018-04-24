#include<stdio.h>

int main()
{
	printf("输入表达式：\n");
	double a,b;
	char op;
	scanf("%lf%s%lf",&a,&op,&b);
	switch(op)
	{
		case '+': printf("%.2lf",a + b);
		break;
		case '-': printf("%.2lf",a - b);
		break;
		case '*': printf("%.2lf",a * b);
		break;
		case '/': printf("%.2lf",a / b);
		break;
	}

	return 0;

}
	
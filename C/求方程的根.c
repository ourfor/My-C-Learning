#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,temp,root1,root2;
	printf("输入a,b,c的值：");
	scanf("%lf%lf%lf",&a,&b,&c);

	//判断是否为一元二次方程
	if(a==0)
	{
		printf("该方程不是一元二次方程。\n");
		return 0;
	}

	//为一元二次方程
	else
	{
		temp=b * b - 4 * a * c;    //判别式

		if(temp<0) printf("此方程没有实数根。\n");

		//有实数根的情况
		else {
			temp=sqrt(temp);


			//有两个相等的实数根
			if(temp==0) {
				root1=root2=- b / (2 * a);
				printf("此方程有两个相等的实数根，x1=x2=%.2lf",root1);
			}

			//有两个不相等的实数根
			else {
				root1=- b / (2 * a) + temp / (2 * a);
				root2=- b / (2 * a) - temp / (2 * a);
				printf("此方程有两个b不相等的实数根，x1=%.2lf,x2=%.2lf",root1,root2);  //输出两位小数
			}
			
		}
	}
	return 0;
}

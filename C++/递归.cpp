//递归和循环比较
#include<iostream>
#include<ctime>
clock_t start,stop;
double time_run;
using namespace std;
void PrintN(int num);
int main()
{
	cout << "n=?";
	int n;
	cin >> n;
	start=clock();
	PrintN(n);
	stop=clock();
	time_run=((double)(stop-start))/CLK_TCK;
	cout << time_run;
	return 0;

}
void PrintN(int num)
{
	int i;
	for(i=0;i<=num;i++)
		printf("%d ",i);
}
/*void PrintN(int num)
{
	if(num){
		PrintN(num-1);
		printf("%d ",num);
	}
	
	
}*/
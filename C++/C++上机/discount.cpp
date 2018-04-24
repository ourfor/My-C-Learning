//----------------------------C++上机,要求使用静态数据成员以及静态成员函数----------------------------

#include<iostream>
using namespace std;

class shop_discount{

	private:
		static int discount;
		int quantity;
		double price;
		
	public:

		double sum_part;
	    void calculate_money();
		static void input();
		

};

shop_discount man[3];

man[0].discount=9.8;

;
//-------------------------类成员函数定义-------------------------


void shop_discount::calculate_money()
{
	if(quantity>10) sum_part=quantity * price * discount;
	else sum_part=quantity * price;
}

void shop_discount::input()
{
		for(int i=0;i<=2;i++)
	{
		cout << "输入销售员" << 100+i << "的销售量以及销售单价：";
		cin >> man[i].quantity >> man[i].price;
		man[i].calculate_money();
	}
}




//-------------------------主函数-------------------------
int main()
{
	man[0].input();
	double sum=0;
	for(int i=0;i<=2;i++)
	{
		sum+=man[i].sum_part;
	}
	cout << sum;
	return 0;

}

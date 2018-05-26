//工资管理程序，人员：经理(manager)、技术人员(technicist)、销售人员(salesman)、销售经理(sales_manager)

#include<iostream>
using namespace std;

class Manager
{
public:
	virtual void total(){reward=8000;}
	virtual void Extra(double extra_i){extra=extra_i;}
	virtual void Display(){cout << "经理每月的工资为：" << reward << endl;}
	virtual void All(){total();Display();}

	double reward;
	double extra;
};

class Technicist
{
public:
	void Tech(double work_hour_i){work_hour=work_hour_i;}
	void reward_total(){reward=work_hour * each_pay;}
	void All(int i);
private:
	double reward;
	double work_hour;
	static double each_pay;
	
};

void Technicist::All(int i)
{
	cout << "第" << i + 1 << "技术员工工作了多长时间：\n";
	double work_hour_i;
	cin >> work_hour_i;
	Tech(work_hour_i);
	reward_total();
	cout << "那么他的月工资为" << reward;
}

double Technicist::each_pay=100;

class Salesman
{
public:
	void Sales(double sales_month_i){sales_month=sales_month_i;reward=sales_month * 5 /100;}
	void Input(int i);
	void Display(int i);
	void Sum(){sum=sum + sales_month;}
	static double sum;

private:
	double sales_month;
	double reward;
};

double Salesman::sum=0;

void Salesman::Input(int i)
{
	cout << "输入第" << i + 1 << "个员工的月销售额:";
	double sales_m;
	cin >> sales_m;
	Sales(sales_m);
}

void Salesman::Display(int i)
{
	cout << "第" << i + 1 << "名员工的月工资为：" << reward;
}

class Sales_manager:public Manager
{
public:
	Sales_manager(){reward=5000;}
	void Extra(double extra_i){extra=extra_i;}
	void Display(){cout << "销售经理每月的工资为：" << reward + extra * 5 /100 << endl;}
	void All(double extra_i){Extra(extra_i);Display();}

};

void func(int man)
{
	Salesman c[man];
	double extra_i=0;
	cout << "现在有" << man << "名员工\n";
	for(int i=0;i<man;i++)
	{
		c[i].Input(i);
		c[i].Display(i);
		c[i].Sum();
		cout << endl;
	}
}

void func_(int man)
{
	Technicist e[man];
	cout << "现在有" << man << "名技术员工\n";
	for(int i=0;i<man;i++)
	{
		e[i].All(i);
		cout << endl;
	}
}


int main()
{
	Manager a;
	Sales_manager b;
	a.All();
	
	cout << "有多少个销售人员呢？\n";
	double man;
	cin >> man;
	func(man);

	cout << "****************************\n";
	cout << "****************************\n";

	Sales_manager d;
	d.All(Salesman::sum);

	cout << "****************************\n";
	cout << "****************************\n";

	cout << "有多少个技术人员呢？\n";
	cin >> man;
	func_(man);

	

	return 0;
}

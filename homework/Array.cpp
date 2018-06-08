#include<iostream>
using namespace std;

//--------------------------------------矩阵的实现-----------------------------------------
class Array
{
public:
	void InputArrayElem();
	void InputNum();
	void Init(int m,int n){Array_m=m;Array_n=n;}
	void Display();
	void Total();
	friend Array operator + (Array a1,Array a2);
	friend Array operator - (Array a1,Array a2);
	friend Array operator * (Array a1,Array a2);

	int Array_m;      //定义一个m * n 的矩阵，用二维数组存储矩阵中的元素
	int Array_n;
private:	
	double a[40][40];
};


void Array::InputArrayElem()
{

	for(int j=0;j<Array_m;j++)
	{
		for(int i=0;i<Array_n;i++)
		{

			cin >> a[j][i];
		}
	}
}

void Array::InputNum()
{
	cout << "你要计算的矩阵是几乘几的呢？\n";
	cin >> Array_m;
	cin >> Array_n;
	cout << "输入矩阵中的元素，用空格隔开，每行输入完后回车输入下一行。" << endl;

}

void Array::Display()
{
	for(int j=0;j<Array_m;j++)
		
	{

		for(int i=0;i<Array_n;i++)
		{
			cout << a[j][i] << " ";
		}

		cout << endl;

	}
}

void Array::Total()
{
	InputNum();
	cout << "输入一个矩阵的元素：" << endl;
	InputArrayElem();
}

Array operator + (Array a1,Array a2)
{
	cout << "两个矩阵相加结果如下：" << endl;
	Array temp;
	temp.Init(a1.Array_m,a1.Array_n);

	for(int j=0;j<a1.Array_m;j++)
	{
		for(int i=0;i<a1.Array_n;i++)
		{
			temp.a[j][i]=a1.a[j][i] + a2.a[j][i];
		}
	}

	return temp;
} 

Array operator - (Array a1,Array a2)
{
	cout << "两个矩阵相减结果如下：" << endl;
	Array temp;
	temp.Init(a1.Array_m,a1.Array_n);

	for(int j=0;j<a1.Array_m;j++)
	{
		for(int i=0;i<a1.Array_n;i++)
		{
			temp.a[j][i]=a1.a[j][i] - a2.a[j][i];
		}
	}

	return temp;
}

Array operator * (Array a1,Array a2)
{
	cout << "两个矩阵相乘结果如下：" << endl;
	Array temp;
	temp.Init(a1.Array_m,a2.Array_n);

	for(int j=0;j<a1.Array_m;j++)
	{
		for(int i=0;i<a1.Array_n;i++)
		{
			temp.a[j][i]=0;
			for(int t=0;t<a1.Array_n;t++)
				temp.a[j][i]=temp.a[j][i] + a1.a[j][t] * a2.a[t][i];
		}
	}

	return temp;
}  
//--------------------------------------运算符重载----------------------------------



int main()
{


	Array A,B,C;
	A.Total();
	cout << endl;
	cout << "输入另一个矩阵的元素：" << endl;
	B.Init(A.Array_m,A.Array_n);
	B.InputArrayElem();
	cout << endl;

	C=A + B;
	cout << endl;
	C.Display();

	C=A - B;
	cout << endl;
	C.Display();

	cout << "下面计算两个矩阵相乘" << endl;
	A.Total();
	B.Total();
	C=A * B;
	cout << endl;
	C.Display();

	return 0;
}

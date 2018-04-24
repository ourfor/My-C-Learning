//栈的初始化、压入、弹出等操作

#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

//预定义状态代码

typedef int Status;
typedef int SElemType;

#define OK 1
#define ERROR 0
//#define OVERFLOW -1
#define INFEASIBLE -2


//栈的初始量
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

//定义栈的结构体(顺序栈)
typedef struct 
{
	SElemType *base;             //栈底
	SElemType *top;				 //栈顶
	int  stacksize;              //当前已分配空间，以元素为单位

}Stack;

Stack S;
int j; 
            



//.............声明出栈函数................
//=======================================
Status Push(Stack S);   
//=======================================



//--------------------------------------栈的初始化--------------------------------------
Status InitStack(Stack &S)
{
	//构造一个空栈
	S.base=(SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

//-------------------------------top和base交换位置-----------------------------
void UNStack(Stack &S)
{
	SElemType *p;
	p=S.base;
	S.base=S.top;
	S.top=S.base;
}

//--------------------------------------入栈--------------------------------------
Status Pop(Stack &S,int &j)
{
	/*cout << "输入元素：" << endl;
	char stop;
	for(;*Stop!='\n';)
	{
		cin >> *S.top;
		S.top=S.top + 1;
		Stop=cin.get()

	}
	*/
	
    S.top=S.top + 1;
    *S.top=j;
	return OK;

}

//--------------------------------------字符入栈--------------------------------------
Status CharPop(Stack &S)
{
	//cout << "输入字符，输入‘@’结束输入:" << endl;

	//cin默认不接受空格与回车，使用成员函数cin.get()，这样就不用输入空格来隔开
	for(;*S.top!='\n';)
	{	
		S.top=S.top + 1;
		*S.top=cin.get();
	}

	//通过栈顶前移来删除输入的字符‘@’
	S.top=S.top-1; 
	  
    Push(S);
	return OK;
}

//--------------------------------------出栈--------------------------------------
Status Push(Stack S)
{
	SElemType *p;
	for(p=S.top;p!=S.base;p--)
	{
		cout << *p;
	}
	cout << endl;
	return OK;
}
//--------------------------------------判断是否为回文--------------------------------------
Status Custom(Stack S)
{
	SElemType *p,*r;
	r=S.base + 1;
	//后进先出的元素与先进先出的元素比较，判断回文
	for(p=S.top;*p==*r&&p!=S.base;)
	{
		cout << *r << *p << endl;
		r++;
		p--;
		
	}
		
	if(*(p + 1)!=*(r - 1)) {cout << "不是回文" << endl;return ERROR;}
	else cout << "是回文" << endl;
	Push(S);
	return OK;

}
//--------------------------------------其他进制转化为十进制--------------------------------------
int SwitchNum_10(Stack &S)
{
	int data,n,i,num,num_input;
	cout << "输入待转化的数：";
	cin >> data;
	cout << "它为几进制：";
	cin >> num_input;

	num=10;
	InitStack(S);
        int record_num_total=0;
	for(i=data;i!=0;data=i)
	{
		i=data / num;
		j=data % num;
                record_num_total++;
		Pop(S,j);
		
	}
	SElemType *r=S.base + 1;
	n=0;
	for(data=0;r!=S.top;r++)
	{
                data=data + (*r) * pow(num_input,n);
                n++;
	}
        data=data + (*r) * pow(num_input,n);
        //cout << data;
	return data;

}
//--------------------------------------十进制转化为其他进制--------------------------------------
Status SwitchNum(Stack &S)
{
	int data,i,num;
	//cout << "输入待转化的数：";
	data=SwitchNum_10(S);
	cout << "你想把它转化为几进制：";
	cin >> num;
	InitStack(S);
	for(i=data;i!=0;data=i)
	{
		i=data / num;
		j=data % num;
		Pop(S,j);
		
	}
	cout << "转化为" << num << "进制后为：\n";

	Push(S);
	return OK;
}





//--------------------------------------主函数--------------------------------------
int main()
{
	InitStack(S);
	//CharPop(S);
	//Custom(S);
	SwitchNum(S);
	return OK;
}




















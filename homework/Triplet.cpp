//有关线性表的元素插入、删除、查阅、初始化、清空、销毁以及...
#include(iostream)
#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
using namespace std;
struct Student{
	char name;
	int id;
	char sex;
}Student1,Student2;//Student information
status main()
{
	cout << "请输入第一个学生的信息";
	cin >> Student1.name >> Student1.id >> Student1.sex;
	cout << "请输入第二个学生的信息";
	cin >> Student2.name >> Student2.id >> Student2.sex;
	cout << Student1.name << endl;
	cout << Student2.sex << endl;
	return OK;
}

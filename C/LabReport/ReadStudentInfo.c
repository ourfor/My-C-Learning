#include  <stdio.h>
#define STU 30
#define COURSE 3
/************Begin***********/
//此处加上输入学生信息的函数声明
void inputScore(int n,int score[STU][COURSE],long num[STU]);

/************End*************/

int main(void)
{
	int n, score[STU][COURSE];
	long num[STU];

	printf("Please enter the total number of the students(n<=30):");
	scanf("%d", &n);					//输入参加考试的学生人数
	printf("Enter No. and score as: MT  EN  PH\n");
        /************Begin***********/
	//此处加上函数调用
	inputScore(n,score,num);

	/************End*************/
    return 0;
}


// 函数功能：输入某班学生期末考试三门课程成绩
/************Begin***********/
void inputScore(int n,int score[STU][COURSE],long num[STU]){
	for(int i = 0;i < n;i++){
    	scanf("%6ld %d %d %d",&num[i],&score[i][0],&score[i][1],&score[i][2]);
    }
}

/************End*************/

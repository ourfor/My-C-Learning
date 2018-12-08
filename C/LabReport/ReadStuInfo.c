#include  <stdio.h>
#define ARR_SIZE 30
/************Begin***********/
//此处加上输入学生信息的函数声明
int inputScore(float score[],long num[]);
void failStudents(int n,float score[],long num[]);
/************End*************/


int main(void)
{
	int n;
	float score[ARR_SIZE];
	long num[ARR_SIZE];
	printf("Please enter num and score until score<0:\n");
	/************Begin***********/
	//此处加上函数调用
	n = inputScore(score,num);
	printf("Total students:%d\n", n);
    failStudents(n,score,num);
    return 0;
}


//函数功能：从键盘输入一个班学生某门课的成绩及其学号
//当输入成绩为负值时，输入结束，函数返回学生总数
/************Begin***********/
int inputScore(float score[],long num[]){
	float inputF;
    long inputL;
    for(int i = 0;;i++){
    	scanf("%8ld %f",&inputL,&inputF);
        if(inputF < 0){
        	return i;
        }else{
        	num[i] = inputL;
            score[i] = inputF;
        }
    }
}

/************End*************/



//函数功能：统计不及格人数，并输出不及格学生名单
/************Begin***********/
void failStudents(int n,float score[],long num[]){
	int count = 0;
    printf("Fail:\n");
    printf("number--score\n");
    for(int i = 0;i < n;i++){	
        if(score[i] < 60){
        	printf("%8ld------%.0f\n",score[i],num[i]);
        	count++;
        }
    }
	printf("Fail students = %d\n",count);
}	

/************End*************/
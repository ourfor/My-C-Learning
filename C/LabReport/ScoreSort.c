#include  <stdio.h>
#define STU 30
#define COURSE 3
/************Begin***********/
//此处加上函数声明
void inputScore(int n,int score[STU][COURSE],long num[STU]);
void GetSumAver(int n,int score[][COURSE],int sum[],float aver[]);
void printScore(int n,long num[],int score[][COURSE],int sum[],float aver[]);
void Sort(long num[],int score[][COURSE],int n,int sum[],float aver[]);
/************End*************/


int main(void)
{
	int n, score[STU][COURSE],sum[STU];
	long num[STU];
	float aver[STU];
	printf("Please enter the total number of the students(n<=30):");
	scanf("%d", &n);					//输入参加考试的学生人数
	printf("Enter No. and score as: MT  EN  PH\n");
        /************Begin***********/
	//此处加上函数调用
	inputScore(n,score,num);
    GetSumAver(n,score,sum,aver);
    printf("Before sort:\n");
    printScore(n,num,score,sum,aver);
    Sort(num,score,n,sum,aver);
    printf("After sort:\n");
    printScore(n,num,score,sum,aver);
	/************End*************/
    return 0;
}


// 函数功能：输入某班学生期末考试三门课程成绩
/************Begin***********/
void inputScore(int n,int score[][COURSE],long num[]){
	for(int i = 0;i < n;i++){
    	scanf("%8ld %d %d %d",&num[i],&score[i][0],&score[i][1],&score[i][2]);
    }
}

/************End*************/


// 函数功能：计算每个学生的总分和平均分
/************Begin***********/
void GetSumAver(int n,int score[][COURSE],int sum[],float aver[]){
	for(int i = 0;i < n;i++){
    	sum[i] = score[i][0] + score[i][1] + score[i][2];
    	//printf("\n%d\n",sum[i]);
    	aver[i] = sum[i] / 3.0f;
    }
}

/************End*************/


// 函数功能：按总分成绩由高到低排出成绩的名次
/************Begin***********/
void Sort(long num[],int score[][COURSE],int n,int sum[],float aver[]){
	int index1 = sum[0];
    int index4;
    float index2;
    long index3;
    for(int k = 0;k < n;k++){
   	 	for(int i = 0;i < n - 1;i++){
    		if(sum[i] < sum[i+1]){
        		index1 = sum[i+1];//交换总成绩
            	sum[i+1] = sum[i];
            	sum[i] = index1;
            	index3 = num[i];//交换学号
           		num[i] = num[i+1];
            	num[i+1] = index3;
            	for(int j = 0;j < 3;j++){//交换成绩
            		index4 = score[i][j];
                	score[i][j] = score[i+1][j];
                	score[i+1][j] = index4;
            	}
            	index2 = aver[i];//交换平均成绩
            	aver[i] = aver[i+1];
            	aver[i+1] = index2;
   			}
            
    	}
	}
}
/************End*************/


// 函数功能：输出名次表，表格内包括学生编号、各科分数、总分和平均分
/************Begin***********/
void printScore(int n,long num[],int score[][COURSE],int sum[],float aver[]){

    	printf("%8s\t|%6s%6s%6s%7s%8s\n","  NO    ","MT","EN","PH","SUM","AVER");
    	printf("---------------------------------------------------\n");
	for(int i = 0;i < n;i++){
		printf("%ld\t|%6d%6d%6d%7d%8.0f\n",num[i],score[i][0],score[i][1],score[i][2],sum[i],aver[i]);
	}
}

/************End*************/
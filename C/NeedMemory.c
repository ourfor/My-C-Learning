#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

int StringToInt(char* argv_);

int main(int argc,char* argv[]){
	//参数合法性
	if(argv[1]==NULL) printf("Usage: ./NeedMemory i_memory\n");
	//字符转化为数字
	int i_memory=StringToInt(argv[1]); 
	int* array_memory=malloc(sizeof(int)*i_memory);
	int lengthOfargv=0;
	//calculate the length of argv[1]
	for(int i=0;(argv[1][i]-'0'>=0&&argv[1][i]-'0'<=9);i++) {
		lengthOfargv++;
	}
	printf("the address of argv[1] is %d, the context is %s, the length of argv[1] is %d\n",(int)argv[1],argv[1],lengthOfargv);
	printf("Hi, I am the process, which pid is %d, and i malloc %d memory\n",getpid(),i_memory);
	for(;;);

	return 0;
}

	//字符转化为数字
int StringToInt(char* argv_){
	int i_num_memory=0;
	for(int i=0;(argv_[i]-'0'>=0&&argv_[i]-'0'<=9);i++) {
		i_num_memory+=argv_[i]-'0';
		i_num_memory*=10;
	}
	i_num_memory/=10;
	return i_num_memory;
}

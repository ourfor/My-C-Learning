#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc,char* argv[]){
	FILE * fp;
	char filePath[100]="";
	
	//输入文件路径
	printf("输入要读取的文件的路径:");
	scanf("%s",filePath);

	if((fp=fopen(filePath,"ar+"))==NULL){
		printf("文件不存在，文件路径输入错误");
		exit(0);
	}
	char ReadStr[100];
	for(int i=0;i<10;i++){
		fgets(ReadStr,99,fp);
		printf("%s",ReadStr);
	}

	//从文件写入数据
	char WriteStr[100];
	for(int j=0;j<10;j++){
		if(j==0) {
			printf("输入文章标题:");
			getchar();
		}
		else printf("%d:",j);

		cin.getline(WriteStr,99,'\n');
		//scanf("%s",WriteStr);
		strcat(WriteStr,"\n");
		fputs(WriteStr,fp);
	}

	fclose(fp);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	FILE *fp;
	char filePath[100];
	char ReadStr[100]="";
	int DataLength=0;
	int data[100]={0};
	
	printf("输入文件的路径:");
	scanf("%s",filePath);

	if(filePath==NULL){
		printf("文件不存在\n");
		exit(0);
	}

	fp=fopen(filePath,"rw+");

	for(int i=0;!feof(fp)||((DataLength=i)&&0);i++){
		fscanf(fp,"%d ",&data[i]);
	}

	for(int j=0;j<DataLength;j++) fprintf(stdout,"%d ",data[j]);

	fclose(fp);

	return 0;
		
}

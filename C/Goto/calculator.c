#include  <stdio.h>
#include <math.h>
#define EPS 1e-7
int main()
{
    float  data1, data2;
    char  op,reply;
    float data3;
    
Here:
    printf("Please enter the expression:\n");
    scanf("%f %c %f",&data1,&op,&data2);
    getchar();
    switch(op){
        case '+': data3=data1+data2;
            break;
        case '-': data3=data1-data2;
            break;
        case '*': data3=data1*data2;
            break;
        case '/': data3=data1/data2;
            break;
        default: printf("Unknown operator!\n");
            
    }
    printf("%f %c %f = %f\n",data1,op,data2,data3);
    printf("Do you want to continue(Y/N or y/n)?");
    scanf("%c",&reply);
    printf("\n");
    if(reply=='y'||reply=='Y') goto Here;
    else printf("Over!\n");
    
    return 0;
}

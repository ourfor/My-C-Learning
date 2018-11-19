#include <stdio.h>
int main(){

	int a,b,c;
	a=1;
	for(b=1;b<10;b++){
		c=a*b;
		if(a<=b) printf("%d*%d=%d ",a,b,c);
		if(b==9){
			b=1;
			a++;
			printf("\n");
		}
		if(a==10) b=10;
	}
	return 0;
}

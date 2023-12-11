#include<stdio.h>

void message(int *x)  //pointer oldugun gsterr x in
{
	int i;
	for(i=1;i<=*x;i++){
		printf("hello %d\n",i);
	}
}

int main(){
	int value;
	scanf("%d", &value);
	printf("%d\n",value);
	printf("%p\n", &value);
	message(&value);
	//deger olarak aliyor o adresdeki deger lfn
}

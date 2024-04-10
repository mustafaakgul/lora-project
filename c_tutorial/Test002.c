
#include<stdio.h>

int main(){
	/*
	switch(var){
		case state1: results; break;
		
	...
	
	default
	}*/
	
	int x;
	
	comehere : scanf("%d", &x);
	switch(x){
		case 1: printf("1 e");break;
		case 3: printf("3 e");break;
		case 4: printf("4 e");break;
		default:printf("1 3 4 gir");break;
	}
	
	//return 1;
	goto comehere;
	
}

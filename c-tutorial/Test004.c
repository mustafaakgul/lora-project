#include<stdio.h>

int main(){
	
	for(int i=0;i<20;i++){
		if(i%2==0){
			continue;
		}
		else{
			print("%d\n",i);
		}
	}
}

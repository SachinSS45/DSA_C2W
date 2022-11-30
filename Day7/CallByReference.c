#include<stdio.h>
//Defination
void fun(int *x){

	*x = *x + 10;
	printf("%d ",*x);//20
}

void main(){

	int x = 10;//Intialization of Variable 'X'
	fun(&x);//Calling function 'fun'
	printf("%d ",x);//20
}

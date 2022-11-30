
#include<stdio.h>
#include<string.h>
struct cricPlayer{

	int jerNo;
	char pName[10];
	float sal;
}obj1 = {18,"Virat",5.0};


void main(){

	struct cricPlayer obj2;
	obj2.jerNo = 45;
	strcpy(obj2.pName , "Rohit");
	obj2.sal = 7.0;


	printf("JerNo = %d\n",obj1.jerNo);
	printf("PlayerName = %s\n",obj1.pName);
	printf("Salary = %f\n",obj1.sal);

	printf("JerNo = %d\n",obj2.jerNo);
	printf("PlayerName = %s\n",obj2.pName);
	printf("Salary = %f\n",obj2.sal);

}

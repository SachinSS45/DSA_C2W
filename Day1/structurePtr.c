/*
 
   Structre Pointer - pointer which is looking at a structre
   */

#include<stdio.h>
struct Movie{

	char mName[20];
	int noOfTicket;
	float rating;
}obj1 = {"Drisham",5,8.8};


void main(){

	typedef struct Movie mv;
	mv obj2 = {"Kantara",10,9.9};

	mv *sptr1 = &obj1;
	mv *sptr2 = &obj2;

	printf("%s\n",(*sptr1).mName);
	printf("%d\n",sptr1->noOfTicket);
	printf("%f\n",sptr1->rating);
		
	printf("%s\n",(*sptr2).mName);
	printf("%d\n",sptr2->noOfTicket);
	printf("%f\n",sptr2->rating);
}

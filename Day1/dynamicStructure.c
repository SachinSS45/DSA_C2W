#include<stdio.h>

struct OTT{

	char pName[20];
	int usersCnt;
	float price;
};

void main(){
	
	struct OTT *ptr1 = (struct OTT*)malloc(sizeof(struct OTT));

	strcpy(ptr1->pName,"Netflix");
}

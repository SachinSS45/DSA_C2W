#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct Movie{

	char mName[20];
	float imdb;
	struct Movie *next;
}Mov;
//Global Head
Mov *head = NULL;


void addNode(){

	Mov *newNode = (Mov*)malloc(sizeof(Mov));
	
	printf("Enter Movie Name : ");
	
	fgets(newNode->mName,20,stdin);

	printf("Enter Rating : ");
	scanf("%f",&(newNode->imdb));
	getchar();
	newNode->next = NULL;
	
	if(head == NULL){//If node is first

		head = newNode;
	}else{//Add at last
		Mov *temp  = head;
		while(temp->next!=NULL){

			temp = temp->next;
		}
		temp->next = newNode;
	}
}
//Printing Linked List
void print(){

	Mov *temp = head;

	while(temp!=NULL){

		temp->mName[strlen(temp->mName)-1]='\0';//here we use '\0' instead '\n' becz of fgets adds '\n' by default at end of string
		printf("|%s->",temp->mName);
		printf("%f|",temp->imdb);
		temp = temp->next;
		
	}
}

void main(){

	addNode();
	addNode();
	print();

	/* Input :
	Enter Movie Name : RRR
	Enter Rating : 9.1
	Enter Movie Name : Bahubali
	Enter Rating : 9.9
	*/
	/*Output :
		|RRR->9.100000| |Bahubali->9.900000|
	*/
}

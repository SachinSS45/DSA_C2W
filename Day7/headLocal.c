#include<stdio.h>
#include<malloc.h>
typedef struct Student{

	int id;
	float ht;
	struct Student *next;
}stud;

void addNode(stud *head){//head = NULL
	
	stud *newNode = (stud*)malloc(sizeof(stud));
	newNode->id = 1;
	newNode->ht = 5.5;
	newNode->next = NULL;
	head = newNode;// head = 300

}
void printNode(stud *head){// head = NULL;
	
	stud *temp = head;// temp = NULL ( It doesn't print anything becz original value of head in main haven't changed after poping of 'addNode()' method

	while(temp!=NULL){

		printf("%d ",temp->id);
		printf("%f ",temp->ht);
		temp = temp -> next;
	}
	printf("\n");
}
void main(int agrc,char* argv[]){

	stud *head = NULL; 
	
	addNode(head);//addNode(NULL)
	printNode(head);//addNode(NULL)
}


#include<stdio.h>
#include<stdlib.h>

struct Node{

	int data;
	struct Node *next;
};

void main(int argc,char* argv[]){
	
	//Creating head
	struct Node *head = NULL;
	//Creating first Node
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = 10;
	newNode->next = NULL;

	head = newNode;//head looking at first Node
		       
	//creating second node
	newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = 30;
	newNode->next = NULL;
	//Connecting first node to second
	head->next = newNode;

	
	//creating third node
	newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = 20;
	newNode->next = NULL;
	//Connecting second node to third
	head->next->next = newNode;

	//Printing this nodes
	
	struct Node *temp = head;

	while(temp!=NULL){

		printf("%d ",temp->data);
		temp = temp->next;
	}
	// 10 20 30 

}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Nodes{

	int data;
	struct Nodes *next;
}Node;
Node *head = NULL;//Declaring Head Globally
Node* createNode(){

	Node *newNode = (Node*)malloc(sizeof(Node));//Creating New Node on Heap
	printf("Enter Data : ");
	scanf("%d",&(newNode->data));
	newNode->next = NULL;
	
	return newNode;
}
void addNode(){

	Node *newNode = createNode();
	
	if(head==NULL){

		head = newNode;
	}else{
		Node *temp = head;
		while(temp->next!=NULL){

			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void printLL(){
		
	Node *temp = head;

	if(head==NULL){

		printf("Your Linked List is Empty");
	}
	while(temp!=NULL){
		
		if(temp->next !=NULL){
			printf("|%d|->",temp->data);
		}else{
			printf("|%d|",temp->data);
		}
		temp= temp->next;
	}
}
int count(){

	Node *temp = head;
	int cnt = 0;
	while(temp!=NULL){
		cnt ++;
		temp = temp->next;
	}
	return cnt;
}

void addAtFirst(){
	
	Node *newNode = createNode();
	
	if(head==NULL){
		
		head =newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}	
}
void addAtPos(int pos){
	
	int cnt = count();
	if(pos <1 || pos>cnt){

		printf("You have entered wrong pos\n");
	}else if(pos==1){
		addAtFirst();
	}else{


		Node *newNode = createNode();
		Node *temp = head;
		while(pos-2 && (temp->next!=NULL)){ // If someone enters position greater than count of Linkedlist
		
		temp =temp->next;
		pos--;
	       }

	newNode->next = temp->next;
	temp->next = newNode;
	}
	
}
void addLast(){

	addNode();
}

void deleteFirst(){

	Node *temp = head;

	if(head == NULL){

		printf("Your LinkedList is Empty\n");
	}else{
	head = temp->next;
	free(temp);
	}
}

void deleteAtPos(int pos){
	
	Node *temp = head;
	if(pos<1){

		printf("You have entered wrong pos it must be greater than zero\n");
	}else if(head == NULL){

		printf("Your LinkedList is Empty \n");
	}else if(pos==1){
		
		deleteFirst();
	}else{
	
		while(pos-2 && (temp->next!=NULL)){ // If someone enters position greater than count of Linkedlist
		
		temp =temp->next;
		pos--;
		}


		Node *temp2 = temp->next;
		temp->next = temp->next->next;
		temp2->next = NULL;
		free(temp2);
	}
}
void deleteLast(){

	Node *temp = head;
	
	if(head == NULL){

		printf("Your LinkedList is Empty\n");
	}else if(head->next==NULL){
		
		deleteFirst();
	}else{
		while(temp->next->next !=NULL){

			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}
void main(){
	
	
	
	char ch;
	do {	
		printf("Which Operation do you want :\n");
		printf("\t1.addNode\n");
		printf("\t2.Count nodes in Linked List\n");
		printf("\t3.Add at first\n");
		printf("\t4.Add at specific positon\n");
		printf("\t5.Add at Last\n");
		printf("\t6.deleteFirst\n");
		printf("\t7.delete from specific positon\n");
		printf("\t8.deleteLast\n");
		printf("\t9.printLinkedList\n");
		int choice;
		printf("Enter your choice : ");
		scanf("\t%d",&choice);
		switch(choice){

			case 1:
				addNode();
				break;
			case 2:
				printf("Number of Nodes in LL : %d",count());
				break;
			case 3:
				addAtFirst();
				break;
			case 4:
				int pos;
				printf("At which position do you want to inset : ");
				scanf("%d",&pos);
				addAtPos(pos);
				break;
			case 5:
				addNode();
				break;
			case 6:
				deleteFirst();
				break;
			case 7:
				int pos1;
				printf("At which position do you want to inset : ");
				scanf("%d",&pos1);
				deleteAtPos(pos1);
				break;
			case 8:
				deleteLast();
				break;
			case 9:
				printLL();
				break;
			default:
				printf("You entered wrong choice\n");
				break;
			}
			getchar();
			printf("\nDo you want any other functionality again if yes type 'y' OR 'Y': ");
			scanf("%c",&ch);


		}while(ch=='y'||ch=='Y');
}

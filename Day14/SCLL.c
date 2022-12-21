#include<stdio.h>
#include<stdlib.h>

typedef struct Nodes{

	int data;
	struct Nodes *next;
}Node;

Node *head = NULL;

Node* createNode(){

	Node* newNode =(Node*)malloc(sizeof(Node));

	printf("Enter data:\n");
	scanf("%d",&newNode->data);

	newNode->next = NULL;

}

void addNode(){

	Node *newNode = createNode();
		
	if(head==NULL){

		head = newNode;
		newNode->next = head;
	}else{
		Node *temp = head;
		while(temp->next!=head){

			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;


	}

}

int printSCLL(){

	if(head==NULL){

		printf("LL is Empty\n");
		return -1;
	}else{
		Node *temp = head;
		while(temp->next!=head){
			
			printf("|%d|->",temp->data);
			temp = temp->next;
		}
		
		printf("|%d|",temp->data);
		printf("\n");
	}
}

void addAtFirst(){

	Node *newNode = createNode();
	
	if(head==NULL){

		head = newNode;
		newNode->next = head;
	}else{

		Node *temp = head;

		while(temp->next!=head){

			temp = temp->next;
		}
		temp ->next = newNode;
		newNode->next = head;
		head = newNode;
	}

}
int count(){

	Node *temp = head;

	if(head==NULL){

		printf("LL is Empty\n");
		return 0;
	}
	int cnt = 1;
	while(temp->next!=head){
			
		cnt++;
		temp = temp->next;
	}
	return cnt;
}
			
int addAtPos(int pos){
	
	int cnt = count();
	if(pos<=0 || pos>cnt+1){

		printf("Invalid Position\n");
	}else if(pos==1){

		addAtFirst();
	}else if(pos == cnt+1){

		addNode();
	}else{
		Node *newNode = createNode();
		Node *temp = head;

		while(pos-2){

			temp = temp->next;
			pos--;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void addAtLast(){
	addNode();
}
int deleteFirst(){

	Node *temp = head;
	if(head==NULL){

		printf("LL is Empty");
		return -1;
	}else{

		if(temp->next==head){
			
			free(head);
			head = NULL;

		}else{	
			while(temp->next!=head){
			
				temp = temp->next;
			}
			head = head->next;
			free(temp->next);
			temp->next = head;
		}

	}
}

int deleteLast(){

	
	Node *temp = head;
	if(head==NULL){

		printf("LL is Empty");
		return -1;
	}else if(temp->next == head){

		deleteFirst();
	}else{

		while(temp->next->next!=head){

			temp = temp->next;
		}
		free(temp->next);

		temp->next = head;
	}
}
int deleteAtPos(int pos){

	 int cnt=count();

	 if(pos<1 || pos>cnt){ 

		printf("Invalid Position\n");
	 }else if(pos==1){

		deleteFirst();
	 }else if(pos==cnt){

		deleteLast();
	 }else {
		 
		Node * temp=head;

		while(pos-2){
			temp=temp->next;
			pos--;
		}

		Node * temp2=temp->next;
		temp->next=temp->next->next;
		temp2->next=NULL;
		free(temp2);
	}
}


void main(){

	char ch;
	int pos,pos1,num,nd;

	do{
		printf("Which Operation do You want : \n");
		printf("1.addNode\n");
		printf("2.Count Nodes in Linked List\n");
		printf("3.Add at First\n");
		printf("4.Add at Position\n");
		printf("5.Add at last \n");
		printf("6.Delete first\n");
		printf("7.Delete at Position\n");
		printf("8.Delete last\n");
		printf("9.Print Linked List\n");

		int choice;
		printf("Enter Your Choice : \n");
		scanf("%d",&choice);

		switch(choice){

			case 1 : 
				printf("How Many Nodes Do You want to create : ");
				scanf("%d",&nd);
				for(int i=0 ; i<nd ; i++){
					addNode();
				}
				break;
			case 2 : 
				printf("Count of Nodes in Linked List Are : %d",count());
				break;
			case 3 : 
				addAtFirst();
				break;
			case 4 : 
				printf("At which Position do You want to insert : \n");
				scanf("%d",&pos);
				addAtPos(pos);
				break;
			case 5 :
				addAtLast();
				break;
			case 6 : 
				deleteFirst();
				break;
			case 7 : 
				printf("At which position do you want to delete : \n");
				scanf("%d",&pos1);
				deleteAtPos(pos1);
				break;
			case 8 :
				deleteLast();
				break;
			case 9 :
				printSCLL();
				break;
			default :
				printf("Invalid Input : ");


		}
		getchar();
		printf("\nDo you want any other Functionalities again if yes type 'Y' || 'y' : ");
		scanf("%c",&ch);
	}
	while(ch=='y'||ch=='Y');


}

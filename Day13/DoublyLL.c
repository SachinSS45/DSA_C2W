#include<stdio.h>
#include<stdlib.h>

 /*
		A doubly linked list is a type of linked list in which each node consists of 3 components:

		    (1)*prev - address of the previous node
		    (2)data - data item
		    (3)*next - address of next node
                  

	                -------------	        ------------	      -------------
	-head|100|---->	|NULL|10|200|<--------->|100|20|300|<-------->|200|30|NULL|
		        100----------	        200---------	      300-----------
*/    

typedef struct Nodes{

	int data;
	struct Nodes *next;
	struct Nodes *prev;
}Node;


Node *head = NULL;//Head declaring Globally 
//Creating New Node
Node* createNode(){

	Node *newNode = (Node*)malloc(sizeof(Node));
	
	printf("Enter data : ");
	scanf("%d",&newNode->data);
	
	newNode->prev = NULL;
	newNode->next = NULL;
}
	
//Add at Last in DLL
void addNode(){

	Node *newNode = createNode();

	if(head ==NULL){

		head = newNode;
	}else{
		Node *temp = head;

		while(temp->next != NULL){

			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}

}
//Length of DLL
int count(){

	int cnt = 0;
	Node *temp = head;
	while(temp!=NULL){

		cnt++;
		temp = temp->next;
	}

	return cnt;
}
//Traversing a DLL
void printLL(){

	Node *temp = head;

	if(head==NULL){

		printf("LL is Empty\n");
	}else{

		while(temp!=NULL){

			printf("|%d|",temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}
//Adding node at first of LL
void addAtFirst(){

	Node *newNode = createNode();
	Node *temp = head;

	if(head == NULL){

		head = newNode;
	}else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}
//Add at Position

void addAtPos(int pos){

	Node *temp = head;
	int cnt = count();
	if(pos<1 && pos > cnt+1){

		printf("Invalid Pos\n");
	}else if(pos==1){

		addAtFirst();
	}else if(pos==cnt+1){

		addNode();
	}else{
		Node *temp = head;
		Node *newNode = createNode();
		while(pos-2){

			temp = temp->next;
			pos--;
		}

		newNode->next = temp->next;
		temp->next->prev = newNode;
		newNode->prev = temp;
		temp->next = newNode;
	}
}

void deleteFirst(){

	if(head==NULL){

		printf("LL is Empty\n");
	}else{
		Node *temp = head;
	/*	head = temp->next;
		head->prev->next = NULL;
		free(head->prev);
		head->prev = NULL;*/

		temp->next->prev = NULL;
		head = temp->next;
		temp->next = NULL;
		free(temp);
	}
}
//Delete Last

void deleteLast(){
	
	Node *temp = head;
	if(head==NULL){

		printf("LL is Empty\n");
	}else if(temp->next ==NULL){

		deleteFirst();
	}else{

		while(temp->next->next!=NULL){
			
			temp->next->prev = NULL;
			free(temp->next);
			temp->next = NULL;

		}
		/* OR 
		 while(temp->next!=NULL){
		 	
		 	temp->prev->next = NULL;
			temp->prev = NULL;
			free(temp);
		}
		*/
	}
}

//Deletion from Pos

void deleteAtPos(int pos){

	Node *temp = head;
	int cnt = count();
	if(pos<1 || pos > cnt+1){

		printf("Invalid Pos\n");
	}else if(pos==1){

		deleteFirst();
	}else if(pos==cnt){
		
		deleteLast();
	}else{

		while(pos-2){

			temp = temp->next;
			pos--;
		}
		
		Node *temp2 = temp->next;
		temp2->next->prev = temp;
		temp->next = temp2->next;
		temp2->next = NULL;
		temp2->prev = NULL;
		free(temp2);
	}
}



//Starts From here
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
		scanf("\t%d", &choice);
		switch (choice) {

		case 1:
			addNode();
			break;
		case 2:
			printf("Number of Nodes in LL : %d", count());
			break;
		case 3:
			addAtFirst();
			break;
		case 4:
			int pos;
			printf("At which position do you want to insert : ");
			scanf("%d", &pos);
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
			printf("From which position do you want to delete : ");
			scanf("%d", &pos1);
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
		scanf("%c", &ch);


	} while (ch == 'y' || ch == 'Y');


}



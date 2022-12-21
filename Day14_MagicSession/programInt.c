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

int firstOccurence(int key){

	Node *temp = head;

	if(head==NULL){

		printf("Empty LL");
		return -1;//Abbortive Return
	}else{
		int count = 0;
		int flag = 1;
		while(temp!=NULL){
			
			count++;
			if(temp->data == key){
				flag = 0;
				printf("%d firstly occured at %d positin\n",key,count);
				break;
			}
			temp = temp->next;
		}

		if(flag){

			printf("Not Found\n");
		}

		
	}
}

int totalOccurence(int key){

	Node *temp = head;

	if(temp==NULL){

		printf("Empty LL");
		return -1;//abbortive return
	}else{
		int count = 0;
		while(temp!=NULL){
			
			
			if(temp->data == key){

			   count++;
			}
			temp = temp->next;
		}

		printf("Total Occurences of %d : %d\n",key,count);
	}
}

int SeclastOccurence(int key){

	Node *temp = head;
		
	if(head == NULL){

		printf("LL is Empty\n");
		return -1;//abbortive Return
	}else{
		int count = 0;
		int prev=0,curr=0;
		while(temp!=NULL){
			
			count++;
			if(temp->data == key){
				
				prev = curr;
				curr = count;
			
			}
			temp = temp->next;
		}
	
		if(prev==curr){

			printf("Not Valid Input");
		}else if(prev==0){

			printf("%d Occured Only Once at %d position\n",key,curr);
		}else{
			printf("Second Last Occurence of %d is at %d Position\n",key,prev);
		}
	}
}

int sumofData(){

	Node *temp = head;

	if(head==NULL){

		printf("LL is Empty\n");
		return -1;//Abbortive Return
	}else{
		while(temp!=NULL){

			int num = temp->data;
			int sum = 0;
			while(num){

				int rem = num%10;
				sum = sum + rem;
				num = num/10;
			}
			temp->data = sum;
			temp = temp->next;
		}
	}
}
int allPalindrome(){

	Node *temp = head;

	if(head==NULL){

		printf("LL is Empty\n");
		return -1;//Abbortive return
	}else{
		int count =0;
		while(temp!=NULL){
			
			temp++;
			int num = temp->data;
			int rev = 0;
			while(num){

				int rem = num%10;
				rev = rev*10 + rem;
				num = num/10;
			}
			if(rev==temp->data){

				printf("Palindrome found at %d\n",count);
			}
			temp = temp->next;
		}
	}
}


void main(){

	char ch;
	int key;
	int num;

	do{
		printf("Which Operation do you want ? \n");
		printf("1.addNode\n");
		printf("2.Count Node\n");
		printf("3.Print Linked List\n");
		printf("4.find first Occurence of Element\n");
		printf("5.find Second Last Occurence of Element\n");
		printf("6.find total Occurence of Element\n");
		printf("7.Program that adds the digits of a data elements and change in original LL\n");
	        printf("8.Program that find palindrome data elements\n");
		
		int choice;
		printf("\nEnter Your Choice : \n");
		scanf("%d",&choice);

		switch(choice){

			case 1:
				printf("How many nodes do you want to create : ");
				scanf("%d",&num);
				for(int i=1;i<=num;i++){

					addNode();
			       	}
				break;
			case 2: 
				printf("Number of Nodes in LL:%d\n",count());
				break;
			case 3:
				printLL();
				break;
			case 4:
				printf("Enter element do you want to search : ");
				scanf("%d",&key);
				firstOccurence(key);
				break;
			case 5:
				printf("Enter element do you want to search : ");
				scanf("%d",&key);
				SeclastOccurence(key);
				break;
			case 6:
				printf("Enter element do you want to search : ");
				scanf("%d",&key);
				totalOccurence(key);
				break;
			case 7:
				sumofData();
				break;
			case 8:
				allPalindrome();
				break;
			case 9:
				printf("Wrong Choice\n");
				break;
		}
		getchar();
		printf("\nDo you want any other Functionalities again if yes type 'Y' || 'y' : ");
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
}

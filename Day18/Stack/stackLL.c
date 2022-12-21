#include<stdio.h>
#include<stdlib.h>
typedef struct Nodes{

	int data;
	struct Nodes *next;
}Stack;
int size;
int flag = 1;
Stack *head = NULL;


int count(){

	Stack *temp = head;
	int cnt = 0;
	while (temp!=NULL)
	{
		temp = temp->next;
		cnt++;
	}
	return cnt;
	
}
Stack* createNode(){

	Stack* newNode = (Stack*)malloc(sizeof(Stack));
	if(count()!= size){
	printf("Enter data : ");
	scanf("%d",&newNode->data);
	}
	newNode->next = NULL;
	return newNode;
}

int push(){
	
	Stack *newNode = createNode();
	
	if(count()==size){
		printf("stack OverFlow\n");
		return -1;
	}else{
		if(head==NULL){
			head = newNode;
		}else{
			Stack *temp = head;
			while(temp->next !=NULL){

				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
}


int pop(){

	if(head==NULL){
		printf("Stack Underflow\n");
		flag = 0;
		return -1;
	}else{
		int ret = 0;
		if(head->next==NULL){

			ret  = head->data;
			free(head);
			head = NULL;
			return ret;
		}else{
			Stack *temp = head;
			while(temp->next->next !=NULL){
				temp = temp->next;
			}

			ret = temp->next->data;
			free(temp->next);
			temp->next = NULL;
			return ret;

		}
	}	
}	
	


int peek(){

	Stack *temp = head;
	if(head==NULL){
		printf("Stack Underflow\n");
		return -1;
	}else{

		while(temp->next!=NULL){
			temp = temp->next;
		}
		printf("Peek element : %d\n",temp->data);
	}
}
void main(){

	printf("Enter the size of Stack : \n");
	scanf("%d",&size);
	

	char ch;
	do{
		printf("Which operation you want to do stack :\n");
		printf("1.push()\n");
		printf("2.pop()\n");
		printf("3.peek()\n");
		int choice;
		scanf("%d",&choice);

		switch(choice){

			case 1:
				push();
				break;
			case 2:{
				int ret = pop();
				if(flag){
					printf("Popped element is %d\n",ret);
				}
				break;
			}
			case 3:
				peek();
				break;
			default:
				printf("Invalid Choice\n");
		}

		getchar();
		printf("Do you want to continue:\n");
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');


}

#include<stdio.h>
#include<stdlib.h>
typedef struct Queues{

	int data;
	struct Queues *next;
}Queue;

Queue *front = NULL;
Queue *rear = NULL;
int flag = 0;
Queue* createNode(){
	Queue *newNode = (Queue*)malloc(sizeof(Queue));
	printf("Enter Data:");
	scanf("%d",&newNode->data);

	newNode->next = NULL;
	return newNode;
}

int enqueue(){
	Queue *newNode = createNode();
	if(front==NULL && rear==NULL){
		front = newNode;
		rear = newNode;
	}else{
		rear->next = newNode;
		rear = newNode;
		return 0;
	}
}

int dequeue(){

	if(front==NULL){
		flag = 0;
		return -1;
	}else{
		int ret = front->data;
		Queue *temp = front;		
		flag = 1;
		front = front->next;
		if(front==NULL){
			rear = NULL;
		}
		free(temp);
	

		return ret;
	}
}

int printQueue(){

	if(front == NULL && rear==NULL){

		return -1;
	}else{
		Queue *temp = front;

		while(temp!=NULL){

			printf("|%d| ",temp->data);
			temp = temp->next;
		}
		printf("\n");
		return 0;
	}
}

int frontt(){

	if(front==NULL && rear==NULL){
		flag = 0;
		return -1;
	}else{
		flag = 1;
		return front->data;
	}
}

void main(){



	char choice;
	//printf("Which Operation Do you want to check : ");
	do{
		printf("Which Operation Do you want to check : ");
		printf("\t1.enqueue()\n");
		printf("\t2.dequeue()\n");
		printf("\t3.front()\n");
		printf("\t4.printQueue()\n");
		

		int ch;
		printf("Enter Your Choice : ");
		scanf("%d",&ch);

		switch(ch){

			case 1: {
					int ret = enqueue();
					if(ret==-1){

						printf("Queue is Overflow\n");
					}
				}
				break;
			case 2:{
				       int ret = dequeue();
				       if(flag==1){

					       printf("%d is dequeued\n",ret);
				       }else{
					       printf("Queue is Underflow\n");
				       }
			       }
			       break;
			case 3:
			       {
				       int ret = frontt();
				       if(flag == 0){
					       printf("Queue is Underflow\n");
				       }else{
					       printf("Front = %d\n",ret);
				       }
			       }
			       break;
			case 4:
			       {
				       int ret = printQueue();
				       if(ret==-1){
					       printf("Queue is Empty..\n");
				       }
			       }
			       break;
			default:
			       printf("You Entered Wrong Choice\n");
			       break;
		}
		getchar();
		printf("Do you want to continue ? ");
		scanf("%c",&choice);
	}while(choice == 'y' || choice=='Y');

}

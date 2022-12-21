#include<stdio.h>
int size = 0;
int front = -1;
int rear = -1;
int flag = 0;

int enqueue(int arr[]){

	if(rear == size-1)
		return -1;
	else{
		if(front==-1){
			front++;
		}
		rear++;
		printf("Enter Data:");
		scanf("%d",&arr[rear]);
		return 0;
	}
}

int dequeue(int *arr){

	if(front==-1 || front>rear){
		flag = 0;
		return -1;
	}else{
		int ret = arr[front];
		
		flag = 1;
		if(front==rear){
			front=-1;
			rear= -1;
		}else{
			front++;
		}

		return ret;
	}
}

int printQueue(int *arr){

	if(front == -1){

		return -1;
	}else{
		for(int i=front;i<=rear;i++){

			printf("|%d| ",arr[i]);
		}printf("\n");
		return 0;
	}
}

int frontt(int *arr){

	if(front==-1){
		flag = 0;
		return -1;
	}else{
		flag = 1;
		return arr[front];
	}
}

void main(){

	printf("Enter the Size : ");
	scanf("%d",&size);

	int arr[size];

	char choice;
	//printf("Which Operation Do you want to check : ");
	do{
		printf("Which Operation Do you want to check : ");
		printf("\t1.enqueue()\n");
		printf("\t2.dequeue()\n");
		printf("\t3.front()\n");
		printf("\t4.printQueue()\n");
		printf("\t5.isFull()\n");

		int ch;
		printf("Enter Your Choice : ");
		scanf("%d",&ch);

		switch(ch){

			case 1: {
					int ret = enqueue(arr);
					if(ret==-1){

						printf("Queue is Overflow\n");
					}
				}
				break;
			case 2:{
				       int ret = dequeue(arr);
				       if(flag==1){

					       printf("%d is dequeued\n",ret);
				       }else{
					       printf("Queue is Underflow\n");
				       }
			       }
			       break;
			case 3:
			       {
				       int ret = frontt(arr);
				       if(flag == 0){
					       printf("Queue is Underflow\n");
				       }else{
					       printf("Front = %d\n",ret);
				       }
			       }
			       break;
			case 4:
			       {
				       int ret = printQueue(arr);
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

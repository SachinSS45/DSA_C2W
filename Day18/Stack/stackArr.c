#include<stdio.h>
int size;
int top = -1;
int flag = 1;
int push(int stack[]){
	
	if(top==size-1){

		printf("Stack Overflow\n");
		return -1;
	}else{
		printf("Enter data : ");
		top++;
		scanf("%d",stack+top);
		return 0;
	}
}
int pop(int *stack){
	
	if(top==-1){
		flag = 0;
		printf("Stack Underflow\n");
		return -1;
	}else{
		
		top--;
		return (stack[top+1]);
	}
}
int peek(int *stack){
	
	if(top==-1){

		printf("Stack Underflow\n");
		return -1;
	}
		printf("Peek Element : %d\n",stack[top]);
		return 0;
	
}

void main(){
	
	printf("Enter the size of Stack : \n");
	scanf("%d",&size);
	int stack[size];

	char ch;
	do{
		printf("Which operation you want to do stack :\n ");
		printf("1.push()\n");
		printf("2.pop()\n");
		printf("3.peek()\n");
		int choice;
		scanf("%d",&choice);

		switch(choice){

			case 1:
				push(stack);
				break;
			case 2:{
				int ret = pop(stack);
				if(flag){
					printf("Popped element is %d\n",ret);
				}
				break;
			}
			case 3:
				peek(stack);
				break;
			default:
				printf("Invalid Choice\n");
		}

		getchar();
		printf("Do you want to continue:\n");
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');

}

#include<stdio.h>
#include<malloc.h>
typedef struct Student{

	int id;
	float ht;
	struct Student *next;
}stud;

stud* addNode(stud *head){//head = NULL
	
	stud *newNode = (stud*)malloc(sizeof(stud));
	newNode->id = 1;
	newNode->ht = 5.5;
	newNode->next = NULL;
	head = newNode;// head = 300
	return head;

}
void printNode(stud *head){// head = 300
	
	stud *temp = head;//temp = 300

	while(temp!=NULL){

		printf("%d ",temp->id);
		printf("%f ",temp->ht);
		temp = temp -> next;
	}
	printf("\n");
}
void main(int agrc,char* argv[]){

	stud *head = NULL; 
	
	head = addNode(head);//addNode(NULL)
	printNode(head);//addNode(300) // 1 5.5
}


#include<stdio.h>
#include<malloc.h>
typedef struct Student{

	int id;
	float ht;
	struct Student *next;
}stud;
stud *head = NULL;
void addNode(){
	
	stud *newNode = (stud*)malloc(sizeof(stud));
	newNode->id = 1;
	newNode->ht = 5.5;
	newNode->next = NULL;
	head = newNode;// head = 300

}
void printNode(){
	
	stud *temp = head;// 300

	while(temp!=NULL){

		printf("%d ",temp->id);
		printf("%f ",temp->ht);
		temp = temp -> next;
	}//1 5.5
	printf("\n");
}
void main(int agrc,char* argv[]){

	addNode();//addNode(NULL)
	printNode();//head = 300
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Nodes{

	char name[20];
	struct Nodes *next;
}Node;
Node *head = NULL;//Declaring Head Globally
Node* createNode(){

	Node*newNode = (Node*)malloc(sizeof(Node));//Creating New Node on Heap

	getchar();//for removing '\n'
	printf("Enter name : ");
	int i=0;
	char ch;
	while((ch=getchar())!='\n'){//We can get output in single line 
		newNode->name[i] = ch;
		i++;
	}
	
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

        if(temp->next!=NULL){
		    printf("|%s|->",temp->name);
        }else{
             printf("|%s|",temp->name);
        }
		
		temp = temp ->next;
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
void deleteAtPos(int pos){
	
	Node *temp = head;
    int cnt = count();
	if(pos<=0 || pos>cnt){

		printf("Invalid Input\n");
	}else if(pos==1){

		
        head = head->next;
        free(temp);
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
int mystrlen(char *str){

    int cnt = 0;
    while(*str!='\0'){
        cnt++;
    }
    return cnt;
}
int comparelen(int len){


     Node *temp = head;

    if(head==NULL){

            printf("LL is Empty\n");
            return -1;
    }
    int flag = 1;
    while(temp!=NULL){
        
        
        if(mystrlen(temp->name)==len){
            printf("%s\n",temp->name);
            flag = 0;
        }        
    }
    if(flag){
        printf("None of string is matching to lenght %d\n",len);
    }
}

void reverse(char *str){

    int start = 0;
    int end = mystrlen(str)-1;

    while(start<end){

        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int revdataEle(){

    Node *temp = head;

    if(head==NULL){
        printf("LL is Empty\n");
        return -1;
    }
    while(temp!=NULL){

        reverse(temp->name);

	temp = temp->next;
        
    }
}

int deletelenstr(int len){


    Node *temp = head;

    if(head==NULL){

            printf("LL is Empty\n");
            return -1;
    }
    
    int cnt = 0;
    while(temp!=NULL){
        
        cnt++;
        if(mystrlen(temp->name)!=len){
            deleteAtPos(cnt);
        }        
    }
    printLL();
}
void main(){

    	  char ch;
          int num = 0;
	  do {	
	    	printf("Which Operation do you want :\n");
	       	printf("\t1.addNode\n");
		printf("\t2.Count nodes in Linked List\n");
        	printf("\t3.printLinkedList\n");
		printf("\t4.Printing strings where user gives len\n");
	        printf("\t5.reverse string which are in nodes data\n");
        	printf("\t6.keep Nodes Only that matches to users len\n");
		
		int choice;
		printf("Enter your choice : ");
		scanf("\t%d",&choice);
		getchar();
		switch(choice){

			case 1:
				printf("How many nodes do you want : ");
                		scanf("%d",&num);
				getchar();
                		for(int i=1;i<=num;i++){
					    addNode();
               			 }
				break;
			case 2:
				printf("Number of Nodes in LL : %d",count());
				break;
	                case 3:
				printLL();
				break;
			case 4:
                
              			int len;
                		printf("Enter which lengths Names do you want :\n");
                		scanf("%d",&len);
				getchar();

                	        comparelen(len);
                		break;
            		case 5:
                		revdataEle();
                		break;
            		case 6:
                		printf("Enter which lengths Names do you want :\n");
                		scanf("%d",&len);
				getchar();
				deletelenstr(len);
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



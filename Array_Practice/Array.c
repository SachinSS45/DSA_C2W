#include<stdio.h>
#include<stdbool.h>
bool search(int *,int ,int);
void reverse(int *,int);
void sort(int *,int);
int largest(int *,int);
int secondLarge(int *,int);
int smallest(int *,int);
int secondSmall(int *,int);
void insert(int*,int*,int ,int);
void delete(int*,int*,int);

bool search(int arr[],int size,int key){
	
	for(int i=0;i<size;i++){

		if(arr[i] == key){

			return true;
		}
	}
	return false;
	
}

void reverse(int arr[],int size){

	int start = 0;
	int end = size -1;
	while(start<=end){

		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}

	for(int i=0;i<size;i++){

		printf("%d ",arr[i]);
	}
	printf("\n");
}

void sort(int arr[],int size){
	//Bubble
//	int count = 0;	
	for(int i=0;i<size-1;i++){
		int flag = 1;
		for(int j=0;j<size-1-i;j++){

			if(arr[j]>arr[j+1]){

				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
			}

			
		}
		if(flag){
			break;
		}
	}
	for(int i=0;i<size;i++){

		printf("%d ",arr[i]);
	}
//	printf("%d ",count);
}
int secondSmall(int arr[],int size){
	//SelectionSort
	
	if(size <2){

		return -1;
	}
	for(int i=0;i<2;i++){
		int flag = 1;
		int mini = i;
		for(int j=i+1;j<size;j++){

			if(arr[j]<arr[mini]){

				mini = j;
				flag = 0;
			}	
		}

		int temp = arr[mini];
		arr[mini] =arr[i];
		arr[i] = temp;
		if(flag ==1){

			break;
		}

	}
	return arr[1];
}

int largest(int arr[],int size){

	int max = arr[0];

	for(int i=1;i<size;i++){

		if(arr[i]>max){

			max = arr[i];
		}
	}
	return max;
}
int smallest(int arr[],int size){

	int min = arr[0];

	for(int i=1;i<size;i++){

		if(arr[i]<min){

			min = arr[i];
		}
	}
	return min;
}
int secondLarge(int arr[],int size){
		
	for(int i=0;i<2;i++){
		int flag = 1;
		for(int j=0;j<size-1-i;j++){

			if(arr[j]>arr[j+1]){

				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
			}			
		}
		if(flag){
			break;
		}
	}
	
	return (arr[size-2]);
}

void insert(int arr[],int* size,int ele,int pos){

	*size = *size + 1;
	//printf("%d\n",*size);
	//arr[*size-1] = ele;

	for(int i=(*size)-1;i>pos;i--){

		arr[i] = arr[i-1];
	}
	arr[pos] = ele;
	for(int i=0;i<*size;i++){

		printf("%d ",arr[i]);
	}

}
void delete(int arr[],int* size,int pos){

	
	//printf("%d\n",*size);
	//arr[*size-1] = ele;

	for(int i=pos;i<(*size)-1;i++){

		arr[i] = arr[i+1];
	}
	*size = *size -1;
	for(int i=0;i<*size;i++){

		printf("%d ",arr[i]);
	}
	

}


void main(){
		
	int arr[100];
	int size;
	char ch;
	do{
	printf("\nEnter which Operation Do you want to do :\n ");
	printf("\t1.Search element in Array\n");
	printf("\t2.Reverse Array\n");
	printf("\t3.Sort Array\n");
	printf("\t4.Largest Element In array\n");
	printf("\t5.Second Largest Element In array\n");
	printf("\t6.Smallest Element In array\n");
	printf("\t7.Second Smallest Element In array\n");
	printf("\t8.Insert Element in Array\n");
	printf("\t9.Delete element from Array\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){

		case 1:
			
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			int key;
			printf("Enter which element do you want to search : ");
			scanf("%d",&key);
			if(search(arr,size,key)){

				printf("%d is found in array\n",key);
			}else{
				printf("%d is not found in array\n",key);
			}
			break;
		case 2:
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			search(arr,size,key);
			break;
		case 3:
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			sort(arr,size);

	
			break;
		case 4:
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			printf("Largest Element In array : %d \n",largest(arr,size));
			break;
		case 5:
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			printf("Second Largest Element In array : %d \n",secondLarge(arr,size));
			break;
		case 6:
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			printf("Smallest Element In Array : %d\n",smallest(arr,size));
			break;
		case 7:
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			printf("Second Smallest Element In Array : %d\n",secondSmall(arr,size));
			break;
		case 8:
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			int pos;
			printf("Enter postion where you want insert a elment :");
			scanf("%d",&pos);
			int ele ;
			printf("Enter which element do you want insert");
			insert(arr,&size,ele,pos);
			
			break;
		case 9:
			printf("Enter the Size of array <= 100 : ");
			scanf("%d",&size);

			printf("Enter the elements in array : ");
			for(int i=0;i<size;i++){
				
				scanf("%d",&arr[i]);
			}
			printf("Enter postion from which you want delete an elment :");
			scanf("%d",&pos);
			delete(arr,&size,pos);
	
			break;
		
		
		}	

	printf("Do you want to any other operation if yes type 'y' OR 'Y' : ");
	scanf(" %c",&ch);
	}while(ch=='Y' || ch=='y');

}

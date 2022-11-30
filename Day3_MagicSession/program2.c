/*
 2.WAP that dynamically allocates a 1-D Array of marks,takes value from the user,and prints it.[use malloc()]

 Draw a dig on notebook
 */

#include<stdio.h>
#include<stdlib.h>

void main(){

	int size;
	printf("How many elements do you want in array : ");
	scanf("%d",&size);

	int *arr = (int *)malloc(size*sizeof(int));//allocating memory dyanamically

	printf("Enter the elements in array : ");

	for(int i=0;i<size;i++){//Talking inputs in array

		scanf("%d",arr+i);
	}

	printf("The elements in array : ");
	for(int i=0;i<size;i++){//Printing elements of array

		printf("%d ",*(arr+i));
	}
	printf("\n");
	free(arr);
}

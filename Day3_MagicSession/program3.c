/*
 3.WAP that dynamically allocates a 2-D Array of integers,takes value from the user,and prints it.[use malloc()]
	rows = 3    col = 4
 Draw a dig on notebook
 */

#include<stdio.h>
#include<stdlib.h>

void main(){

	int row,col;
	printf("Enter the numbers of rows and cols which you want  : ");
	scanf("%d%d",&row,&col);

	int *arr = (int *)malloc(row*col*sizeof(int));//allocating memory dyanamically

	printf("Enter the elements in array : ");

	for(int i=0;i<row*col;i++){//Talking inputs in array
		
			scanf("%d",arr+i);
	
	}

	printf("The elements in array :\n");
	for(int i=0;i<row;i++){//Printing elements of array
			
		for(int j=0;j<col;j++){
				
				printf("%d ",*(arr + i*row + j));
		}
		printf("\n");
	}
	free(arr);
}

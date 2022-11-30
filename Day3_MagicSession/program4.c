/*
 4.WAP that dynamically allocates a 3-D Array of integers,takes value from the user,and prints it.[use malloc()]
	plane = 2 row = 3 col = 4
 Draw a dig on notebook
 */

#include<stdio.h>
#include<stdlib.h>

void main(){

	int plane,row,col;
	printf("Enter the numbers of rows and cols which you want  : ");
	scanf("%d%d%d",&plane,&row,&col);

	int *arr = (int *)malloc(plane*row*col*sizeof(int));//allocating memory dyanamically

	printf("Enter the elements in array : ");

	for(int i=0;i<plane*row*col;i++){//Talking inputs in array
		
			scanf("%d",arr+i);
	
	}

	printf("The elements in array :\n");
	for(int i=0;i<plane;i++){//Printing elements of array
			
		for(int j=0;j<row;j++){
			
			for(int k=0;k<col;k++){	
				printf("%d ",*(arr + i*row*col + j*row + k));
			}
			printf("\n");
		}
		
	}
	free(arr);
	
}

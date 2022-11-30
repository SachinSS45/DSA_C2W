#include<stdio.h>

int linearSearch(int arr[],int size,int key){

    for(int i=0;i<size;i++){

        if(arr[i]==key){

            return 1;
        }
    }
    return 0;
}

int binarySearch(int arr[],int size,int key){

    int start = 0;
    int end = size - 1;

    int mid = (start + end)/2;

    while(start<=end){

        if(key==arr[mid]){
            return 1;
        }
        if(key > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }

        mid = (start + end)/2;
    }
    return 0;
}
void main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int arr[100];
    printf("Enter the elements in array : ");
    for(int i=0;i<size;i++){

        scanf("%d",(arr+i));    
    }
    
    for(int i=0;i<size;i++){

        printf("%d ",*(arr+i));    
    }
    printf("\n");

    int key;
    printf("Enter which element do you want to find:");
    scanf("%d",&key);
    
    int choice;
    printf("Which Search do you want to do :\n");
    printf("1.LinearSearch\n");
    printf("2.BinarySearch\n");
    scanf("%d",&choice);

    switch(choice){

        case 1:
                if(linearSearch(arr,size,key)){
                     printf("%d is present in array\n",key);
                }else{
                    printf("%d is present in array\n",key);
                }
                break;
        case 2:
                printf("Firstly we will check is array is sorted : ");

                for(int i=0;i<size-1;i++){
                    int flag = 0;
                    for(int j=0;j<size-1;j++){
                        if(arr[j]>arr[j+1]){
                            flag = 1;
                        }
                    }

                    if(flag ==0 && (i==0)){
                            printf("Array is Sorted\n");
                            if(linearSearch(arr,size,key)){
                                    printf("%d is present in array\n",key);
                            }else{
                                     printf("%d is present in array\n",key);
                                 }
                            break;
                    }else{
                        printf("Array is not sorted we can't use binary search\n");
                        break;
                    }
                }
                break;
            case 3:
                    printf("Choose Correct Option\n");
                    break;
    }

}
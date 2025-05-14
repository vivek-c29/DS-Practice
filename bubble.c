#include<stdio.h>
#include<conio.h>

void inputArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("Enter array element : \n");
        scanf("%d",&arr[i]);
    }
}

void displayArray(int *arr,int n){
    printf("Array is : \n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[50],n;
    printf("Enter array size : \n");
    scanf("%d",&n);
    inputArray(arr,n);
    displayArray(arr,n);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }

    printf("Sorted Array is : \n");
    displayArray(arr,n);
    return 0;
}
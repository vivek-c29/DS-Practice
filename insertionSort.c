#include <stdio.h>

void inputArray(int *a, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Enter array element : \n");
        scanf("%d", &a[i]);
    }
}

void displayArray(int *a, int n)
{

    printf("Array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void insertion(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i]; //Track curreent element
        int prev = i-1; //Previous element i.e end of sorted part
        while(prev>=0 && arr[prev]>curr){ // If prev > curr move one element ahead (1 4 5)=> 1 4 4
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr; //Place curr at its appropriate place
    }
}

int main()
{

    int arr[50];
    int n;
    printf("Enter array size : \n");
    scanf("%d", &n);
    inputArray(arr, n);
    displayArray(arr, n);
    insertion(arr,n);
    displayArray(arr, n);

    return 0;
}
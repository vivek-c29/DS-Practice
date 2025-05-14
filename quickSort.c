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

int partition(int arr[], int start, int end)
{

    int i = start;
    int j = end;
    int pivot = arr[start];

    while (i < j)
    {
        while (arr[i] <= pivot && i < end) // Increment i while a[i]<=pivot
        {
            i++;
        }
        while (arr[j] > pivot) // decrement j
        {
            j--;
        }
        if (i < j) // Swap elements if i < j
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap pivot with a[j] to place it at the correct position
    int temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partitionIdx = partition(arr, start, end);
        quickSort(arr, start, partitionIdx - 1); //Sort left part
        quickSort(arr, partitionIdx + 1, end);  //Sort Right Part
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

    int res = partition(arr, 0, n - 1);
    printf("%d\n", res);
    quickSort(arr,0,n-1);
    printf("Sorted Array is : \n");
    displayArray(arr,n);
    return 0;
}
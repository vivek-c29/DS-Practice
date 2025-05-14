#include <stdio.h>
#include <conio.h>

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

int main()
{
    int n;
    printf("Enter array size : \n");
    scanf("%d", &n);
    int arr[50];
    inputArray(arr, n);
    displayArray(arr, n);
    int smallest, idx;

    for (int i = 0; i < n - 1; i++)
    {
        smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
                // printf("%d\t",smallest);
            }
        }
        if (i != smallest) //Not compulpsry of this if!!
        {
            int temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
    }
    printf("Sorted Array: \n");
    displayArray(arr, n);
    return 0;
}
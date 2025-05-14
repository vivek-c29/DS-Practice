#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            return binarySearch(arr, low, mid - 1, target);
        }
        else
        {
            return binarySearch(arr, mid + 1, high, target);
        }
    }

    return -1;
}

int main()
{

    int arr[50], n;
    printf("Enter size of array : \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element : \n");
        scanf("%d", &arr[i]);
    }
    printf("Array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    int target;
    printf("\nEnter element to be searched : \n");
    scanf("%d", &target);
    int res = binarySearch(arr,0,n-1,target);
    printf("Element found at %d\n",res);
    return 0;
}
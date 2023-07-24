#include <stdio.h>
int binarySearch(int arr[], int size, int value)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }

        if (arr[mid] > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {112, 80, 60, 97, 22, 34, 102, 58, 48, 136, 92};
    int size = sizeof(arr) / sizeof(int);
    int value;
    scanf("%d", &value);
    // printf("%d",size);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    if (binarySearch(arr, size, value) == -1)
    {
        printf("\nThe value is not in the array\n");
    }
    else
    {
        printf("\n%d is in the index of %d\n", value, binarySearch(arr, size, value));
    }
}
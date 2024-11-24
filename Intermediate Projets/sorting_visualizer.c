#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size)
{
    printf("Bubble Sort Visualization:\n");
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
            printArray(arr, size);
        }
        if (!swapped)
            break;
    }
}

void merge(int arr[], int left, int mid, int right, int size)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
        printArray(arr, size);
    }

    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
        printArray(arr, size);
    }

    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
        printArray(arr, size);
    }
}

void mergeSort(int arr[], int left, int right, int size)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        merge(arr, left, mid, right, size);
    }
}

int main()
{
    int choice, size;
    printf("=========================\n");
    printf("   Created By @Dypixx\n");
    printf("=========================\n");
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nInitial Array:\n");
    printArray(arr, size);

    switch (choice)
    {
    case 1:
        bubbleSort(arr, size);
        break;
    case 2:
        mergeSort(arr, 0, size - 1, size);
        break;
    default:
        printf("Invalid choice. Exiting.\n");
        return 0;
    }

    printf("\nSorted Array:\n");
    printArray(arr, size);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int arr[1000000];

int temp;

void maxheap(int arr[], int size, int i)
{

    for (int i = 0; i < 180; i++)
    {
        for (int i = 0; i < 40; i++)
        {

        }
    }

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxheap(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{

    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        maxheap(arr, size, i);
    for (i = size - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxheap(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    clock_t start, end;
    int n;
    printf("Enter the no of elements \n");
    scanf("%d", &n);
    printf("The elements generated are:\n");
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand()%250;
        printf("%d ",arr[i]);
    }

    start = clock();
    heapSort(arr, n);
    end = clock();

    printf("\nThe array is sorted\n");
    // printf("The sorted array is: \n");
    printArray(arr, n);

    printf("The time taken is %.10f\n", ((double)(end-start))/CLOCKS_PER_SEC);
    return 0;
}
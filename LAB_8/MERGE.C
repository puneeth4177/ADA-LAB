#include<stdio.h>
#include <stdlib.h>
#include<time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
         int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d  ", A[i]);
    printf("\n");
}


int main(){
  int last,arr[8000];
  clock_t end,start;
printf("Enter the Size of array  :");
scanf("%d",&last);
srand(time(NULL));
for(int i=0;i<last;i++){
  arr[i]=rand()%1000;
  printf("%d  ",arr[i]);
}printf("\n");
start=clock();

mergeSort(arr, 0, last - 1);

end=clock();
 printf("\nSorted array is \n");
    printArray(arr, last);
	printf("Time in sec %f\n",(((double)(end-start))/CLOCKS_PER_SEC));

	return 0;
}
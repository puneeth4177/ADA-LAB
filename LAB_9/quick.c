#include <stdio.h>
#include<time.h>
#include<stdlib.h> 

void swap(int *a, int *b)
 {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) 
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
     quickSort(array, pi + 1, high);
  }
}

int main() {
  int a[150000],n;
   clock_t start,end;
  printf("Input the Size of array  \n");
scanf("%d",&n);
printf("\n");
srand(time(NULL));

for(int i=0;i<n;i++){
  a[i]=rand()%100000;
  printf("%d ",a[i]);
}
  
   printf("\n");
   printf("\n");

  
 start=clock();
  
  quickSort(a, 0, n - 1);
  end=clock();
  printf("\nSorted array is: \n");
		for(int i=0;i<n;i++)
		printf("%d ",a[i]);

  printf("\n");
printf("\nTime taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));

}
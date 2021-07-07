#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
  int last,arr[50000];
  clock_t end,start;

printf("Input the Size of array  \n");
scanf("%d",&last);

srand(time(NULL));

for(int i=0;i<last;i++){
  arr[i]=rand()%1000;
  printf("%d ",arr[i]);
}
printf("\n");

start=clock();
for(int i=1;i<=last-1;i++){
  int temp=arr[i];
  int j=i-1;
  while (j >= 0 && arr[j] > temp) {
              arr[j + 1] = arr[j];
              j = j - 1;
          }
          arr[j + 1] = temp;
}
end=clock();

for(int i=0;i<last;i++){
  printf("%d ",arr[i]);
}
printf("\n Time in sec %f\n",(((double)(end-start))/CLOCKS_PER_SEC));
}
#include <stdio.h>
#include <time.h>
int search(int a[], int x,int i) {
    if(a[i]==x)
        return i;
    else
        return search(a,x,i+1);
}
int main() {
    int a[10],size;
    clock_t start,end;
     double cc;
     printf("Enter size of array\n");
     scanf("%d",&size);
    printf("Enter elements\n");
    for(int i=0;i<size;i++) {
        scanf("%d",&a[i]);
    }
     
    int x;
    printf("enter element to search\n");
    scanf("%d",&x);
    start=clock();
    int i=search(a,x,0);
     end=clock();
   printf("Element at index:%d \n",i);
    cc=((double)end-start);
  printf("The number of clock cycles taken = %f \n",cc);
  printf("The total time taken = %f \n",(cc/CLOCKS_PER_SEC));
}
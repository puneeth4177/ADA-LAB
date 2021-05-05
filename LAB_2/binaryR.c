#include <stdio.h>
#include <time.h>
int bsearch(int a[], int x,int i) {
    if(a[i]<x)
        return bsearch(a,x,i+(i/2));
    else if(a[i]>x)
        return bsearch(a,x,i/2);
    else 
        return i;
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
    int i=bsearch(a,x,5);
    end=clock();
    printf("Element at index:%d\n",i);
     cc=((double)end-start);
  printf("The number of clock cycles taken = %f \n",cc);
  printf("The total time taken = %f \n",(cc/CLOCKS_PER_SEC));
}
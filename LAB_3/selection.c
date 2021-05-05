#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARSIZE 50000
int main() {
    int a[ARSIZE];
    double cc;
    clock_t start,end;
    

    for(int i=0;i<ARSIZE;i++)
        a[i]=rand();

   
    
    int s=0,min;
    start=clock();
    for(int i=0;i<ARSIZE;i++) {
        min=32767;
        for(int j=i;j<ARSIZE;j++) {
            if(a[j]<=min) {
                min=a[j];
                s=j;
            }
            else
                continue;
        }
        int temp=a[i];
        a[i]=min;
        a[s]=temp;
    }
    end=clock();
   
     cc=((double)end-start);
  printf("The number of clock cycles taken = %f \n",cc);
  printf("The total time taken = %f \n",(cc/CLOCKS_PER_SEC));
}
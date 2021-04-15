#include<stdio.h>
#include<math.h>
int gcd(int m,int n)
{
    if (n==0)return m;
    if (m<n)return gcd(n,m);
    return gcd (n,m%n);

}
void main()
{
      int m,n,res;
       printf("enter the value of m  \n");
      scanf("%d",&m);
      printf("enter the value of n \n");
      scanf("%d",&n);
      res=gcd(m,n);
	printf("gcd of %d and %d = %d",m,n,res);
    

}

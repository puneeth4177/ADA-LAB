#include<stdio.h>
#include<math.h>
int gcd(int m,int n)
{
    int q, r;
    while (n > 0)
    {
        q = m / n;     
        r = m - q * n;    
        m = n;
        n = r;
    }
    return m;
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

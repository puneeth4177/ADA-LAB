#include <stdio.h>
 
void towers(int, char, char, char);
 
int main()
{
    int num;
 
    printf("Enter the number of disks : \n");
    scanf("%d", &num);
    printf("The sequence of steps involved are :\n");
    towers(num, 'A', 'B', 'C');
    return 0;
}
void towers(int num, char source, char dest, char middle)
{
    if (num == 1)
    {
        printf(" Move disk 1 from  %c to  %c\n", source, dest);
        return;
    }
    towers(num - 1, source, middle, dest);
    printf(" Move disk %d from  %c to  %c\n", num, source, dest);
    towers(num - 1, middle, dest, source);
}
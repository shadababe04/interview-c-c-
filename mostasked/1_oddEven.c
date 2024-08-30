#include<stdio.h>
#include<stdbool.h>
//Brut approch

bool oddeven(int num)
{
    return num%2==0;
}
int main()
{   
    int num = 5;
    // printf("%d",oddeven(3)); // for test
    if(oddeven(num))
    {
        printf("Num: %d is Even", num);
    }
    else
    {
        printf("Num: %d is odd", num);
    }
    return 0;
}
#include<stdio.h>
// Swap two number without using third variable
void swap(int *a, int *b)
{
    // *a = *a + *b;
    // *b = *a - *b;
    // *a = *a - *b;
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
}
int main()
{
    int x=6, y =7;
    printf("Before x:%d y:%d\n",x,y);
    swap(&x, &y);
    printf("After x:%d y:%d",x,y);
    return 0;
}
#include <stdio.h>

int main()
{
    int a,b;
    int *ptr;

    ptr = &a;   // assign address of a to pointer ptr
    *ptr = 1234;   // assign 1234 to the value of a
    ptr = &b;  // assign address of b to pointer ptr
    *ptr = 4567;  // assign 4567 to the value of b

    printf("A is %d and B is %d\n",a,b); // A is 1234 and B is 4567

    return(0);
}

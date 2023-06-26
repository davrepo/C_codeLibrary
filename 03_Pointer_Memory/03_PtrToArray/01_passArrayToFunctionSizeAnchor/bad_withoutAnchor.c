#include <stdio.h>
#include <stdlib.h>

/* Example without Size Anchor - Mistake*/

int SumOfELement(int A[]) { // same as int *A
    // when an array is passed to a function, it is treated as a pointer. 
    // The pointer only holds the address of the first element of the array, 
    // and does not retain the original array size information.
    int sum = 0;
    int size = sizeof(A)/sizeof(A[0]); // A[0] is same as *(A+0) = *A
    printf("SOE - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0])); 
    // SOE - Size of A = 8, size of A[0] = 4
    // 8 (size of a pointer), 4 (size of an integer type)

    for (int i=0; i<size; i++) {
        sum += A[i]; // A[i] is same as *(A+i) = *(i+A) = i[A]
    }
    return sum;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int total = SumOfELement(A); // can also pass &A[0], same effect
    // 3 !!! WRONG !!!
    printf("Total = %d\n", total);
    printf("Main - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0])); // 20, 4
    // Main - Size of A = 20, size of A[0] = 4

    return 0;
}
#include <stdio.h>

int main()
{
	int array[] = { 5, 13, 17, 19 };
	int *ptr; // pointer to an integer
    int (*ptr_to_array)[4]; // pointer to an array of 4 integers

	ptr = array;		// no & needed for array because the array name is the address of the first element
    ptr = &array[0];	// same as above

    ptr = &array[2];	// ptr points to the third element
    
    ptr = array;
    ptr = ptr + 2;		// ptr points to the third element

	printf("The element is %d\n", *(ptr + 1)); // ptr is increased by 1 integer sized chuck, then dereferenced
    // The element is 19

    /* Pointer to an array */
    ptr_to_array = &array; // &array is the address of the entire array, not the first element
    printf("entire array: %d %d %d %d\n", (*ptr_to_array)[0], (*ptr_to_array)[1], (*ptr_to_array)[2], (*ptr_to_array)[3]);
    // entire array: 5 13 17 19
	return(0);
}


#include <stdio.h>

int main()
{
	int array[] = { 11, 13, 17, 19 };
	int x;
	int *ptr;

	ptr = array; // no & needed for array because the array name is the address of the first element

	for(x=0;x<4;x++)
	{
		printf("Element %d: %d\n",x+1,*ptr); // dereference the pointer to get the value
		ptr++; // increment the pointer to the next element
	}

	return(0);
}

// Element 1: 11
// Element 2: 13
// Element 3: 17
// Element 4: 19
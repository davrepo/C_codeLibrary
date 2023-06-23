#include <stdio.h>

int main()
{
	/* Example 1*/
	int array[] = { 11, 13, 17, 19 };
	int x, *ptr;

	ptr = array; // no & needed for array because the array name is the address of the first element

	for(x=0;x<4;x++) {
		printf("Element %d: %d\n",x+1,*ptr); // dereference the pointer to get the value
		ptr++; // increment the pointer to the next element
	}
	// Element 1: 11
	// Element 2: 13
	// Element 3: 17
	// Element 4: 19

	/* Example 2*/
	int a[3] = { 11, 22, 33 };
	int x, *p;

	for( x=0; x<3; x++ ) printf("%p " ,&a[x]);
	// 000000000061FE04 000000000061FE08 000000000061FE0C

	p = a;
	for( x=0; x<3; x++ ) printf("%p ", p++);
	// 000000000061FE04 000000000061FE08 000000000061FE0C

	return(0);
}


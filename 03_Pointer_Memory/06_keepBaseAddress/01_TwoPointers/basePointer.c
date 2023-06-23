#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base, *p ,x; // base is the base address of the memory allocated

	base = (int *)malloc( sizeof(int) * 10 );
	if( base==NULL ) {
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* retain the base */
	p = base; // p is assigned the value stored in base
	/* fill storage */
	for( x=0; x<10; x++ ) {
		*p = x * 100;
		p++; // p can be manipulated without losing the base address
	}
	puts("Memory allocated and filled");

	/* output the buffer's contents */
	p = base; // p is reassigned to the address stored in base
	for( x=0; x<10; x++ ) {
		printf("%d\n",*p);
		p++; // p can be manipulated without losing the base address
	}

	return(0);
}


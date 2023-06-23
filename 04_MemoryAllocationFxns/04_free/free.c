#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int x;

	storage = (int *)malloc( sizeof(int) * 5);
	if( storage==NULL ) {
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");
	// the pointer is allocated, but the storage locations haven't been initialized
	for( x=0; x<5; x++ ) printf("%d\n",*(storage+x) ); // garbage values

	// release the allocated memory
	free(storage);
    // After calling free(storage), the memory previously pointed to by storage has been deallocated, 
    // meaning it can now be reused by the system for other purposes. 
    // However, the storage pointer itself still holds the address of that memory, 
    // even though it's no longer valid to access it (dangling pointer), hence assign it to NULL.
	storage = NULL;
	puts("Memory freed");
	/* it's unnecessary to free() storage before
	   a program quits, but if you plan on re-
	   using the pointer, or it's allocated within
	   a function, do free it and assign the
	   pointer to the NULL symbolic constant,
	   as shown here */

	return(0);
}

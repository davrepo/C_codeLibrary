#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base, x;
	FILE *fp;

	/* allocate storage */
	base = (int *)malloc( sizeof(int) * 10 );
	if( base==NULL ) {
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* fill storage */
	for( x=0; x<10; x++ ) {
		*(base+x) = x * 100;
	}
	puts("Memory allocated and filled");

	/* open the file */
	fp = fopen("integers.dat","w");
	if( fp==NULL ) {
		fprintf(stderr,"Unable to create file\n");
		exit(1);
	}

	/* save the buffer */
	// NB! do NOT use sizeof(base) instead of sizeof(int)
	// b/c we want to write integers, not the size of the pointer
	// sizeof(int) is 4 bytes, sizeof(base) is 8 bytes as it is size of a pointer
	fwrite(base,sizeof(int),10,fp); // 10 is the number of elements to write
	puts("Data saved");

	fclose(fp);
	return(0);
}


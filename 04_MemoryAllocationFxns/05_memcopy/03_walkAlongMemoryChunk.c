#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char name[8]; // 8 bytes
		int age; // 4 bytes
	} man = { "Paul", 64 };
	void *buffer; // void pointer can point to any data type
	int *bufint;
	char *bufchar;

	/* allocate the void buffer */
	buffer = malloc( sizeof(struct person) );
	if( buffer==NULL ) {
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	memcpy(buffer, &man, sizeof(struct person));
	
	/* initialize the data type pointers */
	bufchar = (char *)buffer;
	bufint = (int *)(buffer+8); // skips 8 bytes of memory

	printf("%s is %d years old\n", bufchar, *bufint);

	return(0);
}

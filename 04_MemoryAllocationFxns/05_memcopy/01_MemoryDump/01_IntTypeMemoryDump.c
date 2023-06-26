#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int a = 65284;
	unsigned char *buffer;

	buffer = (unsigned char *)malloc( sizeof(int) );
	if( buffer==NULL ){
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	memcpy(buffer, &a, sizeof(int)); 
	
	/* dump the buffer 1 byte at a time */
	puts("Buffer dump:");
	for( int x=0; x<(int)sizeof(int); x++ ) {
		printf(" %02X", *(buffer+x)); // *(buffer+x) is the same as buffer[x]
	}

	return(0);
}

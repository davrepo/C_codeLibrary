#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this program memory dumps a struct using memcpy
int main() {
	struct person {
		char name[6];
		int age;
	} man = { "Paul", 42 };
	unsigned char *buffer;

	/* allocate the unsigned char buffer */
	buffer = (unsigned char *)malloc( sizeof(struct person) );
	if( buffer==NULL ){
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* copy memory */
    // &man is pointer to 'man' struct, 
    // which points to 1st byte of the memory location 'man' struct is stored in
	memcpy(buffer, &man, sizeof(struct person)); 
	
	/* dump the buffer 1 byte at a time */
	puts("Buffer dump:");
    // (int)sizeof(struct person) is 12 b/c of padding, so 6 + 2(pad) + 4 = 12
	for( int x=0; x<(int)sizeof(struct person); x++ ) {
        // %02X is a format specifier for hexadecimal numbers
		printf(" %02X", *(buffer+x)); // *(buffer+x) is the same as buffer[x]
	}

    // Buffer dump:
    // 50 61 75 6C 00 00 00 00 2A 00 00 00
    // 2A = 42 in hex

	return(0);
}

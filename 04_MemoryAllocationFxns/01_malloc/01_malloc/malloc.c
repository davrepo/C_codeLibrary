#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024 // 1024 chars = 1kb

int main()
{
	/* Example 1 */
	char *sto;

	sto = malloc(sizeof(char)*SIZE);
	if( sto == NULL) { // if sto is NULL, then malloc failed to allocate memory
		puts("Memory error");
		return(1);
	} else {
		printf("%d bytes of memory allocated at %p\n", SIZE, sto);
		// 1024 bytes of memory allocated at 0000000000AC5DA0
	}

	/* Example 2 */
	int *scores, x;

	scores = malloc(sizeof(int)*3);
	if( scores == NULL) {
		puts("Unable to allocate memory");
		return(1);
	}

	*(scores+0) = 10; // go to memory location at score points to, and store 10
	*(scores+1) = 20;
	*(scores+2) = 30;

	for(x=0; x<3; x++) printf("Score %d: %d\n", x+1, *(scores+x));
	// Score 1: 10
	// Score 2: 20
	// Score 3: 30

	/* Example 3*/
	char *name;

	name = malloc(sizeof(char)*64); // name is a memory buffer of 64 bytes
	if (name == NULL) {
		puts("Unable to allocate memory");
		return(1);
	}
	printf("Enter your name: ");
	fgets(name, 64, stdin);
	printf("You entered: %s\n", name);
    // Enter your name: Walter White
    // You entered: Walter White

	return(0);
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct person {
		char *name;
		int *age;
	} my; // this is how you declare a variable of type struct person
	char n[] = "Jennifer";

	// allocate storage for the age integer
	// age is a pointer, malloc() returns a pointer
	my.age = (int *)malloc( sizeof(int) * 1);
	if( my.age==NULL ) {
		fprintf(stderr,"Allocation error\n");
		exit(1);
	}
	// assign value; * is required to reference the content of the address
	*my.age = 26;

	// name is a char pointer, n is decaying to a pointer, so no * is required
	my.name = n;

	// %s reads from a pointer until it finds a null (\0) character, so no * is required
	// %d reads from an integer, so * is required to reference the content of the address
	printf("%s is %d years old\n", my.name, *my.age);

	return(0);
}
